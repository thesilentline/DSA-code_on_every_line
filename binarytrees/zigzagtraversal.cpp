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

vector<int> zigzag(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    return ans;
    bool rightleft=false;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> temp;
        for(int i=0;i<size;i++)
        {
            Node* front=q.front();
            q.pop();
            temp.push_back(front->data);
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
        if(rightleft)
        {
            reverse(temp.begin(),temp.end());
        }
        rightleft=!rightleft;
        for(int i=0;i<size;i++)
        {
            ans.push_back(temp[i]);
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
    ans= zigzag(root);
    cout<<endl;
    printvector(ans,ans.size());
    
    return 0;
}
