// Logger
#include "Logger/Logger.hpp"
// std
#include <string>
#include <thread>
//==============================================================================

void test()
{
  for( int counter = 0; counter < 1000; ++counter)
  {
    std::string text = "counter = ";
    text.append(std::to_string(counter)).append(";\n");
    LOG_MESSAGE(text);
  }
}

int main(int argc, char** argv)
{
  std::thread thr1(test);
  std::thread thr2(test);
  std::thread thr3(test);
  std::thread thr4(test);
  std::thread thr5(test);
  thr1.join();
  thr2.join();
  thr3.join();
  thr4.join();
  thr5.join();

  return 0;
}
//==============================================================================
