/*Problem Statement: Write a program to count the number of words in a given string.*/
#include<iostream>
#include<string>
#include<climits>
using namespace std;
int countWords(string s){
    int count = 0;
    bool inWord = false;

    for(char c : s){
        if(c != ' ' && c != '\t' && c != '\n'){
            if(!inWord){
                count++;
                inWord = true;
            }
        } 
        else {
            inWord = false;
        }
    }
    return count;
}
int main(){
    string s;
    getline(cin, s);
    int ans = countWords(s);
    cout << ans << endl;
    return 0;
}