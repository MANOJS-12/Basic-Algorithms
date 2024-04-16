// You are using GCC
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e9;
void pss(int arr[100][100],int n){
    int par[n];
    int key[n];
    bool safe[n];
    for(int i=0;i<n;i++){
        key[i]=MAX;
        safe[i]=false;
    }
    par[0]=-1;
    key[0]=0;
    for(int i=0;i<n-1;i++){
        int u=-1;
        for(int v=0;v<n;v++){
            if(!safe[v]&&(u==-1||key[v]<key[u])){
                u=v;
            }
        }
        safe[u]=true;
        for(int v=0;v<n;v++){
            if(!safe[v]&&arr[u][v]&&arr[u][v]<key[v]){
                par[v]=u;
                key[v]=arr[u][v];
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<par[i]<<" - "<<i<<" "<<arr[i][par[i]]<<" "<<endl;;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    pss(arr,n);
}