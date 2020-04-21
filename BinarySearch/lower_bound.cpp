// lower_bound will return an iterator to the first element equal to or greater than a given value in a sorted sequence
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll i,j,k,l,m,n;
        cin>>n;
        vector<ll>v1;
        for(i=0;i<n;i++)
        {
            cin>>k;
            v1.push_back(k);
        }
        ll q;
        sort(v1.begin(),v1.end());
        for(i=0;i<n;i++)
            cout<<v1[i]<<" ";

        cin>>q;
        while(q--)
        {
            cin>>m;
            ll id=lower_bound(v1.begin(),v1.end(),m)-v1.begin();
            cout<<id<<endl;
        }
    }


}
