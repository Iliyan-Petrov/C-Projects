#include <stdio.h>
#include <ucontext.h>
#include <malloc.h>
#include <stdlib.h>

#define FIBER_STACK 1024*64
ucontext_t uctx_main;

void plus(); void minus(); void exclaim();
struct tcb_t{ucontext_t context; void (*func)(); struct tcb_t *next;};
struct tcb_t *first = NULL, *last = NULL, *Running;

void plus(){while(1){printf("+ \n");swapcontext(&(Running->context),&uctx_main);}}
void minus(){while(1){printf("- \n");swapcontext(&(Running->context),&uctx_main);}}
void exclaim(){while(1){printf("! \n");swapcontext(&(Running->context),&uctx_main);}}

int create_task (void (*func)()) {
struct tcb_t *p;
getcontext(&(p->context));
(p->context).uc_link = NULL;
(p->context).uc_stack.ss_sp = malloc(FIBER_STACK);
(p->context).uc_stack.ss_size = FIBER_STACK;
(p->context).uc_stack.ss_flags = 0;
makecontext(&(p->context),(*func),0);
p = last;

last = malloc(sizeof(struct tcb_t));
(last->context) = (p->context);
(last->func) = (*func);
(last->next) = NULL;

if(p!=NULL){p->next = last;}
if(first == NULL){first = last;}
return 0;}

int main() {
create_task(plus);
create_task(minus);
create_task(exclaim);
while(1){Running = first; swapcontext(&uctx_main,&(Running->context));}
return 0;}