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

Node* successor(Node* root)
{
    Node* temp= root->right;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}

Node* deletenode(Node* root, int key)
{
    if(root==NULL)
    return NULL;
    if(key>root->data)
    {
        root->right = deletenode(root->right,key);
    }
    else if(key<root->data)
    {
        root->left= deletenode(root->left,key);
    }
    else
    {
        if(!root->left)
        {
            return root->right;
        }

        else if(!root->right)
        {
            return root->left;
        }
        else
        {
            Node* succ= successor(root);
            swap(root->data,succ->data);
            root->right= deletenode(root->right,key);
        }
    }
    return root;


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
    int k;
    cin>>k;
    root= deletenode(root,k);
    inorderTraversal(root);
    cout<<endl;


    
    return 0;
}
