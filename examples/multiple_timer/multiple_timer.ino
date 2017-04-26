#include <Timer.h>

double q = 0;
double w = 0;
double e = 0;
double r = 0;

void inc_q() { q += 1.0 ; }
void inc_w() { w += 0.5 ; }
void inc_e() { e += 0.1 ; }
void inc_r() { r += 0.01 ; }

Timer t1 = Timer(inc_q, 1, true);
Timer t2 = Timer(inc_w, 2, true);
Timer t3 = Timer(inc_e, 10, true);
Timer t4 = Timer(inc_r, 100, true);

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  if (q > 3) {
    return;
  }
  
  t1.tick();
  t2.tick();
  t3.tick();
  t4.tick();

  Serial.print(q);
  Serial.print("\t");
  Serial.print(w);
  Serial.print("\t");
  Serial.print(e);
  Serial.print("\t");
  Serial.print(r);
  Serial.println();
}
