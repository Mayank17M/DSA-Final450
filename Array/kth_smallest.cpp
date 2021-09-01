#include<bits/stdc++.h>
using namespace std;


//O(NLogN) solution
int kthSmallest(int arr[], int n, int k{
    sort(arr, arr + n);
    return arr[k - 1];
}

int main(){
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}

//Using set from STL. O(LogN)- avg case, O(N)- worst case.

// int main(){
//     int arr[]={12, 3, 5, 7, 4, 19, 26};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=4;
//     set<int> s(arr,arr+n);
//     set<int>:: iterator itr = s.begin();
//     advance(itr,k-1);
//     cout<<*itr<<endl;
//     return 0;
// }