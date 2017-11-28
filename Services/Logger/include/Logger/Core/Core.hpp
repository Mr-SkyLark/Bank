#ifndef LOGGER_CORE_CORE_HPP
#define LOGGER_CORE_CORE_HPP
//==============================================================================
#include "Message.hpp"
// std
#include <string>
#include <map>
#include <mutex>
//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
class Core
{
public:
  Core();
  ~Core(){}

  /*!
   * \brief addNoteInLog
   * \param text
   * \param lvl
   */
  void addNoteInLog(const Message& message);

private:
  /*!
   * \brief mMessageList - Контейнер сообщений
   */
  std::map<int, std::string> mMessageList;
  std::mutex g_lock;
};
//==============================================================================
}} // !Service !Log
//==============================================================================
#endif // !_TERRITORY_LOGGER_H_
