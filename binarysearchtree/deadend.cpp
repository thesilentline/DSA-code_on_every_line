//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
 
 
#define ll                      long long
#define pint                    pair<int,int>
#define plong                   pair<long long,long long>
#define vlong                   vector <long long>
#define vint                    vector <int>
#define endl                    "\n"
#define pb                      push_back
#define mp                      make_pair
#define for0(i,n)               for(int i=0;i<n;i++)
#define for1(i,n)               for(int i=1;i<=n;i++)
template <class t>              void printvector(vector<t>& v, ll n) {for0(i,n) {cout<<v[i]<<" ";} cout<<endl;}
//-----------------------------------------------------------------------------------------------------------

struct Node 
{
    int data;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int value) 
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int value) 
{
    if (root == NULL) 
    {
        Node* head=new Node(value);
        return head;
    }
    
    if (value < root->data) 
    {
        root->left = insertNode(root->left, value);
    }
    else 
    {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

void inorderTraversal(Node* root) 
{
    if (root == NULL) 
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void findleafnode(Node* root,vector<int> &v,map<int,int> &m)
{
    if(root==NULL)
    return;

    m[root->data]++;
    if(root->left==NULL and root->right==NULL)
    v.push_back(root->data);

    findleafnode(root->left,v,m);
    findleafnode(root->right,v,m);
}

int main() 
{
    Node* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k=0;
        cin>>k;
        root= insertNode(root,k);
    }
    
    inorderTraversal(root);
    cout<<endl;

    map<int,int> m;
    vector<int> v;
    findleafnode(root,v,m);
    printvector(v,v.size());
    for(auto i: v)
    {
        if(m.find(i+1)!=m.end() and m.find(i-1)!=m.end())
        cout<<i<<" ";
    }
    return 0;
}
