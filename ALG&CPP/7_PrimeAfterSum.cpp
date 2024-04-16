// You are using GCC
// You are using GCC
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> set;
vector<int> primeNo;
bool isPrimeNumber(int x){
    int sqroot = sqrt(x);
    bool flag= true;
    if(x==1){
        return false;
    }
    for(int i=2;i<=sqroot;i++){
        if(x%i==0){
            return false;
        }
    }
        return true;
    
}
void PrintPrimes(){
    int length=set.size();
    for(int i=0;i<length;++i){
        cout<<set[i]<<'\t';
    }
    cout<<endl;
}
void Generate(int total,int N,int S,int index){
    if(total==S && set.size()==N){
        PrintPrimes();
        return;
    }
    if(total>S || index== primeNo.size())
    return;
    
    set.push_back(primeNo[index]);
    Generate(total+primeNo[index],N,S,index+1);
    
    set.pop_back();
    Generate(total,N,S,index+1);
    
}

void PrimesWithSum(int N,int S,int P){
    for(int i=P+1;i<=S;++i){
        if(isPrimeNumber(i))
        primeNo.push_back(i);
    }
    if(primeNo.size()<N)
    return;
    Generate(0,N,S,0);
}

int main(){
    int S,N,P;
    cin>>S>>N>>P;
    cout<<N<<" Prime numbers greater than "<<P<<" with sum = "<<S<<" are :\n";
    PrimesWithSum(N,S,P);
}


-------------------------------------
#include<iostream>
using namespace std;
bool isprime(int n)
{
 if(n<2)
 {
 return false;
 
 }
 for(int i=2;i*i<=n;i++)
 {
 if(n%i==0)
 {
 return false;
 }
 }
 return true;
}
void find(int s,int num,int p,int cur[],int ind)
{
 if(s==0 && num==0)
 {
 for(int i=0;i<ind;i++)
 {
 cout<<cur[i]<<"\t";
 }
 cout<<endl;
 return;
 }
 for(int i=p+1;i<=s;i++)
 {
 if(isprime(i))
 {
 cur[ind]=i;
 find(s-i,num-1,i,cur,ind+1);
 }
 }
}
int main()
{
 int s;
 cin>>s;
 int n;
 cin>>n;
 int p;
 cin>>p;
 int cur[n];
 cout<<n<<" Prime numbers greater than "<<p<<" with sum = "<<s<<" are 
:"<<"\n";
 find(s,n,p,cur,0); 
 
}