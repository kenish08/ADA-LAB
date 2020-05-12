#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<timer.h>
int a[20000],low,high,ele,pos;
int lin()
{
    if(pos<0)
    {
        return pos+1;
    }
    else if(a[pos]==ele)
    {
        return pos+1;
    }
    else
    {
        pos=pos-1;
        return lin();
    }
}
int bin()
{
    int mid=(low+high)/2;
    if(low>high)
    {
        return 0;
    }
    if(a[mid]==ele)
    {
        return mid+1;
    }
    else if(a[mid]>ele)
    {
        high=mid-1;
        return bin();
    }
    else if(a[mid]<ele)
    {
        low=mid+1;
        return bin();
    }
}
void main()
{
    int i,n,temp;
    Timer t;
    clrscr();
    printf("\nEnter the number of elements ");
    scanf("%d",&n);
    randomize();
    printf("\nEnter the search element ");
    scanf("%d",&ele);
    printf("\nEnter 1 for linear search and 2 for binary search ");
    scanf("%d",&i);
    if(i==1)
    {
        for(i=0;i<n;i++)
        {
            a[i]=rand();
        }
        pos=n-1;
        t.start();
        temp=lin();
        t.stop();
    }
    else
    {
        for(i=0;i<n;i++)
        {
            a[i]=i;
        }
        low=0;
        high=n-1;
        t.start();;
        temp=bin();
        t.stop();
    }
    printf("\nElement found at position = %d and time taken = %lf",temp,(double)t.time());
    getch();
}

