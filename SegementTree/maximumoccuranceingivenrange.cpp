#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void build(ll tree[],ll arr[],ll node, ll start,ll end1)
{
    if(start==end1)
    {
        tree[node]=arr[start];
        return;
    }
    ll mid=(start+end1)/2;
    build(tree,arr,2*node,start,mid);
    build(tree,arr,2*node+1,mid+1,end1);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
ll query(ll tree[],ll node,ll start,ll end1,ll left,ll right)
{

     if(right<start || end1<left)
        return 0;
    if(left<=start && end1<=right)
    {
        return tree[node];
    }
    ll mid=(start+end1)/2;
    ll p1=query(tree,2*node,start,mid,left,right);
    ll p2=query(tree,2*node+1,mid+1,end1,left,right);
    return max(p1,p2);
}
int main()
{
    ll i,j,k,l,m,n;
    cin>>n;
    ll arr[n+1];
    for(i=1;i<=n;i++)
        cin>>arr[i];
    ll freq[n+1]={0};
    map<ll,ll>m1;
    for(i=1;i<=n;i++)
        m1[arr[i]]++;
    for(i=1;i<=n;i++)
        freq[i]=m1[arr[i]];

    ll height=(ll)(ceil(log2(n)));
    ll max_size=2*(ll)pow(2,height)-1;
    ll tree[max_size]={0};
    build(tree,freq,1,1,n);
    for(i=1;i<max_size;i++)
    {
        cout<<"i==="<<i<<"   "<<tree[i]<<endl;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll maxocc;
            if(arr[l]==arr[r])
                maxocc=r-l+1;
            else
            {
                ll leftmost=0;
                ll rightmost=0;
                while(l>1 && l<=r && arr[l]==arr[l-1])
                {
                    l++;
                    leftmost++;
                }
                while(r>=l && r<n && arr[r]==arr[r+1])
                {
                    r--;
                    rightmost++;
                }
                maxocc=max(leftmost,rightmost);
                ll val=query(tree,1,1,n,l,r);
                maxocc=max(maxocc,val);
            }
                cout<<maxocc<<endl;
            }
}
