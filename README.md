# Timuino

### Why

To have a non-blocking function call executed based on FPS.

### How

1. Include Timer.h : `#include <Timer.h>`
2. Create a timer with the callback of choice : `Timer timer = Timer(enterframe, 60);`
3. in the loop function, call on `timer.tick()`

Your _enterframe_ function will be called every 60fps top.