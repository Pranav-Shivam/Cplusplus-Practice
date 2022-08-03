#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
}node;

int main()
{
    int i,len;
    printf("Enter the lenhth of string :- ");
    scanf("%d",&len);

    struct node *headNode, *currentNode, *temp;

    for(i=0;i<len;i++)
    {
        currentNode =(node *)malloc(sizeof(node));

        printf("Enter the element:- ");
        scanf("%d",&currentNode->value);

        if(i==0)
        {
            headNode=temp=currentNode;
        }
        else
        {
            temp->next=currentNode;
            temp=currentNode;
        }
    }
    temp->next=NULL;
    temp=headNode;
    printf("The linked list :- ");

    for(i=0;i<len;i++)
    {
        printf("%d >> ",temp->value);
        temp=temp->next;
    }
}