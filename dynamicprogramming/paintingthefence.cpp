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

int solve(int n,int k)
{
    if(n==1)
    return k;

    if(n==0)
    return 0;

    int same= k;
    int diff= (k-1)* k;

    for(int i=3;i<=n;i++)
    {
        int prev= diff;
        diff= same *(k-1) + diff*(k-1);
        same= prev;
    }
    return same+diff;
}


int main()
{
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;

}