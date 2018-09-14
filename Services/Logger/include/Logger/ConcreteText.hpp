#ifndef LOGGER_CONCRETE_TEXT_HPP_
#define LOGGER_CONCRETE_TEXT_HPP_
//==============================================================================
#include "Message.hpp"
#include <BString.hpp>
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
class ConcreteText: public Message
{
public:
  ConcreteText();
  virtual void generateString() const override;

  virtual Level getLevel() const override;

  virtual void append(const BString& info) override;

private:
  BString mMessage;
  BString mPrefix;
  Level mLevel;
};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
