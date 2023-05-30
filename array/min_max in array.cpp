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
struct Pair {
    int min;
    int max;
};
struct Pair minmaxp(vector<int> &v, int low, int high)
{
    struct Pair minmax, mml, mmr;
    if(low == high)
    {
        minmax.min= v[low];
        minmax.max= v[high];
        return minmax;
    }
    else if(low == high-1)
    {
        minmax.max=max(v[low],v[high]);
        minmax.min=min(v[low],v[high]);
        return minmax;
    }    
    else
    {
        int mid= (low+ high)/2;
        mml = minmaxp(v,low, mid);
        mmr = minmaxp(v, mid+1, high);
        minmax.min= min(mml.min,mmr.min);
        minmax.max = max(mml.max,mmr.max);
        return minmax;
    }
}
void solve()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    struct Pair ans;
    ans = minmaxp(v,0,n-1);
    cout<<ans.min<<"  "<<ans.max<<endl;
    printvector(v, n);
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