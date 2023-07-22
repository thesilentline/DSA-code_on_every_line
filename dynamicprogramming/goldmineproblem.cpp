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

int solve(int x,int y,int m, int n, vector<vector<int>> gold)
{
    if(x<0 or y<0 or x>m or y>n)
    return 0;

    if(dp[x][y]!=-1)
    return dp[x][y];


    int a= solve(x+1,y+1,m,n,gold);
    int b= solve(x,y+1,m,n,gold);
    int c= solve(x-1,y+1,m,n,gold);

    return dp[x][y]=gold[x][y] +  max(a,max(b,c));

}

int main()
{
    vector<vector<int>> gold {  {1, 3, 1, 5},
                                {2, 2, 4, 1},
                                {5, 0, 2, 3},
                                {0, 6, 1, 2}
                             };
    int m = 4, n = 4;
    memset(dp,-1,sizeof(dp));
    int ans=0;
    int index=0;
    for(int i=0;i<m;i++)
    {
        if(ans<gold[i][0])
        {
            ans=gold[i][0];
            index=i;
        }

    }
    cout<<solve(index,0,m-1,n-1,gold)<<endl;

}