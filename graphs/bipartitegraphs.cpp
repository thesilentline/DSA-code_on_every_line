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

    void dfs(int src, int par, int color, vector<int> &visit_color, int &f)
    {
        visit_color[src]= color;
        for(auto i:adjList[src])
        {
            if(visit_color[i]==-1)
            {
                dfs(i,src,3-color,visit_color,f);
            }
            else if(src != par and color==visit_color[i])
            {
                f=1;
                break;
            }
        }
    }

    bool bipartite()
    {
        vector<int> visit_color(numVertices,-1);
        int f=0;
        dfs(0,0,1,visit_color,f);
        return f;
    }

};

int main() 
{
    Graph graph(10);

    graph.addEdge(7, 1);
    graph.addEdge(8, 4);
    graph.addEdge(8, 10);
    graph.addEdge(4, 7);
    graph.addEdge(6, 5);
    graph.addEdge(9, 3);
    graph.addEdge(3, 5);
    graph.addEdge(2, 5);
    graph.addEdge(2, 10);

    graph.printGraph();

    if(!graph.bipartite())
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}