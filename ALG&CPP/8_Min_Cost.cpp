// You are using GCC
#include<iostream>
using namespace std;
int mincost(int cost[100][100],int row,int col){
    for(int i=1;i<row;i++)
    cost[i][0]+=cost[i-1][0];
    for(int j=1;j<col;j++)
    cost[0][j]+=cost[0][j-1];
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            cost[i][j]+=min(cost[i-1][j],cost[i][j-1]);
        }
    }
    return cost[row-1][col-1];
}
int main(){
    int cost[100][100];
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>cost[i][j];
        }
    }
    cout<<"The Minimum Cost is : "<<mincost(cost,row,col);
    cout<<endl;
    cout<<endl;
    cout<<"The Table Contains : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
}