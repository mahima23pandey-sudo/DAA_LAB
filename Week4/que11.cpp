```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a,int l,int r)
{
    int x=a[r];
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=x)
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}

int quickSelect(vector<int>& a,int l,int r,int k)
{
    if(l<=r)
    {
        int p=partition(a,l,r);
        if(p==k) return a[p];
        if(p>k) return quickSelect(a,l,p-1,k);
        return quickSelect(a,p+1,r,k);
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];

        int k;
        cin>>k;

        if(k>n || k<=0)
        cout<<"not present"<<endl;
        else
        {
            int ans=quickSelect(a,0,n-1,k-1);
            cout<<ans<<endl;
        }
    }
}
```
