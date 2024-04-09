#include <stdio.h>

#include <stdlib.h>

#define SIZE 100

void enqueue();

void dequeue();

void show();


int arr[SIZE];

int Rear = -1;

int Front = -1;


int main()
{ 
   
int ch;
   
while(1)
   
{  
         
  printf("1.Enqueue Operation \n");

  printf("2.Dequeue Operation \n");
         
  printf("3.Display the Queue \n");
         
  printf("4.Exit \n");
         
  printf("Enter your choice of operations: ");
         
  scanf("%d", &ch);
         
    switch(ch)
          
         {
            
            case 1: 
             
            enqueue();
             
            break;
            
             
            case 2:
             
            dequeue();
             
            break;
            
           
           case 3:
             
           show();
             
           break;
            
         
           case 4:
             
           exit(0);
             
           break;
            
          
           default:
             
           printf("Incorrect choice \n");
          
         }
      
  }

return 0;
  
}



void enqueue()

{
 
     int insert_item;
  
       if(Rear == SIZE - 1)
    
          {printf("Overflow \n");}
  
       else
   
          {
if(Front == - 1)
      Front = 0;
      printf("Element to be inserted: \n");
      scanf("%d", &insert_item);
      Rear = Rear + 1;
      
           arr[Rear] = insert_item;
} 

}




void dequeue()

{
 int index = -1;
 int delete_item;
  
  if(Front == -1 || Front > Rear)
  
    {
printf("Underflow \n");
   return;
}
  
  else 
    {
       
printf("Element to be deleted: \n");
   
       scanf("%d", &delete_item);
   
   
    for (int i = Front; i<= Rear;i++)
    
      {
        if(arr[i] == delete_item)
{index = i; break;}
    
      }
   
    if(index != -1)
    
    {
for(int i=index;i< SIZE - 1; i++){arr[i] = arr[i+1];}
      Rear = Rear - 1;
}
   
  else {printf("Element Not Found \n");} 
  
   }

}



void show()
{
   
if (Front == -1)
    
   printf("Empty Queue \n");
 

   else
{

   printf("Queue: \n");
    
   for(int i = Front; i <= Rear; i++)
printf("%d ", arr[i]);
    printf("\n");
  
       }

}
