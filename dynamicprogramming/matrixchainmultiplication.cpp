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
int solve(int i, int j, vector<int> v)
{
    if(i==j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=INT_MAX;
    int res;
    for(int d=i;d<j;d++)
    {
        res=v[i-1]*v[d]+v[j] + solve(i,d,v) + solve(d+1,j,v);
        ans= min(ans,res);
    }
    return dp[i][j]= ans;

}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n-1,v)<<endl;

}