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
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int i=0,j=1;
    for(int t=0;t<n;t++)
    {
        if(v[t]<0)
        {
            if(i>=n)
            i=j;
            temp[i]=v[t];
            i=i+2;
        }
        else if(v[t]>=0)
        {
            if(j>=n)
            j=i;
            temp[j]=v[t];
            j=j+2;

        }
    }
    printvector(temp,n);
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