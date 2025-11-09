#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        int minIdx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx]= temp;
    }
    return;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return;
}

int main()
{
    vector<int> arr;
    int x;
    while (cin >> x && x != -1)
    {
        arr.push_back(x);
    }
    SelectionSort(arr);
    print(arr);
    return 0;
}