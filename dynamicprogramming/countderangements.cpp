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
    vector<int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]= (i-1)*(dp[i-1]+dp[i-2]);
    }
    cout<<dp[n]<<endl;
}