//Check if string is palindrome

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s){
    int flag=1;
    for(int i=0;i<S.length()/2;i++){
	    if(S[i]!=S[S.length()-1-i]) flag =0;
	}
    return flag;
}

int main(){
    string s;
    cin>>s;
    cout<<isPalindrome(s)<<endl;
    return 0;
}