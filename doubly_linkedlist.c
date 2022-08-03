#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * prev;
    struct node * next;
}*stNode,*enNode;

void doubly_List(int n);
void display_List();

int main()
{
    int n;
    stNode=NULL;
    enNode=NULL;
    printf("\n Doubly linked list :- Creation and display \n");
    printf("-----*******----------------------**********--------\n");
    printf("\nEnter the length of the list :- ");
    scanf("%d",&n);
    doubly_List(n);
    display_List();

    return 0;
}
//Creating a doubly linked list 
void doubly_List(int n)
{
    int i,num;
    struct node *fnNode;
    if(n>=1)
    {
        stNode=(struct node *)malloc(sizeof(struct node));

        if(stNode!=NULL)
        {
            printf("\nEnter first element :- ");
            scanf("%d",&num);
            stNode->data=num;
            stNode->prev=NULL;
            stNode->next=NULL;
            enNode=stNode;

            //Enter more elements in the Linked list
            for(i=2;i<=n;i++)
            {
                fnNode=(struct node *)malloc(sizeof(struct node));
                if(fnNode!=NULL)
                {
                    printf("\nEnter the value for %d elements :- ",i);
                    scanf("%d",&num);
                    fnNode->data=num;
                    fnNode->prev=enNode;
                    fnNode->next=NULL;
                    enNode->next=fnNode;
                    enNode=fnNode;
                }
                else
                {
                    printf("\nMemory can't be allocated \n");
                    break;
                }
            }
        }    
        else
        {
            printf("\nMemory can't be allocated \n");
        }
    }
}
void display_List()
{
    struct node *temp;
    int n=0;
   if(stNode==NULL)
    {
        printf("\nNo data found in the list \n");
    }
    else
    {
        temp=stNode;
        while(temp!=NULL)
        {
            printf("\nData at node %d is %d ",n,temp->data);
            n++;
            temp=temp->next;
        }
    }
}