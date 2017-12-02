// Logger
#include "Logger/Logger.hpp"
// std
#include <string>
#include <thread>
#include <time.h>
#include <vector>
//==============================================================================



void test(double& diff)
{
  std::vector<double> result;
  for( int counter = 0; counter < 3; ++counter)
  {
    result.push_back(clock());

    std::string text = "counter = ";
    text.append(std::to_string(counter));
    LOG_MESSAGE(text);
  }
  diff = clock() - result.front();

}

void test_empty(double& diff)
{
  std::vector<double> result;
  for( int counter = 0; counter < 100000; ++counter)
  {
    result.push_back(clock());
  }
  diff = clock() - result.front();
}

int main(int argc, char** argv)
{
  double time2;
  double time1;
  std::vector<double> timerResult;
  std::vector<std::thread> threadVector;

  time1 = clock();
  for(int i = 0; i < 5; ++i)
  {
    timerResult.push_back(0);
    threadVector.push_back(std::thread(test, std::ref(timerResult[i])));
  }
  for(std::thread& t : threadVector)
    t.join();
  time2 = clock();

  std::string message;
  message.append("Timer: ")
      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
      .append(" - thread timer: ")
      .append(std::to_string([&]() -> double {
           double res = 0;
           for(double tRes : timerResult)
              res += tRes;
           return res / (double)CLOCKS_PER_SEC;
       } () ));
  LOG_MESSAGE(message);

  timerResult.clear();
  threadVector.clear();
  message.clear();

  time1 = clock();
  for(int i = 0; i < 5; ++i)
  {
    timerResult.push_back(0);
    threadVector.push_back(std::thread(test_empty, std::ref(timerResult[i])));
  }
  for(std::thread& t : threadVector)
    t.join();
  time2 = clock();

  message.append("Timer: ")
      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
      .append(" - thread timer: ")
      .append(std::to_string([&]() -> double {
           double res = 0;
           for(double tRes : timerResult)
              res += tRes;
           return res / (double)CLOCKS_PER_SEC;
       } () ));
  LOG_MESSAGE(message);

  return 0;
}
//==============================================================================