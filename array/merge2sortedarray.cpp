#include<iostream>
//~ author      : DSB
#include<bits/stdc++.h>
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
    int m;
    cin>>m;
    vector<int> v2(m);
    for(int i=0;i<m;i++)
    cin>>v2[i];
    int i=0;
    int k=n-1,j=0;
    while(v[n-1]>v2[0])
    {
        swap(v[n-1],v2[0]);
        sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());
    }
    printvector(v,n);
    printvector(v2,m);

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