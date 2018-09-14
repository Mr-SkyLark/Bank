#ifndef LOGGER_CONCRETE_DECORATOR_HPP_
#define LOGGER_CONCRETE_DECORATOR_HPP_
//==============================================================================
// Logger
#include "Decorator.hpp"
// std
#include <memory>
//==============================================================================
namespace Server{
namespace Logger{
//==============================================================================
class TypeDecorator: public Decorator
{
public:
  TypeDecorator(Message* message);
  ~TypeDecorator(){}

  virtual void generateString() const override;
  virtual Level getLevel() const override;

private:
  TypeDecorator(){}
  TypeDecorator(const TypeDecorator&){}
  const TypeDecorator operator=(const TypeDecorator&){}

private:
  std::shared_ptr<Message> mMessage;

};
//==============================================================================
}} // !Service !Core
//==============================================================================
#endif
