//Maximum and minimum of an array using minimum number of comparisons

#include <bits/stdc++.h>
using namespace std;

void getresult(int arr[], int n){
    int min=0, max=0;
    if(n==1) max=min=arr[0];
    if (arr[0] > arr[1]){
      max = arr[0];
      min = arr[1];
   }
   else{
      max = arr[1];
      min = arr[0];
   }
   for (int i = 2; i<n; i++){
      if (arr[i] > max)
         max = arr[i];
      else if (arr[i] < min)
         min = arr[i];
   }
   printf(" Minimum element: %d", min);
   printf(" Maximum element: %d", max); 
}

int main(){
   int arr[] = {200, 191, 112, -11, 330, 60};
   int n = 6;
   getresult (arr, n);
}