#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int i,n,j,k;
cout<<"enter the number of elements:";
cin>>n;
int a[n];
cout<<"enter n elements:";
for(i=0;i<n;i++)
cin>>a[i];
for(i=1;i<n;i++)
{
j=i-1;
k=a[i];
while(a[j]>k && j>=0)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=k;
}
for(i=0;i<n;i++)
cout<<a[i]<<" ";
return 0;
}
/*
enter the number of elements:5
enter n elements:7
2
6
3
5
2 3 5 6 7

*/
