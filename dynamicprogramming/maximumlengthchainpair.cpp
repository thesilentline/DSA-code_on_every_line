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
int main()
{
    vector<pair<int,int>> p;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p.push_back(make_pair(x,y));
    }
    sort(p.begin(),p.end());
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[j].second<p[i].first)
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        m= max(m,dp[i]);
    }
    cout<<m<<endl;

}