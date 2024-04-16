// You are using GCC                              time and space : O(M*N)
#include<bits/stdc++.h>
using namespace std;

void printMatrix(int m[10][10],int r,int c){
    int s[r][c];
    for(int i=0;i<r;i++){
        s[i][0]=m[i][0];
    }
    for(int j=0;j<c;j++){
        s[0][j]=m[0][j];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(m[i][j]==1){
                s[i][j]=min({s[i][j-1],s[i-1][j],s[i-1][j-1]})+1;
            }
            else{
                s[i][j]=0;
            }
        }}
        
        int smax=s[0][0];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(smax<s[i][j]){
                    smax=s[i][j];
                }
            }
        }
        
        for(int i=0;i<smax;i++){
            for(int j=0;j<smax;j++){
                cout<<"1 ";
            }
            cout<<endl;
        }
    
}
int main(){
    int r,c;
    cin>>r>>c;
    int m[10][10];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    
    printMatrix(m,r,c);
    
}

-------------------------------------------------------------------------------------------------------------

// You are using GCC
#include<bits/stdc++.h>
using namespace std;

void printMatrix(bool m[10][10],int r,int c){
    int s[r][c];
    for(int i=0;i<r;i++){
        s[i][0]=m[i][0];
    }
    for(int j=0;j<c;j++){
        s[0][j]=m[0][j];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(m[i][j]==1){
            s[i][j]=min({s[i-1][j],s[i][j-1],s[i-1][j-1]})+1;
        }
            else{
                s[i][j]=0;
            }
        }
    }
    
    int smax=s[0][0];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(smax<s[i][j]){
                smax=s[i][j];
            }
        }
    }
    
    cout<<"Maximum size of Sub-matrix with 1's is : "<<smax<<"*"<<smax<<endl;
    cout<<"\n Max Square sub-matrix with 1's is :"<<endl;
    for(int i=0;i<smax;i++){
        for(int j=0;j<smax;j++){
            cout<<"1";
        }
        cout<<endl;
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    bool m[10][10];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    printMatrix(m,r,c);
}

-----------------------------------------------------------------------------------------------------------

// You are using GCC
#include<bits/stdc++.h>
using namespace std;


void printMatrix(int m[100][100],int r,int c){
    int s[r][c];
    for(int i=0;i<r;i++){
        s[i][0]=m[i][0];
    }
    for(int j=0;j<c;j++){
        s[0][j]=m[0][j];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(m[i][j]==1){
                s[i][j]=min({s[i-1][j],s[i][j-1],s[i-1][j-1]})+1;
            }
            else{
                s[i][j]=0;
            }
        }
    }
    
    int smax=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(smax<s[i][j]){
                smax=s[i][j];
            }
        }
    }
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[i][j]==smax){
                count++;
            }
        }
    }
    
    cout<<"Number of maximum size square sub-matrices with all 1s: "<<count;
}
int main(){
    int r,c;
    cin>>r>>c;
    int m[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    
    printMatrix(m,r,c);
}