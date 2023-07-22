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
int dp[100];

int solve(int n)
{
    if(n<=2)
    return n;

    if(dp[n]!=-1)
    return dp[n];

    return dp[n]= solve(n-1) + (n-1)*solve(n-2);
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n)<<endl;
}