// Logger
#include "Logger/Logger.hpp"
// std
#include <string>
#include <thread>
#include <time.h>
#include <vector>
#include <iostream>
//==============================================================================
#define THREAD_COUNT 5
#define TEST_COUNT 10
//==============================================================================
//void testOld(double& diff)
//{
//  std::vector<double> result;
//  for( int counter = 0; counter < TEST_COUNT; ++counter)
//  {
//    result.push_back(clock());

//    std::string text = "counter = ";
//    text.append(std::to_string(counter));
//    DEBUG_PRINT(text);
//  }
//  diff = clock() - result.front();
//}

//void test(double& diff)
//{
//  std::vector<double> result;
//  for( int counter = 0; counter < TEST_COUNT; ++counter)
//  {
//    result.push_back(clock());

//    std::string text = "counter = ";
//    text.append(std::to_string(counter));
//    LOG_MESSAGE(text);
//  }
//  diff = clock() - result.front();
//}

//void test_empty(double& diff)
//{
//  std::vector<double> result;
//  for( int counter = 0; counter < TEST_COUNT; ++counter)
//  {
//    result.push_back(clock());
//  }
//  diff = clock() - result.front();
//}

//int main(int argc, char** argv)
//{
//  // Создаем таймеры
//  double time2;
//  double time1;
//  // Создаем вектор результатов и вектор потоков
//  std::vector<double> timerResult;
//  std::vector<std::string> textResult;
//  std::vector<std::thread> threadVector;
//  std::string message;

//  for(int i = 0; i < THREAD_COUNT; ++i)
//  {
//    timerResult.push_back(0);
//  }

//  //Запускаем первый тест
//  time1 = clock();
//  for(int i = 0; i < THREAD_COUNT; ++i)
//  {
//    threadVector.push_back(std::thread(testOld, std::ref(timerResult[i])));
//  }
//  for(std::thread& t : threadVector)
//    t.join();
//  // Заканчиваем первый тест
//  time2 = clock();

//  // Строим сообщение на вывод
//  message.append("Timer: ")
//      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
//      .append(" - thread timer: ")
//      .append(std::to_string([&]() -> double {
//           double res = 0;
//           for(double tRes : timerResult)
//              res += tRes;
//           return res / (double)CLOCKS_PER_SEC;
//       } () ));
//  textResult.push_back(message);

//  // Очистка данных
//  threadVector.clear();
//  message.clear();

//  // Запускаем тест второй
//  time1 = clock();
//  for(int i = 0; i < THREAD_COUNT; ++i)
//  {
//    threadVector.push_back(std::thread(test, std::ref(timerResult[i])));
//  }
//  for(std::thread& t : threadVector)
//    t.join();
//  // Заканчиваем тест второй
//  time2 = clock();

//  message.append("Timer: ")
//      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
//      .append(" - thread timer: ")
//      .append(std::to_string([&]() -> double {
//           double res = 0;
//           for(double tRes : timerResult)
//              res += tRes;
//           return res / (double)CLOCKS_PER_SEC;
//       } () ));
//  textResult.push_back(message);

//  // Очистка данных
//  threadVector.clear();
//  message.clear();

//  // Запускаем тест третий
//  time1 = clock();
//  for(int i = 0; i < THREAD_COUNT; ++i)
//  {
//    threadVector.push_back(std::thread(test_empty, std::ref(timerResult[i])));
//  }
//  for(std::thread& t : threadVector)
//    t.join();
//  // Заканчиваем тест третий
//  time2 = clock();

//  message.append("Timer: ")
//      .append(std::to_string((time2 - time1) / (double)CLOCKS_PER_SEC))
//      .append(" - thread timer: ")
//      .append(std::to_string([&]() -> double {
//           double res = 0;
//           for(double tRes : timerResult)
//              res += tRes;
//           return res / (double)CLOCKS_PER_SEC;
//       } () ));
//  textResult.push_back(message);

//  for(std::string &text: textResult)
//    DEBUG_PRINT(text);

////  std::this_thread::sleep_for (std::chrono::seconds(5));
//  {
//    std::unique_lock<std::mutex> loggerLock(logger.getDoneMutex());
//    logger.stopLogger();
//    while(!logger.getDoneFlag()) // против ложных пробуждений
//      logger.getDoneSignal().wait(loggerLock);
//    loggerLock.unlock();
//  }

//  DEBUG_PRINT("FINISH!");
//  return 0;
//}


class A
{
public:
  A() : a_(0) {
    std::cout << "A-Constructor\n";
  }
  A(int a) : a_(a) {
    std::cout << "A-Constructor2\n";
  }
  A(const A& a) : a_(a.a_) {
    std::cout << "A-Copy\n";
  }
  ~A(){
    std::cout << "~A\n";
  }

  void print() {
    std::cout << "A: " << a_ << "| ";
  }
  void inc() {
    ++a_;
  }

  int f1() const { std::cout << "A1\n"; return 0; }
  int f2() const { std::cout << "A2\n"; return 0; }
  int f3() const { std::cout << "A3\n"; return 0; }

private:
  int a_;
};

class B
{
public:
  B() : b_(0) {
    std::cout << "B-Constructor\n";
  }
  B(int b) : b_(b) {
    std::cout << "B-Constructor2\n";
  }
  B(const B& b) : b_(b.b_) {
    std::cout << "B-Copy\n";
    //throw("B failed");
  }
  ~B(){
    std::cout << "~B\n";
  }

  void print(){
    std::cout << "B: " << b_ << "| ";
  }
  void inc() {
    ++b_;
  }

  virtual int f1() const { std::cout << "B1"; return 0; }
  virtual int f2() const { std::cout << "B2"; return 0; }
  virtual int f3() const { std::cout << "B3"; return 0; }

private:
  int b_;
};

class Foo
{
public:
  Foo(A* a, B* b) : a_(a), b_(b){
    std::cout<< "Foo-Constructor\n";
  }

  ~Foo()
  {
    delete a_;
    delete b_;
    std::cout<< "~Foo\n";
  }

  Foo(const Foo& other)// : a_(new A(*other.a_)), b_(new B(*other.b_))
  {
    std::cout<< "Foo-Copy\n";

    // Do throwable work.
    std::shared_ptr<A> nA(other.a_ == NULL ? NULL : new A(*other.a_));
    std::shared_ptr<B> nB(other.b_ == NULL ? NULL : new B(*other.b_));

    a_ = nA.get();
    b_ = nB.get();

  }

  void print()
  {
    std::cout<< "Foo-Print: ";
    a_->print();
    b_->print();
    std::cout<< "\n";
  }

  void inc()
  {
    a_->inc();
    b_->inc();
  }

private:
  A *a_;
  B *b_;
};

//class B : public A
//{
//public:
//  B() : b(f1()) { f1(); }
//  virtual ~B() { f3(); }

//  virtual int f1() const { std::cout << "B1"; return 0; }
//  virtual int f2() const { std::cout << "B2"; return 0; }
//  virtual int f3() const { std::cout << "B3"; return 0; }

//private:
//  int b;
//};

int main(int argc, char* argv[])
{
  A* a = new A(3);
  B* b = new B(4);

  Foo foo(a,b);
  try
  {
    Foo copyFoo(foo);
    foo.inc();
    foo.print();
    copyFoo.print();
  }
  catch(...)
  {
    return 0;
  }


  return 0;
}
//==============================================================================
