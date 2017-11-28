#include "Logger/Core/Core.hpp"
#include "json.hpp"
// std
#include <iostream>

//==============================================================================
namespace Service{
namespace Logger {
//==============================================================================
Core::Core()
{

}
//==============================================================================
void Core::addNoteInLog(const Message &message)
{
  std::string text;
  message.generateString(text);
  g_lock.lock();
  std::cout << text;
  g_lock.unlock();
}
//==============================================================================
}} // !Service !Log
