//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
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
void unionofvector(vector<int> v1, vector<int> v2)
{
    unordered_set<int> s;
    for(int i=0; i<v1.size();i++)
    s.insert(v1[i]);
    for(int i =0;i<v2.size();i++)
    s.insert(v2[i]);
    cout<<s.size()<<endl;
}
void intersection(vector<int> v1, vector<int> v2)
{
    unordered_set<int> s;
    for(int i=0; i<v1.size();i++)
    s.insert(v1[i]);
    for(int i=0;i<v2.size();i++)
    {
        if(s.find(v2[i])!= s.end())
        {
            cout<<v2[i]<<" ";
        }
    }
}
int main()
{
// int t;
// cin>>t;
// for(int i=0;i<t;i++)
{
  int n;
  cin>>n;
  vector<int> v1(n);
  for(int i=0;i<n;i++)
  cin>>v1[i];
  int n1;
  cin>>n1;
  vector<int> v2(n1);
  for(int i=0;i<n1;i++)
  cin>>v2[i];
  unionofvector(v1,v2);
  intersection(v1,v2);
  }
}