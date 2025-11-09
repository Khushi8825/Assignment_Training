// Problem Statement: Write a program to remove all characters 
//  a string except alphabets in a given string.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string remove(string s){
    string ans = "";
    for(int i = 0;i<s.size(); i++){
        if(isalpha(s[i])){
            ans += s[i];
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    string ans = remove(s);
    cout << ans;
    return 0;
}