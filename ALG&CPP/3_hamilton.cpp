#include<iostream>
using namespace std;
int V;
int graph[100][100];
void printSolution(int arr[])
{
    for(int i=0;i<V;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[0];
}
bool isSafe(int v,int pos,int path[])
{
    if(graph[path[pos-1]][v]==0)
    {
        return false;
    }
    for(int i=0;i<pos;i++)
    {
        if(v==path[i])
        {
            return false;
        }
    }
    return true;
}
bool Hamiltonian(int pos,int path[])
{
    if(pos==V)
    {
        return true;
    }
   
    for(int v=1;v<V;v++)
    {
        if(isSafe(v,pos,path))
        {
            path[pos] = v;
           
            if(Hamiltonian(pos+1,path))
            {
                return true;
            }
            path[pos]=-1;
        }
    }
    return false;
}
int main()
{
    int i,j;
    cin>>V;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    int path[V];
    for(i=0;i<V;i++)
    {
        path[i]=-1;
    }
    path[0]=0;
    if(Hamiltonian(1,path))
    {
        printSolution(path);
    }
    else
    {
        cout<<"No solution";
    }
}