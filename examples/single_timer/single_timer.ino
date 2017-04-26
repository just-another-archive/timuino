#include <Timer.h>

double q = 0;

void inc_q() { q += 1.0 ; }

Timer t1 = Timer(inc_q, 60, true);

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  if (q > 3) {
    return;
  }
  
  t1.tick();
  Serial.println(q);
}
