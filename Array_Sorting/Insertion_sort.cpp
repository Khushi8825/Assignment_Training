#include <iostream>
#include<vector>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(vector<int>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    vector<int> arr;
    int x;
    while (cin >> x && x != -1)
    {
        arr.push_back(x);
    }
    insertionSort(arr, arr.size());
    printArray(arr, arr.size());
    return 0;
}

