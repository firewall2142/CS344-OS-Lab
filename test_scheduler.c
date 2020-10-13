#include "types.h"
#include "user.h"



int
main(int argc, char *argv[])
{
  int numforks = 10;
  double workmult = 1e4;
  int work = 100;
  

  if(argc >= 2)
    numforks = atoi(argv[1]);
  
  if(argc >= 3)
    work = atoi(argv[2]);
  

  int id = 0;
  int burstitr = numforks + 2;
  double dummy=0; // variable to waste cpu time


  for(int itr=0; itr < numforks; itr++){
    id = fork();
    if(id < 0) {
      printf(2, "fork failed! (returned %d)\n", id);
    } else if(id == 0){
      // child process
      // do some work
      printf(1, "Setting burst time = %d\n", burstitr);
      printf(1, "c");
      set_burst_time(burstitr);


      dummy = 0;
      while(dummy/work < workmult){
        dummy += 2.731423 * 0.459045;
      }
      break;

    } else {
      burstitr--;
      // parent

      //printf(1, "Waiting for child %d to finish\n", id);

      // wait for the child to finish
      // wait();
    }
  }

  // wait for the children to finish
  while(wait() != -1);


  printf(1, "finished: burst = %d\n", get_burst_time());
  exit();

}
