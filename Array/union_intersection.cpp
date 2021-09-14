/**
 * Find union and intersection of two unsorted arrays.
 * 
 * Reference: https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
*/

#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int b[], int n, int m) {
    //code here
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        s.insert(b[i]);
    }
    return s.size();
}

int doIntersection(int a[], int b[], int n, int m){
    set<int> s;
    int i=0,j=0;
    while(i<n && j<m){
        for(i=0;i<n;i++){
            for(j=0; j<m; j++){
                if(a[i]==b[j]) s.insert(a[i]);
            }
        }
    }
    return s.size();
}

// Driver Code
int main(){
    int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
 
    cout<<doUnion(a, b, n, m)<<endl;
    cout<<doIntersection(a, b, n, m);
}