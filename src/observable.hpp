#pragma once

#include <memory>
#include <vector>
#include "observer.hpp"

class Observer;

class Observable
{
public:
  virtual ~Observable() {}

  virtual void AddObserver(std::weak_ptr<Observer> const observer);
  virtual void RemoveObserver(std::weak_ptr<Observer> const observer);
  virtual void Notify() const;

private:
  std::vector<std::weak_ptr<Observer>> observers;
};
