#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include "Logger/Core/Core.hpp"

using namespace Service;

static Logger::Core logger;

#define DEBUG_PRINT( TEXT ) \
logger.printDebugMessage(Logger::Message(TEXT, Logger::DEBUG));
#define LOG_MESSAGE( TEXT ) logger.addNoteInLog(TEXT);

#endif
