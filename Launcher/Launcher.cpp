// Logger
#include "Logger/Logger.hpp"
// std
#include <string>
#include <thread>
#include <time.h>
#include <vector>
//==============================================================================

//static std::mutex printMutex;

void test(double& diff)
{
  std::vector<double> result;
  for( int counter = 0; counter < 10000; ++counter)
  {
    result.push_back(clock());

    std::string text = "counter = ";
    text.append(std::to_string(counter));
    LOG_MESSAGE(text);
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

  double res = 0;
//  for(double tRes : timerResult)
//     res += tRes;
//  res = res / static_cast<double>(CLOCKS_PER_SEC);

  std::string message;
  message.append("Timer: ")
      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
      .append(" - thread timer: ")
      .append("0");

  LOG_MESSAGE(message);


  return 0;
}
//==============================================================================
