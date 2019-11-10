#include "Arduino.h"
#define FRICTION 1

class Particle
{
  public:
    void Spawn(int position);
    void Tick(int USE_GRAVITY);
    void Kill();
    bool Alive();
    int _position;
    int _power;
  private:
    int _life;
    int _alive;
    int _speed;
};

void Particle::Spawn(int position){
    _position = position;
    _speed = random(-200, 200);
    _power = 255;
    _alive = 1;
    _life = 220 - abs(_speed);
}

void Particle::Tick(int USE_GRAVITY){
    if(_alive){
        _life ++;
        if(_speed > 0){
            _speed -= _life/10;
        }else{
            _speed += _life/10;
        }
        if(USE_GRAVITY && _position > 500) _speed -= 10;
        _power = 100 - _life;
        if(_power <= 0){
            Kill();
        }else{
            _position += _speed/7.0;
            if(_position > 1000){
                _position = 1000;
                _speed = 0-(_speed/2);
            }
            else if(_position < 0){
                _position = 0;
                _speed = 0-(_speed/2);
            }
        }
    }
}

bool Particle::Alive(){
    return _alive;
}

void Particle::Kill(){
    _alive = 0;
}
