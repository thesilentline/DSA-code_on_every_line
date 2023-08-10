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
int solve(int i,vector<int> v,int n)
{
    if(i>n)
    return 0;

    if(dp[i][n]!=-1)
    return dp[i][n];

    int x= v[i]+ min(solve(i+2,v,n),solve(i+1,v,n-1));
    int y= v[n]+ min(solve(i,v,n-2),solve(i+1,v,n-1));
    return dp[i][n]= max(x,y);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,v,n-1)<<endl;
}