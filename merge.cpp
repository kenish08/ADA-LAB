#include<iostream>
#include<vector>
using namespace std;
vector<int> input(vector<int> vec)
{
    auto x=0,n=0;
    cout<<"Enter the value of n \n";
    cin>>n;
    while(n-->0)
    {
        cin>>x;
        vec.push_back(x);
    }
    return vec;
}
vector<int> merge(vector<int> vec,int b,int m,int e)
{
    auto i=0,j=0,k=0,s1=m-b+1,s2=e-m;
    vector<int> l,r;
    for(i=0;i<s1;i++)
        l.push_back(vec[b+i]);
    for(j=0;j<s2;j++)
        r.push_back(vec[m+1+j]); 
    i=0;j=0;k=b;
    while(i<s1 && j<s2)
    {
        if(l[i]<=r[j])
        {
            vec[k]=l[i];i++;
        }
        else
        {
            vec[k]=r[j];j++;
        }
        k++;
    }
    while(i<s1)
    {
        vec[k]=l[i];
        i++;k++;
    }
    while(j<s2)
    {
        vec[k]=r[j];
        j++;k++;
    }
    return vec;
}
vector<int> mergesort(vector<int> vec,int b,int e)
{
    if(b<e)
    {
        auto m = (b+e-1)/2;
        vec=mergesort(vec,b,m);
        vec=mergesort(vec,m+1,e);
        vec=merge(vec,b,m,e);
    }
    return vec;
}
void display(vector<int> vec)
{
    auto i=0;
    while(i<vec.size())
    {
        cout<<vec[i]<<" ";
        i++;
    }
}
int main(void)
{
    vector<int> vec;
    vec=input(vec);
    vec=mergesort(vec,0,vec.size()-1);
    display(vec);
}
