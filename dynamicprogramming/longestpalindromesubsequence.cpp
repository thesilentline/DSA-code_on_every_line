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
int solve(string s, int i, int n)
{
    if(i==n)
    return 1;

    if(i>n)
    return 0;

    if(dp[i][n]!=-1)
    return dp[i][n];

    if(s[i]==s[n])
    return dp[i][n]= 2+ solve(s,i+1,n-1);

    return dp[i][n]= max(solve(s,i+1,n),solve(s,i,n-1));
}

int main()
{
    string s;
    cin>>s;
    int n= s.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,n-1)<<endl;

}