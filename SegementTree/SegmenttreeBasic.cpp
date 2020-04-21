#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
static int p=0,h=0,u=0;
void build(ll tree[],ll arr[],ll node,ll start,ll end1)
{
    if(start==end1)
    {
        cout<<"node==="<<node<<"   "<<"arr[start]===="<<arr[start]<<endl;
        tree[node]=arr[start];
        return;
    }

        ll mid=(start+end1)/2;
       //ll mid = pow(2, ceil(log(end1-start)/log(2))-1);
       // cout<<"mid==="<<mid<<"  "<<"start===="<<start<<"end1==="<<end1<<"node ======"<<node<<endl;
        build(tree,arr,2*node,start,mid);
        build(tree,arr,2*node+1,mid+1,end1);
        tree[node]=tree[2*node]+tree[2*node+1];
}
void update(ll tree[],ll arr[],ll node,ll start,ll end1,ll index,ll val)
{
    if(start==end1)
    {
        arr[index]=val;
        tree[node]=val;
    }
    else
    {
        ll mid=(start+end1)/2;
        if(start<=index && mid>=index)
        {
            update(tree,arr,2*node,start,mid,index,val);
        }
        else
        {
            update(tree,arr,2*node+1,mid+1,end1,index,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
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
    cout<<"step---p"<<p<<" "<<"2*node ="<<2*node<<"start  mid  "<<start<<"   "<<mid<<endl;
    p++;
    ll p1=query(tree,2*node,start,mid,left,right);
    cout<<"p1======="<<p1<<endl;
    cout<<"step---h"<<h<<" "<<"2*node+1="<<2*node+1<<"mid+1 end  "<<mid+1<<"   "<<end1<<endl;
    cout<<"p1===="<<p1<<endl;
    h++;
    ll p2=query(tree,2*node+1,mid+1,end1,left,right);
    cout<<"step---u"<<u<<" "<<"2*node +1="<<2*node+1<<"mid+1  end  "<<mid+1<<"   "<<end1<<endl;
    u++;
    cout<<"p1    "<<p1<<"   " <<"p2===="<<p2<<endl;
    return p1+p2;
}
int main()
{

    ll i,j,k,l,m,n,tc;
    cin>>n;
    ll x = (int)(ceil(log2(n)));
        cout<<"x===="<<x;
    ll max_size = 2*(int)pow(2, x) - 1;
    cout<<"max_size"<<max_size;
    ll arr[n+1];
    ll tree[2*max_size+1];
    memset(tree,0,sizeof(tree));
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build(tree,arr,1,1,n);

    for(i=1;i<max_size;i++)
        cout<<"i==="<<i<<"   "<<tree[i]<<endl;
    cout<<endl;
    ll q;
    cin>>q;
    while(q--)
    {
        char ch;
        ll x,y;
        cin>>ch>>x>>y;
        if(ch=='q')
        {
            ll c=query(tree,1,1,n,x,y);
            cout<<c<<endl;
        }
        else
        {
            update(tree,arr,1,1,n,x,y);
            for(i=0;i<max_size;i++)
                cout<<i<<tree[i]<<endl;
        }
    }

}

