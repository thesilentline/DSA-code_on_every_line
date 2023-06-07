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
    int m;
    cin>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int min=v[n-1];
    int t=0;
    for(int i=0;i<=n-m;i++)
    {
        if(min>(v[i+m-1]-v[i]))
        {
            min=v[i+m-1]-v[i];
            t=i;
        }
    }
    for(int i=t;i<t+m;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<min<<endl;

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