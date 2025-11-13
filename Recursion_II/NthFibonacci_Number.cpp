/*Given a non-negative integer n, your task is to find the nth Fibonacci number.

The Fibonacci sequence is a sequence where the next term is the sum of the
 previous two terms. The first two terms of the Fibonacci sequence are 0 
 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

The Fibonacci sequence is defined as follows:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) for n > 1   
*/

#include<iostream>
using namespace std;
int nthFibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << nthFibonacci(n);
    return 0;
}