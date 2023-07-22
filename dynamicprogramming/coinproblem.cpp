//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<array>
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
long long dp[1000][1000];

int solve(int amt, int m, vector<int> coins)
{
    if(m==-1 and amt>0)
    return 0;
    if(amt<0)
    return 0;
    if(amt==0)
    return 1;

    if(dp[amt][m]!=-1)
    return dp[amt][m];

    else
    return dp[amt][m]= solve(amt-coins[m],m,coins) + solve(amt,m-1,coins);
}

int main()
{
    int amt,m;
    cin>>amt>>m;
    vector<int> coins(m);
    for(int i=0;i<m;i++)
    cin>>coins[i];
    // dp[amt+1][m];

    for(int i=0;i<=amt;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<solve(amt,m-1,coins)<<endl;;
    // cout<<dp[amt][m-1]<<endl;
}