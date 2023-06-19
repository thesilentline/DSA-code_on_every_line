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

void inorderTraversal(Node* root) 
{
    if (root == NULL) 
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node* previous(Node* root)
{
    Node* temp= root->left;
    while(temp->right)
    {
        temp=temp->right;
    }
    return temp;
}

Node* successor(Node* root)
{
    Node* temp= root->right;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}

void solve(Node* root, Node* &prev, Node* &suc,int key)
{
    if(root==NULL)
    return;
    if(root->data==key)
    {
        if(root->left)
        prev=previous(root);
        if(root->right)
        suc=successor(root);
    }
    else if(key>root->data)
    {
        prev=root;
        solve(root->right,prev,suc,key);
    }
    else
    {
        suc=root;
        solve(root->left,prev,suc,key);
    }
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

    Node* prev=NULL;
    Node* suc=NULL;
    int key;
    cin>>key;
    solve(root,prev,suc,key);
    cout<<prev->data<<" "<<suc->data<<endl;
    return 0;
}
