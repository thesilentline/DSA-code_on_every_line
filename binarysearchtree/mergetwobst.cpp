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

Node* balanced(int b, int e,vector<int> &v)
{
    if(b>e)
    return NULL;

    int mid=(b+e)/2;
    Node* root= new Node(v[mid]);

    root->right=balanced(mid+1,e,v);
    root->left=balanced(b,mid-1,v);
    return root;

}

int main() 
{
    Node* root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node* root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    vector<int> v;
    inorderTraversal(root1,v);
    cout<<endl;
    inorderTraversal(root2,v);
    cout<<endl;
    sort(v.begin(),v.end());

    Node* root= balanced(0,v.size()-1,v);
    inorderTraversal(root,v);

    cout<<endl;
    cout<<root->data<<endl;
    
    return 0;
}
