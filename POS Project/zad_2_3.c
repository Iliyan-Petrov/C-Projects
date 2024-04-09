#include <malloc.h>

#include <ucontext.h>

#include <stdio.h>


#define FIBER_STACK 1024*64



ucontext_t uctx_func1, uctx_func2, uctx_func3, uctx_main;




void fiber1 ()
{
  
printf("Fiber1: started \n");
  
printf("Fiber1: Now swap context to Fiber2 \n");
  
swapcontext(&uctx_func1, &uctx_func2);
  
printf("Fiber1: returned \n");
  
printf("Fiber1: Now swap context to Fiber2 \n");
  
swapcontext(&uctx_func1, &uctx_func2);

}




void fiber2 ()
{
 
printf("Fiber2: started \n");
 
printf("Fiber2: Now swap context to Fiber3 \n");
 
swapcontext(&uctx_func2, &uctx_func3);
 
printf("Fiber2: returned \n");
 
printf("Fiber2: Now swap context to Fiber3 \n");
 
swapcontext(&uctx_func2, &uctx_func3);

}



void fiber3 ()
{

printf("Fiber3: started \n");
 
printf("Fiber3: Now swap context to Fiber1 \n");
 
swapcontext(&uctx_func3, &uctx_func1);
 
printf("Fiber3: returned \n");
 
printf("Fiber3: Now swap context to Main \n");
 
swapcontext(&uctx_func3, &uctx_main);

}



int main ()
{

getcontext (&uctx_func1);
 
uctx_func1.uc_link = NULL;
 
uctx_func1.uc_stack.ss_sp = malloc(FIBER_STACK);
 
uctx_func1.uc_stack.ss_size = FIBER_STACK;
 
uctx_func1.uc_stack.ss_flags = 0;
 
makecontext(&uctx_func1, fiber1, 0);



getcontext (&uctx_func2);
 
uctx_func2.uc_link = NULL;
 
uctx_func2.uc_stack.ss_sp = malloc(FIBER_STACK);
 
uctx_func2.uc_stack.ss_size = FIBER_STACK;
 
uctx_func2.uc_stack.ss_flags = 0;
 
makecontext(&uctx_func2, fiber2, 0);

 

getcontext (&uctx_func3);
 
uctx_func3.uc_link = NULL;
 
uctx_func3.uc_stack.ss_sp = malloc(FIBER_STACK);
 
uctx_func3.uc_stack.ss_size = FIBER_STACK;
 
uctx_func3.uc_stack.ss_flags = 0;
 
makecontext(&uctx_func3, fiber3, 0);


 

 
swapcontext(&uctx_main, &uctx_func1);
 
 
printf("Main: returned \n");
 
printf("Main: exiting \n");

 
return 0;

}
