#include <bits/stdc++.h>
using namespace std;
int answer(int arr[], int ranges[][2], int reversals,
 int index){
     for (int i = reversals - 1; i >= 0; i--) {
        int left = ranges[i][0], right = ranges[i][1];
        if (left <= index && right >= index)
        index = right + left - index;
        }
    return arr[index];
}
int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int reversals;
    cin>>reversals;
    int ranges[reversals][2];
    for(int i=0; i<reversals; i++){
        for(int j=0; j<2; j++){
            cin>>ranges[i][j];
        }
    }
     int index;
    cin>>index;
    cout << answer(arr, ranges, reversals, index);
    return 0;
}