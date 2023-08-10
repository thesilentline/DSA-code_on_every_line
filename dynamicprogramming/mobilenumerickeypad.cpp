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
int solve(vector<vector<int>> number, int i,int j, int n)
{
    if(n==1)
    return 1;

    if(dp[number[i][j]][n]!=-1)
    return dp[number[i][j]][n];

    int a= solve(number,i,j,n-1);

    int e=0,b=0,c=0,d=0;

    if((i-1>-1) and number[i-1][j]!=-1)
        e= solve(number, i-1,j, n-1);
    if((i+1<4) and number[i+1][j]!=-1)
        b= solve(number, i+1,j, n-1);
    if((j-1>-1) and number[i][j-1]!=-1)
        c= solve(number, i,j-1, n-1);
    if((j+1<3) and number[i][j+1]!=-1)
        d= solve(number, i,j+1, n-1);

    return dp[number[i][j]][n]= e+a+b+c+d;
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> number{{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    int num=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(n!=0 and number[i][j]!=-1)
            num += solve(number,i,j,n);
        }
    }
    cout<<num<<endl;
}