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


int main()
{
    string s;
    cin>>s;
    int len= s.size();
    for(int i=0;i<=len;i++)
    {
        for(int j=0;j<=len;j++)
        dp[i][j]=0;
    }
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(s[i-1]==s[j-1] and i!=j)
            dp[i][j]= 1 + dp[i-1][j-1];

            else
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout<<dp[len][len]<<endl;
}