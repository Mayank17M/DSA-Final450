/** 
 * Print all permutations of a string.
 * 
 * References: 
 *  https://www.javatpoint.com/program-to-find-all-permutations-of-a-string
 *  https://www.youtube.com/watch?v=GuTPwotSdYw&t=780s
 */

#include<bits/stdc++.h>
using namespace std;

void print_permutations(string input, int l, int r){
    if(l==r){
        cout<<input<<" ";
        return;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(input[l], input[i]);
            print_permutations(input, l+1, r);
            swap(input[l],input[i]);
        }
    }
}

int main(){
    string input = "ABC";
    print_permutations(input, 0, input.size()-1);
    return 0;
}