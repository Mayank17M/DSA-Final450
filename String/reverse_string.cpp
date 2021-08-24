//Reverse a string.

#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int start =0;
    int end = s.size()-1;
    while(start<end){
        char temp = s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }

    //Alternative one-liner solution.  
    //for(int i=0;i<s.size()/2;i++) swap(s[i],s[s.size()-1-i]);
       
}

}

void printString(vector<char> s, int n){
    for(int i=0; i<n; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');
    printString(s,s.size());
    reverseString(s);
    printString(s,s.size());
}


