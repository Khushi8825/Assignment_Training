/*You are given n disks placed on a starting rod (from), with the smallest disk
 on top and the largest at the bottom. There are three rods: the starting rod(from)
 , the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks
 from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.*/
#include<iostream>
using namespace std;
int towerOfHanoi(int n, int src, int help, int des){
    if(n == 1) return 1;
    return towerOfHanoi(n-1, src, des, help) + 1 + towerOfHanoi(n-1, help, src, des);
}
int main(){
    int n;
    cin >> n;
    int src;
    int helper;
    int des;
    cout<<towerOfHanoi(n, src, helper, des);
    return 0;
}
