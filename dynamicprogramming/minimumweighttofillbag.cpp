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
int dp[1001][1001];

int solve(int n,int w, vector<int> a)
{
    if(n<0 and w==0)
    return 0;

    if(n<0)
    return 1e9;

    if(w==0)
    return 0;

    if(dp[n][w]!=-1)
    return dp[n][w];

    if((n+1)>w or a[n]==-1)
    {
        return dp[n][w]=solve(n-1,w,a);
    }
    else
    {
        return dp[n][w]=min(solve(n-1,w,a),a[n]+solve(n,w-(n+1),a));
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int w;
    cin>>w;
    memset(dp,-1,sizeof(dp));
    int temp=solve(n-1,w,a);
    if(temp==1e9)
    cout<<-1<<endl;
    else
    cout<<temp<<endl;
}