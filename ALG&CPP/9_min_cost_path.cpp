// You are using GCC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int row=100;
const int col=100;

int mincost(int cost[row][col], vector<pair<int,int>>&path,int n,int m){
    int dp[n][m];
    
    dp[0][0]=cost[0][0];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+cost[i][0];
    }
    for(int j=1;j<m;j++){
        dp[0][j]=dp[0][j-1]+cost[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n-1,j=m-1;
    path.push_back({i,j});
    while(i>0||j>0){
        if(i>0&&dp[i-1][j]<dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
        path.push_back({i,j});
    }
    reverse(path.begin(),path.end());
    return dp[n-1][m-1];
}
int main(){
    int cost[row][col];
    int newrow,newcol;
    cin>>newrow>>newcol;
    for(int i=0;i<newrow;i++){
        for(int j=0;j<newcol;j++)
        {
            cin>>cost[i][j];
        }
    }
    vector<pair<int,int>>path;
    int mincostvalue=mincost(cost,path,newrow,newcol);
    cout<<"Minimum Cost: "<<mincostvalue<<endl;
    cout<<"Path:"<<endl;
    for(const auto& num:path){
        cout<<"("<<num.first<<", "<<num.second<<")"<<endl;
    }
    return 0;
}




//gowtham method:

// You are using GCC
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n,i,j;
    cin>>m>>n;
    vector<int>path;
    int cost[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    for(i=1;i<m;i++){
        cost[i][0]+=cost[i-1][0];
    }
        for(j=1;j<n;j++){
            cost[0][j]+=cost[0][j-1];
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                cost[i][j]+=min(cost[i-1][j],cost[i][j-1]);
            }
        }
        i=m-1,j=n-1;
        path.push_back({i+j});
        while(i>0||j>0){
            if(i>0&&cost[i-1][j]>=cost[i][j-1]){
                path.push_back({i+j-1});
                j--;
            }
            else if(i>0&&j==0){
                path.push_back({i-1+j});
                i--;
            }
            else if(j>0&&i==0){
                path.push_back({i+j-1});
                j--;
            }
            else if(j>0&&cost[i-1][j]<cost[i][j-1]){
                path.push_back({i-1+j});
                i--;
            }
        }
        cout<<"Minimum Cost : "<<cost[m-1][n-1];
        cout<<"\nSum of the Cell :"<<endl;
        for(i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
    }
 // this is for sum of the cell in min path