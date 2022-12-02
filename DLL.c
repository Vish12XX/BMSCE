#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next,*prev;};
struct node* insert_front(struct node *);
struct node* insert_rear(struct node *);
struct node* insert_pos(struct node* );
struct node* delete_rear(struct node *);
struct node* delete_front(struct node*);
struct node* delete_list(struct node*);
struct node* delete_val(struct node*);

void display(struct node *);

void main(){
struct node *start=NULL;
int ch=9;
do{
printf("\n*****MENU*****\n");    
printf("Insert-\n\t1.Front\n\t2.Rear\n\t3.At position\nDelete-\n\t4.Front\n\t5.Rear\n\t6.An element\n\t7.Full list\n\n8.Display\n9.Exit\n\nEnter choice: ");
scanf("%d",&ch);
switch(ch){
case 1: start = insert_front(start);
break;
case 2: start = insert_rear(start);
break;
case 3: start=insert_pos(start);
break;
case 4: start=delete_front(start);
break;
case 5: start=delete_rear(start);
break;
case 8: display(start);
break;
case 9: exit(0);
case 7: start=delete_list(start);
break;
case 6: start=delete_val(start);
break;
default: printf("\nInvalid choice...");
break;}}while(ch!=9);

}

struct node* insert_front(struct node *start){
struct node *new_node;
int num;
printf("\nEnter element: ");
scanf("%d",&num);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
new_node->prev=NULL;
if(start==NULL){
new_node->next=NULL;}
else{
new_node->next=start;
start->prev=new_node; }
start=new_node;
return start;}

void display(struct node *start){
struct node *temp=start;
if(start==NULL){
printf("\nEmpty list.....");}
else{
printf("\nElements are: ");
while(temp!=NULL){
printf("%d ->",temp->data);
temp=temp->next;}printf("NULL"); }}

struct node* insert_rear(struct node* start){
struct node *new_node,*temp=start;
int num;
printf("\nEnter element: ");
scanf("%d",&num);
new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=num;
new_node->next=NULL;
if(start==NULL){
new_node->prev=NULL;
start=new_node;}
else{
while(temp->next!=NULL){
temp=temp->next;}
new_node->prev=temp;
temp->next=new_node;}
return start;}

struct node* insert_pos(struct node* start){
    int pos,c=0;
    if(start==NULL){
      printf("\nCreating list....\n");
      start=insert_front(start);
      return start;}
    struct node *new_node,*temp=start;
    printf("\nEnter position to insert at: ");
    scanf("%d",&pos);
        while(temp!=NULL){
        temp=temp->next;
        c++;}
        if(pos==1){
            start=insert_front(start);
            return start;
        }
        else if(pos==c+1){
            start=insert_rear(start);
            return start;
        }
        else if(pos<c+1&&pos>0){
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter element: ");
            scanf("%d",&new_node->data);
            c=1;
            temp=start;
            while(c!=pos){
                temp=temp->next;
                c++;}
            temp = temp->prev;
            temp->next->prev=new_node;
            new_node->next=temp->next;
            temp->next=new_node;
            new_node->prev=temp;
            return start;
        }
        else printf("Invalid position.");
        }

struct node* delete_front(struct node *start){
if(start==NULL)
printf("\nEmpty list....");
else if(start->next==NULL){
free(start);
start=NULL;}
else{
start=start->next;
free(start->prev);
start->prev=NULL;}
return start;}

struct node* delete_rear(struct node *start){
if(start==NULL){
printf("\nEmpty list....");}
else if(start->next==NULL){
free(start);
start=NULL;}
else{
struct node *temp=start;
while(temp->next!=NULL){
temp=temp->next;}
temp=temp->prev;
free(temp->next);
temp->next=NULL;}
return start;}

struct node* delete_list(struct node *start){
if(start==NULL)
printf("\nEmpty list....");
else if(start->next==NULL){
free(start);
start=NULL;}
else{
while(start!=NULL){
start=start->next;
if(start==NULL)
return start;
else{
free(start->prev);
start->prev=NULL;}}}
return start;}

struct node* delete_val(struct node*start){
if(start==NULL)
printf("\nEmpty list....");
else if(start->next==NULL){
free(start);
start=NULL;
printf("\nList Deleted");}
else{
    struct node *temp=start;
    int val;
    printf("\nEnter element to be deleted: ");
    scanf("%d",&val);
    while(temp->data!=val&&temp->next!=NULL){
        temp=temp->next;}
    if(temp->data==val&&temp->prev!=NULL&&temp->next!=NULL){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;}
    else if(temp->data==val&&temp->prev==NULL)
    start=delete_front(start);
    else if(temp->data==val&&temp->next==NULL)
    start=delete_rear(start);
    else printf("\nElement not found...");
}return start;}
