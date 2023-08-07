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
int solve(int n,int w, vector<int> val, vector<int> wt)
{
    if(n==-1 or w==0)
    return 0;

    if(dp[n][w]!=-1)
    return dp[n][w];

    if(wt[n]>w)
    return dp[n][w]=solve(n-1,w,val,wt);

    return dp[n][w]= max(val[n]+solve(n,w-wt[n],val,wt),solve(n-1,w,val,wt));
}

int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    cin>>val[i];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(n-1,w,val,wt)<<endl;

}