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
    vector<int> profit(n,0);
    int maxprice=v[n-1];
    int minprice=v[0];
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]>maxprice)
        maxprice=v[i];

        profit[i]=max(profit[i+1],maxprice-v[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(v[i]<minprice)
        minprice=v[i];

        profit[i]=max(profit[i-1],profit[i]+v[i]-minprice);
    }
    cout<<profit[n-1]<<endl;
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