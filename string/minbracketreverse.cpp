//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<stack>
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
    string exp;
    cin>>exp;
    int count=0;
    stack <int> s;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='}' and !s.empty())
        {
            if(s.top()=='{')
            s.pop();
        }
        else
        {
            s.push(exp[i]);
        }
    }
    int red_len=s.size();
    int n=0;
    while(!s.empty() and s.top()=='{')
    {
        s.pop();
        n++;
    }
    cout<<(red_len/2 + n%2)<<endl;
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