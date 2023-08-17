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
int m=INT_MAX;
int solve(int i, vector<int> a, int n)
{
    if(i==n-1)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    

    for(int j=1;j<=a[i];j++)
    {
        if(i+j<n)
        m= 1+ min(m,solve(i+j,a,n));
    }
    return dp[i]= m;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,a,n);
    

}