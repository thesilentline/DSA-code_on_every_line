//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<string>
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
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
void solve()
{
    string s;
    cin>>s;

    int maxl=0;
    int start=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++)
        {
            int flag=1;
            for(int k=0;k<(j-i+1)/2;k++)
            {
                if(s[i+k] != s[j-k])
                    {
                        flag=0;
                    }

                if(flag==1 && (j-i+1)>maxl)
                {
                    start=i;
                    maxl=j-i+1;
                }
            }
        }
    }
    printSubStr(s, start, start + maxl - 1);
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





