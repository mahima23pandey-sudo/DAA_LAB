
#include <iostream>
#include <vector>
using namespace std;

// Linear Search Function
bool linearSearch(vector<int> &arr, int key, int &comparisons) {
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int comparisons = 0;
    bool found = linearSearch(arr, key, comparisons);

    if (found)
        cout << "Present " << comparisons << endl;
    else
        cout << "Not Present " << comparisons << endl;

    return 0;
}
