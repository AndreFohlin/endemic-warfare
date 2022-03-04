pragma once
#include "State.h"

class MenuState
{
public:

  virtual ~MenuState(){}

  //this will execute when the state is entered
  virtual void Enter(entity_type*)=0;

  //this is the states normal update function
  virtual void Update(entity_type*)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void Exit(entity_type*)=0;
};