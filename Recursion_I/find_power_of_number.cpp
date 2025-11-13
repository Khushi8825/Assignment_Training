/*Given a number n, find the value of n raised to the power of its own reverse.
Note: The result will always fit into a 32-bit signed integer.*/

#include<iostream>
using namespace std;
 int reverse(int n){
       int ans = 0;
       while(n != 0){
           int rem = n%10;
           ans = ans*10 + rem;
           n = n/10;
       }
        return ans;
    }
    int helper(int n, int rev){
        if(rev == 0) return 1;
        return n*helper(n, rev-1);
    }
    int reverseExponentiation(int n) {
        // code here
        int rev = reverse(n);
        
        return helper(n, rev);
    }
int main(){
    int x;
    cin >> x;
    int ans = reverseExponentiation(x);
    cout<<ans;
    return 0;
}