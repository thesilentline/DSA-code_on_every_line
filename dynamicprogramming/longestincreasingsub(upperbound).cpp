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
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int dp[n+1];
    for(int i=1;i<n+1;i++)
    dp[i]=INT_MAX;
    dp[0]=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int idx= upper_bound(dp,dp+n+1,a[i])-dp;
        if(a[i]>dp[idx-1] and dp[idx]>a[i])
        dp[idx]=a[i];
    }

    for(int i=n;i>0;i--)
    {
        if(dp[i]!=INT_MAX)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}