#include<stdio.h>
#include<stdlib.h>

void insertbeg();
void disp();
void insertend();
void insertafter();
void delbeg();
void delend();
void delafter();

struct node
{
   struct node *next;
   struct node *prev;
   int val;
   
};
struct node *s=NULL;
int main()
{
    int ch=0;
    
   
   while (ch!=8)

   {
      printf("enter option for double LL \n 1.inser Beg \t 2.display \t 3.insertend \t 4.insertafter\n 5.delete Beg\t  6.delend \t delafter() 8.exit \n ");
      scanf("%d",&ch);
     switch (ch)
     {
      case 1: insertbeg();
        break;
      case 2: disp();
        break;
      case 3:insertend();
         break;
      case 4:insertafter();
         break;
      case 5:delbeg();
         break;
      case 6:delend();
         break;
      case 7:delafter();
      break;
      case 8: exit(0);
        break;
     
     default: printf("invalid option");
        
     }
   }
   return 0;
}

void insertbeg()
{
   struct node *n;
   n=(struct node*)malloc(sizeof(struct node));
   
   if(n==NULL)
   {
      printf("memory allocation problem \n");
      return ;
   }
   printf("enter value for insert\n");
   scanf("%d",&n->val);
  
   n->next=s;
   n->prev=NULL;
   s=n;
   printf("value inserted succesfully!!-------------\n\n ");
}

void disp()
{
  struct node *temp,*t1;
  temp=s;
  if (temp==NULL)
  {
   printf("list is empty \n");
   return ;
  }
  
  printf("display values as forword \n");

  while(temp!=NULL){
   printf("%d\t",temp->val);
   t1=temp;
   temp=temp->next;
   
  }
  printf("\n display value as backword direction \n ");
  while (t1!=NULL)
  {
   printf("%d\t",t1->val);
   t1=t1->prev;
  }  
}

void insertend()
{
   struct node *temp,*n ;

   n=(struct node*)malloc(sizeof(struct node));

   if(n==NULL)
   {
      printf("memory allocation problem \n");
      return;
   }

   printf("enter value for insert at end \n");
   scanf("%d",&n->val);

   n->next=NULL;

   if(s==NULL)
   {
      s=n;
      printf("value inserted at end successfully\n");
      return;
   }

   temp=s;

   while(temp->next!=NULL)
   {
      
      temp=temp->next;
   }

   temp->next=n;
   n->prev=temp;
   printf("value inserted at end successfully\n");
}

void insertafter()
{
   struct node *temp,*n;
   int no;
   temp=s;

   if(s==NULL)
   {
      printf("list  is empty \n ");
      return;
   }
   printf("inter val after which u want to insert \n ");
   scanf("%d",&no);
   
   while (temp!=NULL)
   {
      if(temp->val==no)
      {
         break;
      }
      temp=temp->next;
   }

   if(temp==NULL)
   {
      printf("enter value is not in list \n");
      return;
   }
   else{
      n=(struct node *)malloc(sizeof(struct node));
      if(n==NULL)
      {
         printf("memory allocation problem \n");
         return;
      }
      printf("enter value for inser \n ");
      scanf("%d",&n->val);
      n->next=temp->next;
      temp->next->prev=n;
      temp->next=n;
      n->prev=temp;

   }
   
}

void delbeg()
{
   struct node *temp;

   if(s==NULL)
   {
      printf("list is empty\n");
      return;
   }
   if(s->next==NULL)
   {
      temp=s;
      s=NULL;
      printf("deleted val is =%d",temp->val);
      free(temp);
      return;
      
   }
 temp=s;
 s=s->next;
 s->prev=NULL;
  printf("deleted val is =%d",temp->val);
 free(temp);  
}

void delend()
{
   struct node *temp;
   temp=s;

   if(s==NULL)
   {
      printf("list is empty\n");
      return;
   }

   if(s->next==NULL)
   {

      printf("deleted val is = %d",s->val); 
      free(temp);
      s=NULL;
      return;
   }
   while (temp->next!=NULL)
   {
   
      temp=temp->next;
   }
temp->prev->next=NULL;
   printf("deleted node is %d",temp->val);
   free(temp);  
}

void delafter()
{
   struct node *temp;
   int pos;

   if(s==NULL)
   {
      printf("list is empty\n");
      return;
   }

   printf("enter val after which u want to delete ");
   scanf("%d",&pos);

   temp=s;

   while(temp!=NULL)
   {
      if(pos==temp->val)
      {
         break;
      }

      temp=temp->next;
   }

   if(temp==NULL)
   {
      printf("value is not in list\n");
      return;
   }

   if(temp->next==NULL)
   {
      printf("no node exists after %d\n",pos);
      return;
   }

  
   temp->prev->next=temp->next;
   temp->next->prev=temp->prev;

   printf("deleted val is = %d\n",temp->val);

   free(temp);
}