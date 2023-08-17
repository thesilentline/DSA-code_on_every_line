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
int dp[100][100];
int solve(int n, int k, int h)
{
    if(k==1 or k==0)
    return k;

    if(n==0)
    return k;

    int mini=INT_MAX;
    int res=0;

    for(int i=1;i<=h;i++)
    {
        res= max(solve(n-1,k-1,h),solve(n,h-k,h));
        mini= min(res,mini);
    }
    return mini+1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,k,k)<<endl;
}