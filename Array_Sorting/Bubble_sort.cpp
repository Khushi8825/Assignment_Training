#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr);
    print(arr);
    return 0;
}