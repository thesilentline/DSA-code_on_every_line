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
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int x=n/k;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    for(auto i: m)
    {
        if(i.second>x)
        cout<<i.first<<" ";
    }
}
int main()
{
// int t;
// cin>>t;
// for(int i=0;i<t;i++)
{
solve();
}
}