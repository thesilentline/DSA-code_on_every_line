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
bool ispalin(string s)
{
    string r=s; 
    reverse(s.begin(),s.end());
    if(r==s)
    return true;
    else
    return false;
}
int solve(int i, int j, string s)
{
    if(i>=j or ispalin())
    return 1;

    if(dp[i][j]!=-1)
    return dp[i][j];

    string snew= s.substr(i, j - i + 1);
    

}
