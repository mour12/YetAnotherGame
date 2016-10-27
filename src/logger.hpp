#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

class Logger
{
public:
//  template <typename T>
//  Logger & operator<<(T const &t)
//  {
//    time_t currTime = time(0);
//    std::cout << time(&currTime) << " : " << t;
//    return *this;
//  }
  template <typename T>
  void log(std::ostream & os, T const &t)
  {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    os << std::put_time(std::localtime(&now_c), "%c") << " : " << t << std::endl;
  }
  template<typename T, template<typename, typename...> class C, typename... Args>
  void log (std::ostream & os, C<T, Args...> const & objs)
  {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    os << std::put_time(std::localtime(&now_c), "%c") << " : ";
    for (auto const & obj : objs)
      os << obj << "; ";
    os << std::endl;
  }
  static Logger & getInstance()
  {
    static Logger instance;
    return instance;
  }

private:
  Logger() {}
  ~Logger() {}
  Logger(Logger const&) = delete;
  Logger& operator= (Logger const&) = delete;
};
