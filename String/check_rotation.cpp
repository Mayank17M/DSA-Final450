//A Program to check if strings are rotations of each other or not.

# include <bits/stdc++.h>
using namespace std;

bool areRotations(string str1, string str2)
{
    bool flag=false;
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;
    string temp = str1 + str1;
    if(temp.find(str2)!=string::npos){
        flag=true;
    }
    return flag;
}

int main()
{
   string str1 = "AACD", str2 = "ACDA";
   if (areRotations(str1, str2))
     printf("Strings are rotations of each other");
   else
      printf("Strings are not rotations of each other");
   return 0;
}