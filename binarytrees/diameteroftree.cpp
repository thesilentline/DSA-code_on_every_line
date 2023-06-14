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

pair<int,int> diameteroftree(Node* root)
{
    if(root==NULL)
    {
        pair<int,int> temp= make_pair(0,0);
        return temp;
    }
    pair<int,int> left= diameteroftree(root->left);
    pair<int,int> right=diameteroftree(root->right); 
    int op1= left.first;
    int op2= right.first;
    int op3= 1+left.second+right.second;
    pair<int,int> ans;
    ans.first= max(op1,max(op2,op3));
    ans.second=max(1+left.second,1+right.second);
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
    pair<int,int> temp= diameteroftree(root);
    cout<<temp.first<<endl;
    
    return 0;
}
