//Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. 
//You are given a number N, you have to output the number of integers less than N in the sample space S.

#include<bits/stdc++.h>
using namespace std;

int countSquares(int n){
    int count=0;
    for(int i=1;i*i<n;i++){
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<countSquares(n)<<endl;
    return 0;
}