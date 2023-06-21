//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
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

void inorderTraversal(Node* root,vector<int> &v) 
{
    if (root == NULL) 
        return;
    
    inorderTraversal(root->left,v);
    cout << root->data << " ";
    v.push_back(root->data);
    inorderTraversal(root->right,v);
}

Node* insert(Node* root,int d, Node* &succ)
{
    if(root==NULL)
    return root= new Node(d);

    if(d < root->data)
    {
        succ= root;
        root->left = insert(root->left, d, succ);
    }
    else if(d > root->data)
    {
        root->right= insert(root->right, d, succ); 
    }
    return root;
}

void replace(vector<int> &v)
{
    Node* root= NULL;
    for(int i=v.size()-1;i>=0;i--)
    {
        Node* succ= NULL;
        root= insert(root,v[i],succ);
        if(succ)
        v[i]=succ->data;
        else
        v[i]=-1;
    }

}

int main() 
{
    Node* root = NULL;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int k=0;
        cin>>k;
        v.push_back(k);
    }
    printvector(v,v.size());
    replace(v);

    printvector(v,v.size());
    
    return 0;
}
