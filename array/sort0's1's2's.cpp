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

//Dutch National Flag problem. The problem was proposed by Edsger Dijkstra.

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        switch(v[mid])
        {
            case 0:
                swap(v[low++],v[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(v[mid],v[high--]);
                break;
        }
    }
    printvector(v,n);
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