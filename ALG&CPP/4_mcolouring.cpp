#include<iostream>
using namespace std;
bool isSafe(int index, int c, int arr[][4],int color[])
{
    for(int i=0;i<4;i++)
    {
        if(arr[index][i]==1 && color[i]==c)
        return false;
    }
    return true;
}
bool mcolor(int m, int arr[][4],int color[],int index)
{
    if(index==4)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(isSafe(index,c,arr,color))
        {
            color[index] = c;
            if(mcolor(m,arr,color,index+1))
            return true;
            color[index] =0;
           
        }
    }
    return false;   
}
int main()
{
    int i,j;
    int arr[4][4];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    int m;
    cin>>m;
    int color[m];
    for(i=0;i<4;i++)
    {
        color[i]=0;
    }
    if(mcolor(m,arr,color,0))
    {
        for(i=0;i<4;i++)
        {
            cout<<color[i]<<" ";
        }
    }
    else{
        cout<<"No solution";
    }
}