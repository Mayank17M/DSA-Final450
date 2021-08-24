// Minimum number of jumps to reach end of an array.

#include<bits/stdc++.h>
using namespace std;

int minJumpsToEnd(int arr[], int n){
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        int jump=1;
        int max=arr[0];
        int x=arr[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return jump;
            // if(arr[0]==0) return -1;
            if(i+arr[i]>max) max=i+arr[i];
            x--;
            if(x==0){
                jump++;
                if(i>=max) return -1;
                x=max-i;
            }
            // i+=arr[i];
            // jump++;
        }
        // return i>=n?jump:-1;
        return -1;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<minJumpsToEnd(arr,n)<<endl;
    }
    return 0;
}