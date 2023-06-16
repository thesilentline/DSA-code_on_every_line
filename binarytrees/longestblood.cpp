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

pair<int,int> longestbloodline(Node *root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }

    pair<int,int> left= longestbloodline(root->left);
    pair<int,int> right= longestbloodline(root->right);
    if(left.second>right.second)
    return make_pair(left.first+root->data,left.second+1);
    else
    return make_pair(right.first+root->data,right.second+1);
}

int main() 
{
    // Node* root = NULL;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     int k=0;
    //     cin>>k;
    //     root= insertNode(root,k);
    // }
    
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left= new Node(6);

    inorderTraversal(root);
    cout<<endl;
    pair<int,int> temp= longestbloodline(root);
    cout<<temp.first<<endl;
    
    return 0;
}
