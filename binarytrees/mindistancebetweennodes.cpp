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

Node* leastcommon(Node* root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1 or root->data==n2)
    return root;
    Node* left=leastcommon(root->left,n1,n2);
    Node* right=leastcommon(root->right,n1,n2);
    if(left and right)
    return root;
    if(left)
    return left;
    else
    return right;
}

int distance(Node* root, int value)
{
    if(root==NULL)
    return 0;
    if(root->data==value)
    return 1;
    int left= distance(root->left,value);
    int right= distance(root->right,value);
    if(!left and !right)
    return 0;
    else
    return left+right+1;
}

int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    
    inorderTraversal(root);
    cout<<endl;

    // cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    // cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    // cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    // cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    int a=5;
    int b=8;
    Node* temp= leastcommon(root,a,b);
    int A=distance(temp,a);
    int B=distance(temp,b);
    cout<<A+B-2<<endl;
    
    return 0;
}
