/*Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.*/
#include<iostream>
using namespace std;
    int helper(int& n, int x){
        
        if(n % x != 0) return 0;
        return 1;
    }
    int evenlyDivides(int n) {
        // code here
        int count = 0; 
        int x = n;
        while(n != 0){
            int rem = n % 10;
            count += helper(x, rem);
            n = n/10;
        }
        return count;
    }
int main(){
    int n;
    cin >> n;
    int ans =  evenlyDivides(n);
    cout << ans;
    return 0;
}