#include "Timer.h"

Timer::Timer(void (* c)(), byte f, bool a)
{
  this->_callback = c;
  this->fps = f;

  this->_active = a;
  this->_dump = millis();
}

bool Timer::active() {
  return this->_active;
}

void Timer::play() {
  if (this->_active == true) {
    return;
  }

  this->_active = true;
  this->_dump = millis();
}

void Timer::pause() {
  if (this->_active == false) {
    return;
  }

  this->_active = false;
}

void Timer::toggle() {
  this->_active ? this->pause() : this->play();
}

void Timer::tick() {
  if (this->_active == false) {
    return;
  }

  unsigned int frame = 1000 / this->fps;

  uint32_t now = millis();
  uint32_t delta = now - this->_dump;

  int16_t slice = frame - delta;

  if (slice <= 0) {
    if (this->_callback != NULL) {
      this->_callback();
    }

    this->_dump = now + slice;
  }
}
