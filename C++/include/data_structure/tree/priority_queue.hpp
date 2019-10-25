//priority queue
```cpp

#include<stdio.h>
#include<stdlib.h>

struct pqueue
{
  int info,priority;
  struct pqueue *next;
};
typedef struct pqueue pq;
pq *start;

void insert(int,int);
void delete();
void display();

void main()
{
  int ch,ele,priority;
  while(1)
  {
    printf("\n1. insert\n2. delete\n3. display\n4. exit");
    printf("\nenter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nenter an element and its priority : ");
             scanf("%d%d",&ele,&priority);
             insert(ele,priority);
             break;
      case 2:delete(); break;
      case 3:display(); break;
      case 4:printf("\nbye bye");
             exit(1);
      default:printf("\ninvalid choice");
    }
  }
}

void insert(int ele,int priority)
{
  pq *temp,*t;
  temp=(pq *)malloc(sizeof(pq));
  temp->info=ele;
  temp->priority=priority;
  temp->next=NULL;
  if (start==NULL)
    start=temp;
  else if(start->priority>priority)
  {
    temp->next=start;
    start=temp;
  }
  else
  {
    t=start;
    while(t->next!=NULL && (t->next)->priority<=priority)
    {
      t=t->next;
    }
    temp->next=t->next;
    t->next=temp;
  }
}

void delete()
{
  pq *temp=start;
  if(start!=NULL)
  {
    printf("\n%d is removed",start->info);
    start=start->next;
    free(temp);
  }
  else
  {
    printf("\nqueue is empty");
  }
}

void display()
{
  pq *temp=start;
  printf("\ndisplay priority queue : \n");
  while(temp!=NULL)
  {
    printf("%d(%d)\t",temp->info,temp->priority);
    temp=temp->next;
  }
}

```
