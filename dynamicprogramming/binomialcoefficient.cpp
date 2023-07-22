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
    int n,r;
    cin>>n>>r;
    if(r>n)
    {
        cout<<0<<endl;
        return 0;
    }
    int mod= 1000000007;
    r=min(r,n-r);
    vector<int> dp(r+1,0);
    dp[0]=1;
    for(int j=1;j<=n;j++)
    {
        for(int i=min(j,r);i>0;i--)
        {
            dp[i]= (dp[i-1]+dp[i])%mod;
        }
    }
    cout<<dp[r]<<endl;
}