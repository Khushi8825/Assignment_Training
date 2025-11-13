// Given the non-negative integers n , compute the factorial of a given number.
// Note: Factorial of n is defined as n * (n -1) * (n - 2) * ... * 1, for n = 0, factorial is 1.
#include<iostream>
using namespace std;
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}
int main(){
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans;
    return 0;
}