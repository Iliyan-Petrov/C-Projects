#include <stdio.h>

#include <stdlib.h>

#include <unistd.h
>
#include <signal.h>



volatile sig_atomic_t stop;



void handle_sigint 
{
   stop = 1;
}



int main() 
{
  int br=0;
  
  signal(SIGINT, handle_sigint);
  
while(1)
  {
  br++;
  printf("Time passed: %ds \n", br);
  sleep(1);
  }
  return 0;
}
