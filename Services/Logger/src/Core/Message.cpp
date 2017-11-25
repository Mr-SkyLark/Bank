#include "Logger/Core/Message.hpp"
// std
#include <string.h>
//==============================================================================
namespace Service{
namespace Log {
//==============================================================================
Message::Message(const std::string& message,
        MessageLevel level, time_t date)
  : mLevel(level)
  , mDate(date)
  , mMessage(message)
{

}

void Message::generateString(std::string& text)
{
  text.clear();
  text.append(mMessage);
}
//==============================================================================
}} // !Service !Log
