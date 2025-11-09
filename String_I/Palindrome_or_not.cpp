/*A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
bool isPalindrome_helper(string &s, int i, int j)
{
    // base case
    if (i >= j)
        return true;

    // steps
    s[i] = tolower(s[i]);
    s[j] = tolower(s[j]);

    if (!(isalnum(s[i])))
    {
        return isPalindrome_helper(s, i + 1, j);
    }
    if (!(isalnum(s[j])))
    {
        return isPalindrome_helper(s, i, j - 1);
    }
    if (s[i] != s[j])
    {
        return false;
    }

    return isPalindrome_helper(s, i + 1, j - 1);
}
bool isPalindrome(string s)
{
    return isPalindrome_helper(s, 0, s.size() - 1);
}
int main()
{
    string s;
    cin>>s;
    bool ans = isPalindrome(s);
    cout << ans;
    return 0;
}