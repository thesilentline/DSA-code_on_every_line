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
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> left(n);
    vector<int> right(n);
    left[0]=v[0];
    right[n-1]=v[n-1];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],v[i]);
    }
    int water=0;
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],v[i]);
    }
    for(int i=1;i<n-1;i++)
    {
        int temp= min(left[i-1],right[i+1]);
        if(temp>v[i])
        water+=temp-v[i];
    }
    cout<<water<<endl;
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