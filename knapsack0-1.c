//A C Program to calculate and print the profit of the knapsack by Implementing 0/1 Knapsack problem using Dynamic Programming

#include<stdio.h>
 int max(int a,int b)
 {
     return (a>b)?a:b;
 }
 int knapsackProfit(int wb,int W[],int val[],int n)
 {
     int i,w;
     int knapw[n+1][wb+1];
     for(i=0;i<=n;i++)
     {
         for(w=0;w<=wb;w++)
         {
             if(i==0||w==0)
             {
                 knapw[i][w]=0;
             }
             else if(W[i-1]<=w)
             {
                 knapw[i][w]=max(val[i-1]+knapw[i-1][w-W[i-1]],knapw[i-1][w]);
             }
             else
             {
                 knapw[i][w]=knapw[i-1][w];
             }
         }
     }
     return knapw[n][wb];
 }
 int main()
 {
    int i,n=4;
    int w=24;
    int weights[] = {9, 12, 18, 15};
    int profits[] = {6, 9, 3, 12};
    printf("Weight\tProfits\n");
    for(i=0;i<n;i++)
    {
        printf("\n%6d \t %6d\n",weights[i],profits[i]);
    }
     printf("\n Weight(Maximum Weight) of the knapsack bag :- %d\n",w);
     printf("\n n (Number of Items) = %d \n",n);
     printf("\n\nThe value he/she can carry in his bag : %d \n",knapsackProfit(w,weights,profits,n));
 }
