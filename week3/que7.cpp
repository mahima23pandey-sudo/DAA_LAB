#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, long long &comparisons, long long &swaps)
{
    int n = arr.size();
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long comparisons, swaps;

        selectionSort(arr, comparisons, swaps);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}
