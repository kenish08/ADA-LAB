#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<timer.h>
void sel(int a[],int n)
{
    int i,j,temp,pos;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
}
void main()
{
    int *a,n,i;
    Timer t;
    clrscr();
    printf("\nEnter the value of n ");
    scanf("%d",&n);
    a=(int *)malloc(n);
    randomize();
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    t.start();
    sel(a,n);
    t.stop();
    printf("\nTime taken = %lf",t.time());
    getch();
}

