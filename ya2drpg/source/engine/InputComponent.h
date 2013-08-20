#pragma once
#include "GameObject.h"

class InputComponent
{
public:
  virtual void update(GameObject& gameObject) = 0;
};