#include "Logger/Message.hpp"
// std
#include <string>
#include <sstream>
#include <thread>
#include <time.h>
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================

//void Message::generateString(std::string& text) const
//{
//  text.clear();
//  tm ltm;
//  //localtime_r(&mDate, &ltm);
//  std::stringstream data(std::stringstream::in | std::stringstream::out);
//  //text.append(mMessage).append("\n");
//  data << 1900 + ltm.tm_year << "/"
//       << 1 + ltm.tm_mon << "/"
//       << ltm.tm_mday << " "
//       << 1 + ltm.tm_hour << ":"
//       << 1 + ltm.tm_min << ":"
//       << 1 + ltm.tm_sec << "\t";
//  switch (mLevel) {
//  case DEBUG:
//    data << "[DBG] - ";
//    break;
//  case INFO:
//    data << "[INF] - ";
//    break;
//  case WARNING:
//    data << "[WAR] - ";
//    break;
//  case ERROR:
//    data << "[ERR] - ";
//    break;
//  default:
//    data << "[UNK] - ";
//    break;
//  }

//  data << std::this_thread::get_id() << " - "
//       << mMessage << "\n";

//  text = data.str();
//}
//==============================================================================
}} // !Service !Log
