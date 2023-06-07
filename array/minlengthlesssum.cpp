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
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int k;
    cin>>k;
    int start=0,end=0;
    int currsum=0;
    int minlen=n+1;
    while(end<n)
    {
        while(currsum<=k and end<n)
        {
            currsum+=v[end++];
        }

        while(currsum>k and start<n)
        {
            if(end-start<minlen)
            {
                minlen=end-start;
            }
            currsum -= v[start++]; 
        }
    }
    cout<<minlen<<endl;
}
int main()
{
// int t;
// cin>>t;
// for(int i=0;i<t;i++)
{
solve();
}
}