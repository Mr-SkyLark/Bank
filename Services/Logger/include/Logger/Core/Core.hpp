#ifndef LOGGER_CORE_CORE_HPP
#define LOGGER_CORE_CORE_HPP
//==============================================================================
#include "Message.hpp"
// std
#include <string>
#include <map>
#include <queue>
#include <mutex>
#include <condition_variable>
//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
class Core
{
public:
  Core();
  ~Core();

  /*!
   * \brief printProcess
   */
  void printProcess();

  /*!
   * \brief addNoteInLog
   * \param message
   */
  void addNoteInLog(const Message& message);

  /*!
   * \brief addNoteInLogOld
   * \param message
   */
  void addNoteInLogOld(const Message& message);

private:
  bool mDoneFlag;
  /*!
   * \brief mMessageList - Контейнер сообщений
   */
  std::queue<std::string> mMessageList;
  /*!
   * \brief printMutex
   */
  std::mutex mPrintMutex;
  /*!
   * \brief printMutex
   */
  std::mutex mQueueMutex;
  /*!
   * \brief mLoggerConditionVariable
   */
  std::condition_variable mLoggerConditionVariable;
};
//==============================================================================
}} // !Service !Log
//==============================================================================
#endif // !_TERRITORY_LOGGER_H_
