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
namespace Server{
namespace Logger{
//==============================================================================
class Core;  // опережающее объявление
//==============================================================================
class CoreSingletonDestroyer
{
public:
  ~CoreSingletonDestroyer();
  void init( Core* core );
private:
  Core* mCore;
};
//==============================================================================
class Core
{
public:
  static Core& get();

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

protected:
  Core();
  Core( const Core& );
  Core& operator=( Core& );
  ~Core();
  friend class CoreSingletonDestroyer;

private:  
  static Core* mCore;
  static CoreSingletonDestroyer destroyer;
  /*!
   * \brief mDoneFlag
   */
  bool mDoneFlag;
  bool mFinishHim;
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
