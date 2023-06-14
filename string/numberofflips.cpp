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
char flipch(char c)
{
    if(c=='0')
    return '1';
    else
    return '0';
}
int solve(string s, char current)
{
    int flip=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=current)
        flip++;
        current = flipch(current);
    }
    return flip;
}
int main()
{
// int t;
// cin>>t;
// for(int i=0;i<t;i++)
{
string s;
cin>>s;
int mm=solve(s,'0');
int nn=solve(s,'1');                                                                                               vvv
if(mm<nn)
cout<<mm<<endl;
else
cout<<nn<<endl;
}
}