//~ author      : DSB
#include<bits/stdc++.h>
#include<vector>
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
bool mycompare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    vector<pair<int,int> > final;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),mycompare);
    int start=v[0].first;
    int end=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first<end)
        {
            end=max(end,v[i].second);
            start=min(start,v[i].first);
            // cout<<start<<" "<<end<<endl;
        }
        else
        {
            final.push_back(make_pair(start,end));
            // cout<<start<<" "<<end<<endl;
            start=v[i].first;
            end=v[i].second;
        }
    }
    final.push_back(make_pair(start,end));
    for(int j=0;j<final.size();j++)
    {
        cout<<final[j].first<<" "<<final[j].second<<endl;
    }
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