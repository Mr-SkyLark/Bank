#include "Logger/Core/Message.hpp"
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
//==============================================================================
}} // !Service !Log
