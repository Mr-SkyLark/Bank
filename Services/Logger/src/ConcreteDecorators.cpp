#include "ConcreteDecorators.hpp"
#include "BString.hpp"
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
TypeDecorator::TypeDecorator(Message* message)
  : mMessage(message)
{

}
//==============================================================================
void TypeDecorator::generateString() const
{
  BString typeString= "[UNK]";
  switch (mMessage->getLevel()) {
    case DEBUG:
      typeString = "[DBG]";
      break;
    case INFO:
      typeString = "[INF]";
      break;
    case WARNING:
      typeString = "[WAR]";
      break;
    case ERROR:
      typeString = "[ERR]";
      break;
  }
  mMessage->append(typeString);
}
//==============================================================================
Message::Level TypeDecorator::getLevel() const
{
  return mMessage->getLevel();
}
//==============================================================================
}} // !Service !Log
