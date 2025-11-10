#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
char maxiElement(string s){
    unordered_map <char,int> freq;
    for(int i = 0; i<s.size(); i++){
        freq[s[i]]++;
    }
    int count = INT_MIN;
    char ans;
    for(auto i : freq){
        if(i.second > count){
            count = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin, s);
    char ans = maxiElement(s);
    cout<< ans;
    return 0;
}