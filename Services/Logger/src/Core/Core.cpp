#include "Logger/Core/Core.hpp"
#include "json.hpp"
// std
#include <iostream>
#include <thread>
#include <chrono>

void printProcessTo()
{}

//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
Core::Core()
  : mDoneFlag(false)
{
  std::thread printTread(&Core::printProcess, this);
  printTread.detach();
}
//==============================================================================
Core::~Core()
{
  mDoneFlag = true;
//  mPrintMutex.unlock();
//  mQueueMutex.unlock();
//  mDoneMutex.unlock();
  //mPrintSignal.notify_one();
}
//==============================================================================
void Core::printProcess()
{
  while(!mDoneFlag)
  {
    std::unique_lock<std::mutex> queueMutex(mQueueMutex);
    mPrintSignal.wait(queueMutex,
                      [&]()->bool{return (!mMessageList.empty() || mDoneFlag);});
    while(!mMessageList.empty())
    {
      {
        std::unique_lock<std::mutex> printMutex(mPrintMutex);
        std::cout << mMessageList.front();
      }
      {
        //std::unique_lock<std::mutex> queueMutex(mQueueMutex);
        mMessageList.pop();
      }
    }
  }
  std::unique_lock<std::mutex> doneLock(mDoneMutex);
  std::notify_all_at_thread_exit(mDoneSignal, std::move(doneLock));
}
//==============================================================================
void Core::stopLogger()
{
  mDoneFlag = true;
  mPrintSignal.notify_one();
}
//==============================================================================
void Core::addNoteInLog(const Message &message)
{
  std::string text;
  message.generateString(text);
  {
    std::unique_lock<std::mutex> queueMutex(mQueueMutex);
    mMessageList.push(text);
  }
  //mPrintSignal.notify_one();
}
//==============================================================================
void Core::printDebugMessage(const Message &message)
{
  std::string text;
  message.generateString(text);
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
