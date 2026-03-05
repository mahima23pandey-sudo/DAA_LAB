```cpp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    
    vector<char>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    vector<int>count(26,0);
    
    for(int i=0;i<n;i++)
    count[a[i]-'a']++;
    
    int mx=0;
    char ch;
    
    for(int i=0;i<26;i++)
    {
        if(count[i]>mx)
        {
            mx=count[i];
            ch='a'+i;
        }
    }
    
    if(mx<=1)
    cout<<"No Duplicates Present"<<endl;
    else
    cout<<ch<<"-"<<mx<<endl;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    solve();
}
```
