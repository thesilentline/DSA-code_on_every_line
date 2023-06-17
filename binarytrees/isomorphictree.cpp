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

bool isomorphic(Node* root1, Node* root2)
{
    if(root1== NULL and root2==NULL)
    return true;
    if(root1==NULL or root2==NULL)
    return false;
    if(root1->data != root2->data)
    return false;
    bool a= isomorphic(root1->left,root2->left) and isomorphic(root1->right,root2->right);
    bool b= isomorphic(root1->left, root2->right) and isomorphic(root1->right,root2->left);
    return a or b;
}

int main() 
{
    struct Node *n1 = new Node(1);
    n1->left        = new Node(2);
    n1->right       = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);
 
    struct Node *n2 = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right   = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);
    
    inorderTraversal(n1);
    cout<<endl;
    inorderTraversal(n2);
    cout<<endl;

    cout<<isomorphic(n1,n2)<<endl;
    
    return 0;
}
