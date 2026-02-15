#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairs(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int i = 0, j = 1;
    int count = 0;
    
    while (j < n) {
        if (i == j) {
            j++;
            continue;
        }
        
        int diff = arr[j] - arr[i];
        
        if (diff == k) {
            count++;
            i++;
            j++;
        }
        else if (diff < k) {
            j++;
        }
        else {
            i++;
        }
    }
    
    return count;
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
        
        int k;
        cin >> k;
        
        cout << countPairs(arr, k) << endl;
    }
    
    return 0;
}
