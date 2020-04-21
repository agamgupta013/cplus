#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
    ll sum;
    ll prefix;
};
node query(node tree[],ll index,ll start,ll end1,ll left,ll right)
{

    node result;
    result.sum=result.prefix=-1;
    if(start>right || end1<left)
        return result;
    if(start>=left && end1<=right)
        return tree[index];
    ll mid=(start=end1)/2;
    if(left>mid)
        return query(tree,2*index+1,mid+1,end1,left,right);
    if(right<=mid)
        return query(tree,2*index,start,mid,left,right);
    node l=query(tree,2*index,start,mid,left,right);
    node r=query(tree,2*index+1,mid+1,end1,left,right);
    result.sum=l.sum+r.sum;
    result.prefix=max(l.prefix,l.sum+r.prefix);

    return result;
}
void build(node tree[],ll arr[],ll index,ll start,ll end1)
{
    if(start==end1)
    {
        tree[index].sum=arr[start];
        tree[index].prefix=arr[start];
        return;
    }
    ll mid=(start+end1)/2;
    build(tree,arr,2*index,start,mid);
    build(tree,arr,2*index+1,mid+1,end1);
    tree[index].sum=tree[2*index].sum+tree[2*index+1].sum;
    tree[index].prefix=max(tree[2*index].prefix,tree[2*index].sum+tree[2*index+1].prefix);
}

int main()
{
    ll i,j,k,l,m,n;
    cin>>n;
    ll arr[n+1];
    node tree[4*n+1]={0};
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build(tree,arr,1,1,n);
    for(i=0;i<4*n;i++)
    cout<<i<<"      "<<tree[i].sum<<"   "<<tree[i].prefix<<endl;

}
