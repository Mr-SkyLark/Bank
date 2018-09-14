// Logger
#include "Logger/Logger.hpp"
// std
#include <string>
#include <thread>
#include <time.h>
#include <vector>
#include <iostream>
#include <io.h>
#include <fcntl.h>
//==============================================================================
int main(int argc, char* argv[])
{
  Server::Logger::Core& caramba_logger = Server::Logger::Core::get();
  caramba_logger.addNoteInLog("start");
  return 0;
}
//==============================================================================
