/////////////////////////////////////////////    TIME&SPACE : O(N^N)   
#include<bits/stdc++.h>
using namespace std;
void lps(string s,string r){
    int l=s.length();
    int arr[l+1][l+1];
    for(int i=0;i<l;i++){
        for(int j=1;j<l;j++){
            arr[i][j]=0;
        }
    }
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            if(s[i-1]==r[j-1]){
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    cout<<arr[l][l];
}
int main(){
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());
    lps(s,r);
}

--------------------------------------------------------------------------

// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void solve(string s,string r)
{
    int l=s.length();
    int arr[l+1][l+1];
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            arr[i][j]=0;
        }
    }
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            if(s[i-1]==r[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    int i=l+1,j=l+1;
    string k="";
    while(i>0&&j>0)
    {
        if(s[i-1]==r[j-1]){
            k=s[i-1]+k;
            i--;
            j--;
        }
        else if(arr[i-1][j]>arr[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<k;

}
int main()
{
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());
    solve(s,r);
    
    
}