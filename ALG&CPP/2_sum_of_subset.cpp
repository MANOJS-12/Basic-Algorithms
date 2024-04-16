#include<iostream>
using namespace std;
int tcount=0;
void count(int sum,int tsum,int index,int arr[],int n)
{
    if(tsum==sum)
    {
        tcount++;
        return;
    }
    if(tsum>sum || index==n )
    {
        return;
    }
    count(sum,tsum+arr[index],index+1,arr,n);
    count(sum,tsum,index+1,arr,n);
}
int main()
{
    int i,sum,tsum;
    int size;
    cin>>size;
    int arr[size];
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cin>>sum;
    
    if(count(sum,0,0,arr,size))
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
        
}

---------------------------------------------------------

#include<iostream>
using namespace std;
int tcount=0;
void count(int sum,int tsum,int index,int arr[],int n)
{
    if(tsum==sum)
    {
        tcount++;
        return;
    }
    if(tsum>sum || index==n )
    {
        return;
    }
    count(sum,tsum+arr[index],index+1,arr,n);
    count(sum,tsum,index+1,arr,n);
}
int main()
{
    int i,sum,tsum;
    int size;
    cin>>size;
    int arr[size];
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cin>>sum;
    count(sum,0,0,arr,size);
    cout<<tcount;
}

