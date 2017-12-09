#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include "Logger/Core/Core.hpp"

using namespace Service;

static Logger::Core logger;

#define LOG_MESSAGE( TEXT ) logger.addNoteInLogOld(TEXT)

#endif
