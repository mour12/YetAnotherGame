#include <algorithm>
#include "observable.hpp"

void Observable::AddObserver(std::weak_ptr <Observer> const observer)
{
  if (std::find_if(observers.begin(), observers.end(), [&observer](std::weak_ptr<Observer> const o) {return o.lock() == observer.lock();}) == observers.end())
  {
    observers.push_back(observer);
  }
}

void Observable::RemoveObserver(std::weak_ptr<Observer> const observer)
{
  observers.erase(std::find_if(observers.begin(), observers.end(), [&observer](std::weak_ptr<Observer> const o) {return o.lock() == observer.lock();}));
}

void Observable::Notify() const
{
  for (auto observer : observers)
  {
    if (observer.lock() != nullptr)
    {
      observer.lock()->OnNotified(this);
    }
  }
}

