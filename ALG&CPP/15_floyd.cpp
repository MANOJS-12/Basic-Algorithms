// Minimum distance :
#include<bits/stdc++.h>
using namespace std;
const int INF=999;
int v;
int m[100][100];
void dist(int w){
    int k,i,j;
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(m[i][j]>m[i][k]+m[k][j]){
                     m[i][j]=m[i][k]+m[k][j];
                }
            }
        }
    }
    cout<<"Minimum distance to reach "<<w<<" from 1 is "<<m[0][w-1];
}
int main(){
    cin>>v;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>m[i][j];
        }
    }
    int w;
    cin>>w;
    if(w>v){
        cout<<"Unknown Vertex";
    }
    else{
        dist(w);
    }
}
------------------------------------------------------------------------------------------------------

// shortest path 
#include<bits/stdc++.h>
using namespace std;
const int INF=999999;
int v;
void spm(int arr[100][100]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(arr[i][j]>(arr[k][j]+arr[i][k])&&arr[k][j]!=INF&&arr[i][k]!=INF){
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
    cout<<endl;
    cout<<"Shortest path matrix"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
          
                cout<<arr[i][j]<<" ";
        
        }
        cout<<endl;
    }
}
int main(){
    cin>>v;
    int e;
    cin>>e;
    int arr[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=INF;
            }
        }
    }
    int st,en,val;
    for(int i=0;i<e;i++){
        cin>>st>>en>>val;
        arr[st][en]=val;
        arr[en][st]=val;
    }
    cout<<"Original matrix"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(arr[i][j]==INF){
                cout<<"INF ";
            }
            else{
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
spm(arr);
}

---------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

void printpath(vector<vector<int>>&mat,int startnode,int endnode,vector<int>&path){
    path.push_back(startnode);
    if(startnode==endnode){
        for(int i=0;i<path.();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int v:mat[startnode]){
            if(find(path.begin(),path.end(),v)==path.end()){
                printpath(mat,v,endnode,path);
            }
        }
    }
    path.pop_back();
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>mat(n);
    int start,end;
    cin>>start>>end;
    for(int i=0;i<e;i++){
        cin>>start>>end;
        mat[start].push_back(end);
    }
    vector<int>path;
    int startnode,endnode;
    cin>>startnode>>endnode;
    printpath(mat,startnode,endnode,path);
}