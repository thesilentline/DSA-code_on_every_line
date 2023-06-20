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

void count(Node* root,int &c)
{
    if(root==NULL)
    return;

    count(root->left,c);
    c++;
    count(root->right,c);
}

void medianbst(Node* root, Node* &prev,Node* &curr, int &c,int k)
{
    if(root==NULL)
    return;
    medianbst(root->left,prev,curr,c,k);
    if(c==k)
    {
        curr=root;
        return;
    }
    prev=root;
    c++;
    medianbst(root->right,prev,curr,c,k);

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
    Node* curr=NULL;
    int c=0;
    count(root,c);
    int k=1;
    int m=c/2+1;
    medianbst(root,prev,curr,k,m);
    if(c%2==0)
    cout<<(prev->data+curr->data)*(1.0)/(2.0)<<endl;
    else
    cout<<curr->data*(1.0);

    
    return 0;
}
