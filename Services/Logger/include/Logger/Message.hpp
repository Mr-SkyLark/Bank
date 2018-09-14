#ifndef LOGGER_CORE_MESSAGE_HPP_
#define LOGGER_CORE_MESSAGE_HPP_
//==============================================================================
class BString;
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
class Message
{
public:

  enum Level
  {
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN = 999
  };

  virtual ~Message(){}

  virtual void generateString() const = 0;

  virtual Level getLevel() const = 0;

  virtual void append(const BString &info) = 0;

protected:


};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
