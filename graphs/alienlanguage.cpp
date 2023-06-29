//~ author      : DSB
#include <iostream>
#include <vector>
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

class Graph 
{
private:
    int numVertices; 
    vector<vector<int>> adjList;

public:   
    Graph(int vertices) 
    {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int vertice1, int vertice2) 
    {
        adjList[vertice1].push_back(vertice2);
    }

    void printGraph() 
    {
        for (int i = 0; i < numVertices; i++) 
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) 
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(vector<int> &visit, int i, string &ans)
    {
        visit[i]=1;
        for(auto j: adjList[i])
        {
            if(!visit[j])
            dfs(visit, j,ans);
        }

        char ch= i+ 'a';
        ans=  ch +ans;
    }

};

int main() 
{
    int n=5,k=4;
    Graph graph(k);
    vector<string> dict={"baa","abcd","abca","cab","cad"};
    for(int i=0;i<n-1;i++)
    {
        string curr= dict[i];
        string next= dict[i+1];
        int j= min(curr.size(),next.size());
        for(int k=0;k<j;k++)
        {
            if(curr[k]!=next[k])
            {
                graph.addEdge(curr[k]-'a',next[k]-'a');
                break;
            }
        }
    }

    graph.printGraph();

    vector<int> visit(k,0);
    string ans="";
    for(int i=0;i<k;i++)
    {
        if(!visit[i])
        {
            graph.dfs(visit,i,ans);
        }
    }
    cout<<ans<<endl;

    return 0;
}