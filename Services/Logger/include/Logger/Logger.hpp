#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include "Logger/Core.hpp"

#define INIT_LOGGER \
  Server::Logger::Core& caramba_logger = Server::Logger::Core::get();\
  std::string caramba_meassge_log;

#define LOG_DEBUG_MESSAGE( TEXT ) \
{ \
  caramba_meassge_log = TEXT; \
  caramba_logger.printDebugMessage(Server::Logger::Message(caramba_meassge_log, Logger::DEBUG)); \
}
#define LOG_MESSAGE( TEXT ) \
{ \
  caramba_meassge_log = TEXT; \
  caramba_logger.addNoteInLog(caramba_meassge_log); \
}

#endif
