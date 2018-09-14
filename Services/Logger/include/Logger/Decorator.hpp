#ifndef LOGGER_DECORATOR_HPP_
#define LOGGER_DECORATOR_HPP_
//==============================================================================
#include "Message.hpp"
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
class Decorator: public Message
{
public:
  virtual ~Decorator(){}

  virtual void append(const BString &info) override{}
  virtual Message::Level getLevel() const override
  {
    return Message::UNKNOWN;
  }
};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
