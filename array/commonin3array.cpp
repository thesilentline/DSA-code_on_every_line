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
    int n1;
    cin>>n1;
    vector<int> v1(n1);
    for(int i=0;i<n1;i++)
    cin>>v1[i];
    int n2;
    cin>>n2;
    vector<int> v2(n2);
    for(int i=0;i<n2;i++)
    cin>>v2[i];
    int i=0,j=0,t=0;
    while(i<n and j<n1 and t<n2)
    {
        if(v[i]==v1[j] and v1[j]==v2[t])
        {
            cout<<v[i]<<" ";
            i++;
            j++;
            t++;
        }
        else if(v[i]<v1[j])
        i++;
        else if(v1[j]<v2[t])
        j++;
        else
        t++;
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