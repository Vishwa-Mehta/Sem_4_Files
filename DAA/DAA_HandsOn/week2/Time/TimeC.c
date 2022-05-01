#include "TimeH.h"

int main() {
  struct timespec start;
  struct timespec end;
  clock_gettime(CLOCK_REALTIME, &start);
  long long int s = long_loop();
  clock_gettime(CLOCK_REALTIME, &end);
  printf("time %lf \n", time_elapsed(start, end));
  printf("s : %lld\n", s);
  return 0;
}
