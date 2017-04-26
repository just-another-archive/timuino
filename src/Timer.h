#ifndef timuino
  #define timuino

  #ifndef FPS
    #define FPS 100
  #endif

  #include <Arduino.h>

  class Timer {
    public:
      Timer(void (* callback)() = NULL, byte fps = FPS, bool active = false);

      byte fps;

      void tick();
      bool active();

      void play();
      void pause();
      void toggle();

    private:
      bool _active = false;

      void (* _callback)();
      uint32_t _dump;
  };

#endif
