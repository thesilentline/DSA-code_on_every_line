//~ author      : DSB
#include <iostream>
#include <vector>
#include<unordered_set>
#include<queue>
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
    string start, end;
    cin>>start>>end;
    int wrdlen=3;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    unordered_set<string> words;
    vector<string> ans;
    for(int i=0;i<wordList.size();i++)
    words.insert(wordList[i]);

    queue<string> q;
    int len=0;
    if(words.find(end)==words.end())
    {
        cout<<0<<endl;
        return 0;
    }
    q.push(start);
    while(!q.empty())
    {
        len++;
        int qlen= q.size();
        for(int i=0;i<qlen;i++)
        {
            string front= q.front();
            q.pop();
            for(int j=0;j<wrdlen;j++)
            {
                char org= front[j];
                for(char ch='a';ch<='z';ch++)
                {
                    front[j]=ch;
                    if(front==end)
                    {
                        cout<<len+1<<endl;;
                        return 0;
                    }
                    if(words.find(front)==words.end())
                    continue;

                    words.erase(front);
                    q.push(front);
                }
                front[j]=org;
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}