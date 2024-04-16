#include<bits/stdc++.h>
using namespace std;
int N,board[100][100];
const int moves[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

bool safe(int x,int y){
    return(x>=0 && x<N && y>=0&& y<N && board[x][y]==-1);
}
void printSolution(){
    cout<<"Solution exists: "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool solveutil(int x,int y,int count){
    if(count == N*N)
    	return true;
    for(int k=0; k<8; k++){
        int nextX=x+moves[k][0];
        int nextY=y+moves[k][1];
        if(safe(nextX,nextY)){
            board[nextX][nextY]=count;
            if(solveutil(nextX,nextY,count+1))
		return true;        
            else
          	board[nextX][nextY]=-1;
        }
    }
    return false;
}
int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			board[i][j]=-1;
		}
	}
			
        int startx=0; 
        int starty=0;
        board[startx][starty]=0;
        if(solveutil(startx,starty,1)){
            printSolution();
        }
        else{
            cout<<"No Solution exists.";
        }
}