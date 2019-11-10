#include "Arduino.h"

class Boss
{
  public:
    void Spawn();
    void Hit();
    void Kill();
    bool Alive();
    int _position;
    int _lives;
    int _ticks;
  private:
    bool _alive;
};

void Boss::Spawn(){
    _position = 800;
    _lives = 3;
    _alive = 1;
}

void Boss::Hit(){
    _lives --;
    if(_lives == 0) {
        Kill();
        return;
    }
    if(_lives == 2){
        _position = 200;
    }else if(_lives == 1){
        _position = 600;
    }
}

bool Boss::Alive(){
    return _alive;
}

void Boss::Kill(){
    _alive = 0;
}
