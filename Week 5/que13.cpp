#include <bits/stdc++.h>
using namespace std;

bool findPair(vector<int>& a, int key, int &x, int &y) {
    sort(a.begin(), a.end());
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == key) {
            x = a[l];
            y = a[r];
            return true;
        } else if (sum < key) {
            l++;
        } else {
            r--;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int key;
        cin >> key;
        int x, y;
        if (findPair(a, key, x, y))
            cout << x << " " << y << endl;
        else
            cout << "No Such Element Exist" << endl;
    }
}
