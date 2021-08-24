// Reverse an array

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    printArray(arr,n);
    reverseArray(arr,0,n-1);
    printArray(arr,n);
}