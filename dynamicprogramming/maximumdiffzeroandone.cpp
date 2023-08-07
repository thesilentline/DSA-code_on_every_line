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
int main()
{
    string s;
    cin>>s;
    int maxsum=0;
    int m=INT_MIN;
    for(int i=0;i<s.size();i++)
    {
        int x= (s[i]=='0')?1:-1;
        maxsum+=x;
        if(maxsum>m) m=maxsum;
        if(maxsum<0) maxsum=0;
    }
    cout<<m<<endl;
}