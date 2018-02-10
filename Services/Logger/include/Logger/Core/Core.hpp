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

  void stopLogger();

  /*!
   * \brief addNoteInLog
   * \param message
   */
  void addNoteInLog(const Message& message);

  /*!
   * \brief addNoteInLogOld
   * \param message
   */
  void printDebugMessage(const Message& message);

  std::mutex& getDoneMutex() const;
  bool getDoneFlag() const;
  std::condition_variable& getDoneSignal() const;

private:
  /*!
   * \brief mDoneFlag
   */
  bool mDoneFlag;
  /*!
   * \brief mMessageList - Контейнер сообщений
   */
  std::queue<std::string> mMessageList;
  /*!
   * \brief mPrintMutex
   */
  mutable std::mutex mPrintMutex;
  /*!
   * \brief mQueueMutex
   */
  mutable std::mutex mQueueMutex;
  /*!
   * \brief mDoneMutex
   */
  mutable std::mutex mDoneMutex;
  /*!
   * \brief mPrintSignal
   */
  mutable std::condition_variable mPrintSignal;
  /*!
   * \brief mDoneSignal
   */
  mutable std::condition_variable mDoneSignal;
};
//==============================================================================
}} // !Service !Log
//==============================================================================
#endif // !_TERRITORY_LOGGER_H_
