#include <stdio.h>

#include<stdlib.h>

typedef struct linkedlist{
    int info;
    struct linkedlist *next;
}node;

void insert_at_begning(node **head1, int);
void transversing(node *);
void insertend(node **head1, int);
node * searching(node *,int);
void delete_beg(node **head);
void delete_end(node **head1);
void delete_elem(node **head1,int);
void insert_elem(node **head1,int,int);
void del_entire(node **head);

int main()
{
    node *head=NULL;
    int c,val,val2;
    while (1) {
        printf("\n");
        printf("1. insert at beginning\n");
        printf("2. insert at end\n");
        printf("3. insert after element\n");
        printf("4. delete at beginning\n");
        printf("5. delete at end\n");
        printf("6. delete after element\n");
        printf("7. delete entire list\n");
        printf("8. traversing\n");
        printf("9.searching\n");
        printf("10. Exit\n");
        printf("Enter choice for operations: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                  printf("enter value : ");
                  scanf("%d",&val);
                  insert_at_begning(&head,val);
                break;
            case 2:
                 printf("enter value : ");
                  scanf("%d",&val);
                  insertend(&head, val);
                break;
            case 3:
                  printf("enter before value : ");
                  scanf("%d",&val);
                  printf("enter value to be inserted : ");
                  scanf("%d",&val2);
                   insert_elem(&head,val,val2);
                break;
            case 4:
                delete_beg(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                  printf("enter value : ");
                  scanf("%d",&val);
                  delete_elem(&head,val);
                break;
            case 7:
                del_entire(&head);
                break;
            case 8:
                
                transversing(head);
                break;
           
            case 9:
                  printf("enter value : ");
                  scanf("%d",&val);
                printf("the address is %d",searching(head,val));
                break;
            case 10:
                
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}



void insert_at_begning(node **head1, int val){
    node *temp;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("unable to allocate memory");
    }
    temp -> info=val;
    if(*head1!=NULL)
    {
        temp -> next=(*head1);
    }
    else{
        temp -> next=NULL;
    }
    *head1=temp;
}

void transversing(node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->info);
        head=head->next;
    }
}

void insertend(node **head1,int v)
{
    node *temp,*loc;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("unable to allocate memory");
        return;
    }
    temp->info=v;
    temp->next=NULL;
    if(*head1==NULL)
    {
        *head1=temp;
    }
    else{
        loc=*head1;
        while(loc->next!=NULL)
        {
            loc=loc->next;
        }
        loc->next=temp;
    }
}


node* searching(node *head,int val)
{
    while(head!=NULL)
    {
        if(head->info==val)
        {
            return head;
        }
        head=head->next;
    }
    return head;
}


void delete_beg(node **head1){
    node *temp;
    temp=*head1;
    *head1=(*head1)->next;
    free(temp);
    
}

void delete_end(node **head1)
{
    node *temp,*loc;
    if((*head1)->next==NULL)
    {
        loc=*head1;
        *head1=NULL;
        
    }
    else{
        loc=*head1;
        while(loc->next!=NULL)
        {
            temp=loc;
            loc=loc->next;
        }
    }
    temp->next=NULL;
    free(loc);
}

void delete_elem(node **head1,int val){
    node *temp,*loc;
    loc=searching(*head1,val);
    if(loc==NULL)
    {
        printf("that element is not available");
    }
    if(loc->next==NULL)
    {
        printf("node not available");
    }
    temp=loc->next;
    loc->next=temp->next;
    free(temp);

}


void insert_elem(node **head1,int val,int val2){
    
    node *temp,*loc,*loc2;
    temp=(node *)malloc(sizeof(node));
    loc=searching(*head1,val);
    if(loc==NULL)
    {
        printf("that element is not available");
    }
    temp->info=val2;
    temp->next=loc->next;
    loc->next=temp;
    
    
}

void del_entire(node **head)
{
    node *temp = *head;
    node *loc;

    while (temp != NULL) {
        loc = temp->next;
        free(temp);
        temp = loc;
    }

    *head = NULL; 
}

