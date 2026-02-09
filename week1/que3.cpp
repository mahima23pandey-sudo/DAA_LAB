#include <iostream>
#include <vector>
using namespace std;


bool jumpSearch(vector<int> &arr, int key, int &comparisons) {
    int n = arr.size();
    int step = 2;
    int prev = 0;

    
    while (prev < n) {
        comparisons++;
        if (arr[prev] >= key)
            break;
        prev += step;
    }

    
    int start = max(0, prev - step);
    int end = min(prev, n - 1);

    for (int i = start; i <= end; i++) {
        comparisons++;
        if (arr[i] == key)
            return true;
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int comparisons = 0;
        bool found = jumpSearch(arr, key, comparisons);

        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}
