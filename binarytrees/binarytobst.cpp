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

void updatebst(Node* root,vector<int> &v)
{
    if(root==NULL)
    return;
    updatebst(root->left,v);
    root->data=v[0];
    v.erase(v.begin());
    updatebst(root->right,v);
}


int main() 
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);

    vector<int> v;
    
    inorderTraversal(root,v);
    cout<<endl;
    sort(v.begin(),v.end());
    updatebst(root,v);
    inorderTraversal(root,v);
    
    return 0;
}
