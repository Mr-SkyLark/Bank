#include "Logger/Core/Message.hpp"
// std
#include <string>
#include <sstream>
#include <thread>
//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
Message::Message(const std::string& message,
        MessageLevel level, time_t date)
  : mLevel(level)
  , mDate(date)
  , mMessage(message)
{

}

void Message::generateString(std::string& text) const
{
  text.clear();
  tm *ltm = localtime(&mDate);
  std::stringstream data;
  data << 1900 + ltm->tm_year << "/"
       << 1 + ltm->tm_mon << "/"
       << ltm->tm_mday << " "
       << 1 + ltm->tm_hour << ":"
       << 1 + ltm->tm_min << ":"
       << 1 + ltm->tm_sec << "\t";

  switch (mLevel) {
  case INFO:
    data << "[INF] - ";
    break;
  case WARNING:
    data << "[WAR] - ";
    break;
  case ERROR:
    data << "[ERR] - ";
    break;
  default:
    data << "[UNK] - ";
    break;
  }

  data << std::this_thread::get_id() << " - "
       << mMessage << "\n";

  text = data.str();
}
//==============================================================================
}} // !Service !Log
