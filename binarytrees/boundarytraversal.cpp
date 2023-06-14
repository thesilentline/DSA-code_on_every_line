//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
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

void leftside(Node* root,vector<int> &ans)
{
    if(root==NULL or (root->left==NULL and root->right==NULL))
    return;
    ans.push_back(root->data);
    if(root->left)
    leftside(root->left,ans);
    else
    leftside(root->right,ans);
}

void rightside(Node* root,vector<int> &ans)
{
    if(root==NULL or (root->left==NULL and root->right==NULL))
    return;
    if(root->right)
    rightside(root->right,ans);
    else
    rightside(root->left,ans);
    ans.push_back(root->data);
}

void leafnode(Node* root,vector<int> &ans)
{
    if(root==NULL)
    return;

    if(root->left==NULL and root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafnode(root->left,ans);
    leafnode(root->right,ans);
}

vector<int> boundary(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    return ans;
    leftside(root,ans);
    leafnode(root,ans);
    rightside(root->right,ans);
    return ans;    
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
    vector<int> temp;
    temp= boundary(root);

    printvector(temp,temp.size());

    
    return 0;
}
