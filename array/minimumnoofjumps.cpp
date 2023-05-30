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
    if(n<=1)
    {
        cout<<0<<endl;
        return;
    }
    if(v[0]==0)
    {
        cout<<-1<<endl;
        return;
    }
    int steps=v[0];
    int maxreach=v[0];
    int jumps=1;
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            cout<<jumps<<endl;
            return;
        }
        maxreach=max(maxreach,i+v[i]);
        steps--;
        if(steps==0)
        {
            steps=maxreach-i;
            jumps++;
        }
        if(i>=maxreach)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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