#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int hours = 0;
int minutes = 0;
int seconds = 0;

int main()
{
while(1)
 {
 seconds++;
 printf("%d hours | %d minutes | %d seconds \n",hours,minutes,seconds);
 sleep (1);
 if(seconds == 60)
  {
  minutes++;
    if(minutes == 60)
    {
    hours++;
    minutes = 0;
    }
    seconds = 0;
  }
 }
 return 0;
}