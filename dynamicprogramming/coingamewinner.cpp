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
int solve(int k,int n, int x, int y)
{
    if(n<0)
    return 0;

    if(n==0 and k==1)
    return 1;

    if(n==0)
    return 0;

    if(dp[k][n]!=-1)
    return dp[k][n];

    if(k==0)
    {
        return dp[k][n]= (solve(1,n-1,x,y) or solve(1,n-x,x,y) or solve(1,n-y,x,y));
    }
    else
    return dp[k][n]= (solve(0,n-1,x,y) or solve(0,n-x,x,y) or solve(0,n-y,x,y));
}

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    memset(dp,-1,sizeof(dp));
    int k=1;
    cout<<(solve(k,n-1,x,y) or solve(k,n-x,x,y) or solve(k,n-y,x,y))<<endl;
}