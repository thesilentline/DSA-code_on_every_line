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

pair<bool,int> balanced(Node* root)
{
    if(root==NULL)
    {
        pair<bool,int> temp= make_pair(1,0);
        return temp;
    }

    pair<bool,int> left= balanced(root->left);
    pair<bool,int> right=balanced(root->right);
    pair<bool,int> ans;

    if(abs(left.second-right.second)<=1 and left.first and right.first)
    ans.first= 1;
    else
    ans.first= 0;
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
    pair<bool,int> temp= balanced(root);
    if(temp.first)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    
    return 0;
}
