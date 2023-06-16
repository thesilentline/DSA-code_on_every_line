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

pair<int,int> maxsumalternate(Node* root)
{
    if(root==NULL)
    return make_pair(0,0);

    pair<int,int> left= maxsumalternate(root->left);
    pair<int,int> right= maxsumalternate(root->right);
    pair<int,int> temp;
    temp.first= root->data+ left.second+ right.second;
    temp.second= max(left.first,left.second)+max(right.first,right.second);
    return temp;
}

int main() 
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    
    inorderTraversal(root);
    cout<<endl;
    pair<int,int> temp= maxsumalternate(root);
    cout<<max(temp.first,temp.second)<<endl;
    
    return 0;
}
