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
    int k=0;
    cin>>k;
    int mins=n;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=k)
        count++;
    }
    int nonfav=0;
    for(int i=0;i<count;i++)
    {
        if(v[i]>k)
         nonfav++;
    }
    int r=count-1;
    int l=0;
    while(r<n)
    {
        if(nonfav<mins)
        mins=nonfav;
        r++;
        if(r<n and v[r]>k)
        nonfav++;
        if(v[l]>k)
        nonfav--;
        l++;
    }
    cout<<mins<<endl;
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