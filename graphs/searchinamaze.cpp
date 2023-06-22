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
        adjList[vertice2].push_back(vertice1);
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

    void dfs(int i, int j, vector<vector<int>> &m, int n, vector<vector<int>> visit, vector<vector<int>> &ans)
    {
        if(i<0 or j<0 or i>n-1 or j>n-1)
        return;

        if(m[i][j]==0 or visit[i][j]==1)
        return;

        if(i==n-1 and j==n-1)
        {
            for(auto t: ans)
            {
                for(auto q: ans[i])
                cout<<q<<" ";
                cout<<endl;
            }
            return;
        }
        visit[i][j]=1;
        ans[i][j+1]=1;
        dfs(i,j+1,m,n,visit,ans);
        dfs(i+1,j,m,n,visit,ans);
        visit[i][j]=0;
    }

};

int main() 
{
    Graph g(5);
    string s="";
    vector<vector<int>> m = { { 1, 0, 0, 0 },
                              { 1, 1, 0, 1 },
                              { 0, 1, 0, 0 },
                              { 1, 1, 1, 1 } };
    int max= 4;

    vector<vector<int>> visit(max,vector<int>(max));
    if(m[0][0]==0)
    cout<<s<<endl;
    if(m[max-1][max-1]==0)
    cout<<s<<endl;
    vector<vector<int>> ans(max,vector<int>(max));
    g.dfs(0,0,m,max,visit,ans);

    return 0;
}