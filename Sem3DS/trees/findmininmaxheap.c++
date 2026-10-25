#include <bits/stdc++.h>
using namespace std;

int findMininMaxHeap(vector<int> &arr){
    int n = arr.size();
    int start = n/2;
    int minElement = arr[start];
    for(int i = start ; i < n ; i++){
        if(arr[i] < arr[i+1]){
            minElement = arr[i];
        }
    }

    return minElement;

}

int main(){
    vector<int> arr= {25,13,16,12,10,8,14};
    cout<<"Minimum element:"<<findMininMaxHeap(arr);
    return 0;
}