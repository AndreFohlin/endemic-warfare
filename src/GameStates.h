#pragma once
#include "State.h"
#include "Game.h"



class MenuState : public State<Game>
{
private:
  
  MenuState(){}
  
  //copy ctor and assignment should be private
  MenuState(const MenuState&);
  MenuState& operator=(const MenuState&);

public:

  static MenuState* Instance();
  
public:
  
  virtual void Enter(Game* game);

  virtual void Update(Game* game);

  virtual void Render(Game* game);

  virtual void Exit(Game* game);

};

class PlayState : public State<Game>
{
private:
  
  PlayState(){}
  
  //copy ctor and assignment should be private
  PlayState(const PlayState&);
  PlayState& operator=(const PlayState&);

public:

  static PlayState* Instance();
  
public:
  
  virtual void Enter(Game* game);

  virtual void Update(Game* game);

  virtual void Render(Game* game);

  virtual void Exit(Game* game);
};


class ScoreState : public State<Game>
{
private:
  
  ScoreState(){}
  
  //copy ctor and assignment should be private
  ScoreState(const ScoreState&);
  ScoreState& operator=(const ScoreState&);

public:

  static ScoreState* Instance();
  
public:
  
  virtual void Enter(Game* game);

  virtual void Update(Game* game);

  virtual void Render(Game* game);

  virtual void Exit(Game* game);

};