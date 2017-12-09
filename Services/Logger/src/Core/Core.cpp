#include "Logger/Core/Core.hpp"
#include "json.hpp"
// std
#include <iostream>
#include <thread>

//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
Core::Core()
  : mDoneFlag(false)
{
  std::thread printProcessThread(printProcess);
  printProcessThread
}
//==============================================================================
Core::~Core()
{

}
//==============================================================================
void Core::printProcess()
{
  while(!mDoneFlag)
  {
    std::unique_lock<std::mutex> queueMutex(mQueueMutex);
    mLoggerConditionVariable.wait(queueMutex,
                                  [&](){return !mMessageList.empty();});
    // если есть ошибки в очереди, обрабатывать их
    while(!mMessageList.empty())
    {
      std::unique_lock<std::mutex> printMutex(mPrintMutex);
      std::cout << mMessageList.front();
      mMessageList.pop();
    }
  }
}
//==============================================================================
void Core::addNoteInLog(const Message &message)
{
  std::string text;
  message.generateString(text);
  std::unique_lock<std::mutex> queueMutex(mQueueMutex);
  mMessageList.push(text);
  mLoggerConditionVariable.notify_one();
}
//==============================================================================
void Core::addNoteInLogOld(const Message &message)
{
  std::string text;
  message.generateString(text);
  mPrintMutex.lock();
  std::cout << text;
  mPrintMutex.unlock();
}
//==============================================================================
}} // !Service !Log
