#ifndef LOGGER_CORE_CORE_HPP
#define LOGGER_CORE_CORE_HPP
//==============================================================================
#include "Message.hpp"
// std
#include <string>
#include <map>
//==============================================================================
namespace Service{
namespace Log {
//==============================================================================
class Logger
{
public:
  Logger();
  virtual ~Logger(){}

  /*!
   * \brief addNoteInLog
   * \param text
   * \param lvl
   */
  void addNoteInLog(const std::string &text, MessageLevel lvl = INFO);

private:
  /*!
   * \brief mMessageList - Контейнер сообщений
   */
  std::map<int, std::string> mMessageList;
};
//==============================================================================
}} // !Service !Log
//==============================================================================
#endif // !_TERRITORY_LOGGER_H_
