#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string calculateFreq(string s){
    sort(s.begin(), s.end());  
    string ans = "";
    int i = 1;
    char ch = s[0];
    int count = 1;
    while(i<s.size()){
        if(s[i]==ch){
            count++;
        }
        else{
            ans += (ch + to_string(count));
            ch = s[i];
            count = 1;
        }
        i++;
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    string ans = calculateFreq(s);
    cout<<ans;
    return 0;
}
