#pragma once

#include "observable.hpp"

class Observable;

class Observer
{
public:
  virtual ~Observer() {}

  virtual void OnNotified(Observable const * obj) = 0;
};