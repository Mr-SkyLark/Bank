#ifndef LOGGER_CORE_MESSAGE_HPP_
#define LOGGER_CORE_MESSAGE_HPP_
//==============================================================================
#include <string>
#include <ctime>
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
enum MessageLevel
{
  DEBUG = 0,
  INFO,
  WARNING,
  ERROR
};
//==============================================================================
class Message
{
public:
  Message(const std::string& message,
          MessageLevel messageLevel = INFO, time_t date = std::time(0));

  void generateString(std::string& text) const;

private:
  MessageLevel mLevel;
  time_t mDate;
  std::string mMessage;
};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
