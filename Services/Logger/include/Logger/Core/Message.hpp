#ifndef LOGGER_CORE_MESSAGE_HPP_
#define LOGGER_CORE_MESSAGE_HPP_
//==============================================================================
#include <string>
#include <ctime>
//==============================================================================
namespace Service{
namespace Log {
//==============================================================================
enum MessageLevel
{
  INFO = 0,
  WARNING,
  ERROR
};
//==============================================================================
class Message
{
public:
  Message(const std::string& message,
          MessageLevel messageLevel = INFO, time_t date = std::time(0));

  void generateString(std::string& text);

private:
  MessageLevel mLevel;
  time_t mDate;
  std::string mMessage;
};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
