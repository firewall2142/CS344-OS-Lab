#include "types.h"
#include "user.h"

int main(void){
  printf("setting burst time to 2");
  set_burst_time(2);
  printf("New burst time = ", get_burst_time());
  exit();
}
