#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_front(){
    int num;
    printf("Enter number:");
    scanf("%d",&num);
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
}
void insert_after(){
    struct node *new_node,*temp=start;
    int num,pos;
    if(start==NULL)
    printf("\nEmpty list");
    else{
        printf("\nEnter number after which to insert: ");
        scanf("%d",&pos);
        printf("\nEnter number to insert: ");
        scanf("%d",&num);
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        while(temp->data!=pos && temp->next!=NULL)
        {
            temp=temp->next;
            }
            if(temp->data==pos&&temp->next!=NULL)
            {
                new_node->next=temp->next;
                temp->next=new_node;
                }
            else if(temp->data==pos&&temp->next==NULL)
            {   new_node->next=NULL;
                temp->next=new_node;
                }
            else
            printf("\nNode not found");
    }
}
void insert_rear(){
     int num;
    printf("Enter number:");
    scanf("%d",&num);
    struct node *new_node,*curr;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    if(start==NULL)
    start=new_node;
    else{
        curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            }
            curr->next=new_node;
         }
}
void delete_front(){
    if(start==NULL)
    printf("\nEmpty List");
    else
    {
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
    }
}
void delete_rear(){
    if(start==NULL)
    printf("\nEmpty List");
    else if(start->next==NULL)
    start=NULL;
    else
    {
    struct node *temp;
     temp=start;
     while(temp->next->next!=NULL)
     {
        temp=temp->next;
        }
        free(temp->next->next);
        temp->next=NULL;
        }
}
void display(){
    struct node *temp=start;
    if(start==NULL)
    printf("\nEmpty list");
    else
    {
        printf("\nElements of list are:  ");
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }printf("NULL");
        }
}
void main(){
    int ch=6;
    do{
    printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n4. Delete rear\n5. Print\n6. Exit\n7. Insert after\n\nEnter choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1: insert_front();
        break;
        case 2: insert_rear();
        break;
        case 3: delete_front();
        break;
        case 4: delete_rear();
        break;
        case 5: display();
        break;
        case 6: printf("\n\tExiting..");
        exit(0);
        case 7: insert_after();
        break;
        default: printf("\nInvalid choice");
        break;
        }
    }while(ch!=6);
}
