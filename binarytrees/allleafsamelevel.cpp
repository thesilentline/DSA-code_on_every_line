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

bool checklevel(Node* root)
{
    map<int,vector<int> > m;
    queue<pair<Node*, int> > q;
    if(root==NULL)
    return true;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*, int> temp= q.front();
        q.pop();
        int hd= temp.second;
        Node* node= temp.first;
        if(node->left==NULL and node->right==NULL)
        m[hd].push_back(node->data);
        if(node->left)
        q.push(make_pair(node->left,hd+1));
        if(node->right)
        q.push(make_pair(node->right,hd+1));
    }
    if(m.size()==1)
    return true;
    else
    return false;
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
    if(checklevel(root))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
