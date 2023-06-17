//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<unordered_map>
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
unordered_map<string,int> m;
string duplicate(Node* root)
{
    if(root==NULL)
    return " ";
    string s="";
    if(root->left==NULL and root->right==NULL)
    {
        s= to_string(root->data);
        return s;
    }
    s = to_string(root->data)+" "+s;
    s = duplicate(root->left)+" "+s;
    s = duplicate(root->right)+" "+s;
    m[s]++;
    return s;
}

int main() 
{
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);
    
    inorderTraversal(root);
    cout<<endl;

    duplicate(root);
    for(auto i:m)
    {
        if(i.second>=2)
        {
            cout<<i.first<<endl;
        }
    }
    
    return 0;
}
