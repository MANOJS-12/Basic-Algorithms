#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m=(n-1)/2;
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        arr[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i;(i+j+(2*i*j))<=m;j++)
        {
            arr[i+j+(2*i*j)]=0;
        }
    }
    cout<<2<<" ";
    for(int i=1;i<=m;i++)
    {
        if(arr[i]!=0)
        {
            int k=2*arr[i]+1;
            cout<<k<<" ";
        }
    }
    return 0;
}