#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getsum(ll BITree[],ll index)
{
    ll sum=0;
    index+=1;
    while(index>0)
    {

        sum+=BITree[index];
        index-=index&(-index);
    }
    return sum;
}
void updateBIT(ll BITree[],ll n,ll index,ll val)
{
    index+=1;
    while(index<=n)
    {
        BITree[index]+=val;
        index+=index&(-index);

    }
}
ll *constructBITree(ll arr[],ll n)
{
  ll *BITree=new ll[n+1];
  ll i,j;
  for(i=1;i<=n;i++)
    BITree[i]=0;
  for(i=0;i<n;i++)
  {
      updateBIT(BITree,n,i,arr[i]);
  }
    return BITree;
}

int main()
{
    ll i,j,k,l,m,n;
    cin>>n;
    ll arr[n+1];//BITree[n+1];
    for(i=0;i<n;i++)
        cin>>arr[i];
    ll *BITree=constructBITree(arr,n);
    cout<<"sum====="<<getsum(BITree,5);
    arr[3]=6;
    updateBIT(BITree,n,3,6);
    cout<<getsum(BITree,5);
}
