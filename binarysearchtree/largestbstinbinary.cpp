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

vector<int> isbst(Node* root)
{
    if(root==NULL)
    return {1,0,INT_MAX,INT_MIN};

    if(root->left==NULL and root->right==NULL)
    return {1,1,root->data,root->data};

    vector<int> l= isbst(root->left);
    vector<int> r= isbst(root->right);
    if(l[0] and r[0])
    {
        if(root->data >  l[3] and root->data <r[2])
        {
            int x=l[2];
            int y=r[3];
            if(x==INT_MAX)
            x= root->data;
            if(y==INT_MIN)
            y= root->data;
            return {1,l[1]+r[1]+1,x,y};
        }
    }
    
    return {0,max(l[1],r[1]),0,0};

}

int main() 
{
    Node* root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    
    inorderTraversal(root);
    cout<<endl;

    vector<int> v= isbst(root);
    cout<<v[1]<<endl;  
    return 0;
}
