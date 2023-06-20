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

Node* insert(Node* root, int value) 
{
    if (root == NULL) 
    {
        Node* head=new Node(value);
        return head;
    }
    
    if (value < root->data) 
    {
        root->left = insert(root->left, value);
    }
    else 
    {
        root->right = insert(root->right, value);
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

bool find(Node* root, int k)
{
    if(root==NULL)
    return false;
    if(root->data==k)
    return true;
    else if(k>root->data)
    return find(root->right,k);
    else
    return find(root->left,k);

}

void sumequalx(Node* root1,Node* root2,int k)
{
    if(root1== NULL or root2==NULL)
    return;
    sumequalx(root1->left,root2,k);
    int temp= k-root1->data;
    if(find(root2,temp))
    cout<<root1->data<<" "<<temp<<endl;
    sumequalx(root1->right,root2,k);
}

int main() 
{
    Node *root1 = NULL, *root2 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 7);
    root1 = insert(root1, 2);
    root1 = insert(root1, 4);
    root1 = insert(root1, 6);
    root1 = insert(root1, 8);
 
    root2 = insert(root2, 10);
    root2 = insert(root2, 6);
    root2 = insert(root2, 15);
    root2 = insert(root2, 3);
    root2 = insert(root2, 8);
    root2 = insert(root2, 11);
    root2 = insert(root2, 18);
    
    inorderTraversal(root1);
    cout<<endl;

    inorderTraversal(root2);
    cout<<endl;

    sumequalx(root1,root2,16);
    
    return 0;
}
