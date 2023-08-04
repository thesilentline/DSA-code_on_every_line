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

int solve(int n, vector<int> a)
{
    if(n<0)
    return 0;

    if(n==0)
    return a[n];

    if(dp[n]!=-1)
    return dp[n];

    int x= a[n]+solve(n-2,a);
    int y= a[n]+a[n-1]+ solve(n-3,a);
    int z= solve(n-1,a);
    return dp[n]= max(x,max(y,z));
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
    memset(dp,-1,sizeof(dp));
    cout<<solve(n-1,a)<<endl;



}