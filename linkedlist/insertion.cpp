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
class Node 
{
public:
    int data;
    Node* next;
    
    Node(int temp) 
    {
        data = temp;
        next = NULL;
    }
};

class LinkedList 
{
private:
    Node* head;

public:
    LinkedList() 
    {
        head = NULL;
    }
    
    void insert(int data) 
    {
        Node* newNode = new Node(data);
        
        if (head == NULL) 
        {
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    
    void display() 
    {
        Node* current = head;
        
        while (current != NULL) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        
        cout<<endl;
    }
};

int main() 
{
    LinkedList list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        list.insert(t);
    }
    
    list.display();
}