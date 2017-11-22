#ifndef _TERRITORY_LOGGER_H_
#define _TERRITORY_LOGGER_H_
//==============================================================================
// std
#include <string>
//==============================================================================
namespace Service
{
//==============================================================================

//==============================================================================
class Logger
{
public:
  enum MessageLevel
  {
    INFO = 0,
    WARNING,
    ERROR
  };

  Logger(const std::string& text);
  virtual ~Logger(){}

  void addNoteInLog(const std::string &text, MessageLevel lvl = INFO);

protected:
};
} // !Territory
//==============================================================================
#endif // !_TERRITORY_LOGGER_H_
