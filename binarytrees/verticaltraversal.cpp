//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include <iterator>
#include<map>
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

vector<int> vertical(Node* root)
{
    map<int,map<int,vector<int> > > node;
    queue<pair<Node*, pair<int,int> > > q;
    vector<int> ans;
    if(root==NULL)
    return ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty())
    {
        pair<Node*,pair<int,int> > front= q.front();
        q.pop();
        node[front.second.first][front.second.second].push_back(front.first->data);
        if(front.first->left)
        q.push(make_pair(front.first->left,make_pair((front.second.first)-1,(front.second.second)+1)));
        if(front.first->right)
        q.push(make_pair(front.first->right,make_pair((front.second.first)+1,(front.second.second)+1)));
    }
    for(auto i: node)
    {
        for(auto j: i.second)
        {
            for(int k: j.second)
            {
                ans.push_back(k);
            }
        }
    } 
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
    vector<int> ans;
    ans= vertical(root);
    printvector(ans,ans.size());
    
    return 0;
}
