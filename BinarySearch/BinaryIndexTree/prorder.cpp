/*
BST to a Tree with sum of all smaller keys
Given a Binary Search Tree(BST), convert it to a Binary Tree such that every key of the original BST is changed to key plus sum of all smaller keys in BST.

Given a BST with N Nodes we have to convert into Binary Tree
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
    ll data;
    node *left,*right;
};
node *newnode(ll val)
{
    node *temp=new node;
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
node *insert1(node *root,ll val)
{
    if(root==NULL)
        return newnode(val);
    if(root->data>val)
        root->left=insert1(root->left,val);
    if(root->data<val)
        root->right=insert1(root->right,val);
    return root;
}
 void inorder(node *root)
 {
     stack<node *>s1;
      node *temp=root;
     while(!s1.empty() || temp!=NULL)
     {

         while(temp!=NULL)
         {
             s1.push(temp);
             temp=temp->left;
         }
         temp=s1.top();
         s1.pop();
         cout<<temp->data<<" ";
         temp=temp->right;
     }
 }
 void preorder(node *root,vector<ll>&v1)
 {
     if(root==NULL)
        return;
     v1.push_back(root->data);
     preorder(root->left,v1);
     preorder(root->right,v1);
 }
int main()
{
    node *root=NULL;
    ll i,j,k,l,m,n;
    cin>>n;
    cin>>k;
    root=newnode(k);
    for(i=1;i<n;i++)
    {
        cin>>k;
        root=insert1(root,k);
    }
    vector<ll>v1;
    preorder(root,v1);
    cin>>m;
    ll c=0;
    for(i=0;i<v1.size();i++)
    {
        if(v1[i]>=m)
        {
            c++;
        }
        if(c!=0)
            cout<<v1[i]<<endl;
    }

}

