#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> res;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i++;
            j++;
        } 
        else if (a[i] < b[j]) {
            i++;
        } 
        else {
            j++;
        }
    }
    
    return res;
}

int main() {
    int m, n;
    cin >> m;
    
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    
    cin >> n;
    
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
    vector<int> ans = commonElements(a, b);
    
    for (int x : ans) cout << x << " ";
}
