#include "Logger/Core.hpp"
#include "Logger/ConcreteText.hpp"
#include "Logger/ConcreteDecorators.hpp"
// std
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================  
Core * Core::mCore = 0;
CoreSingletonDestroyer Core::destroyer;
//==============================================================================
CoreSingletonDestroyer::~CoreSingletonDestroyer()
{
  delete mCore;
}
//==============================================================================
void CoreSingletonDestroyer::init( Core* core )
{
  mCore = core;
}
//==============================================================================
Core::Core()
  : mDoneFlag(false)
  , mFinishHim(false)
{
  std::thread printTread(&Core::printProcess, this);
  printTread.detach();
}
//==============================================================================
Core::~Core()
{
  std::cout << " --- log distructor1\n";
  mFinishHim = true;
  std::unique_lock<std::mutex> lock(mDoneMutex);
  while(!mDoneFlag) // против ложных пробуждений
    mDoneSignal.wait(lock);
  std::cout << " --- log distructor2\n";
}
//==============================================================================
Core& Core::get()
{
  if(!mCore)
  {
    mCore = new Core();
    destroyer.init( mCore);
  }
  return *mCore;
}
//==============================================================================
void Core::printProcess()
{
  std::queue<std::string> tempQueue;
  while(true)
  {
    {
      std::unique_lock<std::mutex> queueMutex(mQueueMutex);
      mPrintSignal.wait(queueMutex,
                        [&](){return ( (mMessageList.size() > 100 &&
                                      tempQueue.empty() ) ||
                                      mFinishHim);} );
      tempQueue.swap(mMessageList);
    }
    std::unique_lock<std::mutex> printMutex(mPrintMutex);
    std::ofstream logFile;
    logFile.open ("Log.txt", std::ios::out | std::ios::app);
    if(logFile.is_open())
    {
      while(!tempQueue.empty())
      {
        logFile << tempQueue.front();
        tempQueue.pop();
      }
      logFile.close();
    }
    else
    {
      while(!tempQueue.empty())
      {
        std::cout << tempQueue.front();
        tempQueue.pop();
      }
    }
    if(mFinishHim == true)
      break;
  }
  std::unique_lock<std::mutex> doneLock(mDoneMutex);
  mDoneFlag = true;
  std::notify_all_at_thread_exit(mDoneSignal, std::move(doneLock));
}
//==============================================================================
void Core::stopLogger()
{
  mDoneFlag = true;
  mPrintSignal.notify_one();
}
//==============================================================================
void Core::addNoteInLog(const char* message)
{
  BString text(message);
  addNoteInLog(text);
}
//==============================================================================
void Core::addNoteInLog(const BString& message)
{
  std::shared_ptr<Message> testMessage(new TypeDecorator(new ConcreteText()));
  testMessage->generateString();
  std::string text;
//  message.generateString(text);
  std::unique_lock<std::mutex> queueMutex(mQueueMutex);
  mMessageList.push(text);
  mPrintSignal.notify_one();
}
//==============================================================================
void Core::printDebugMessage(const Message &message)
{
  std::string text;
//  message.generateString(text);
  mPrintMutex.lock();
  std::cout << text;
  mPrintMutex.unlock();
}
//==============================================================================
std::mutex& Core::getDoneMutex() const
{
  return mDoneMutex;
}
//==============================================================================
bool Core::getDoneFlag() const
{
  return mDoneFlag;
}
//==============================================================================
std::condition_variable& Core::getDoneSignal() const
{
  return mDoneSignal;
}
//==============================================================================
}} // !Service !Log
