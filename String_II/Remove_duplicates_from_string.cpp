#include<iostream>
#include<string>
#include<climits>
#include<vector>
using namespace std;
string removeDuplicate(string s){
    vector<int> freq(256, 0);
    string ans = "";
    for(char c:s){
        if(freq[c] == 0){
            ans += c;
            freq[c]++;
        }
        else{
            freq[c]++;
        }
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    string ans = removeDuplicate(s);
    cout<<ans;
}