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
public:
    int numVertices; 
    vector<vector<int>> adjList;

   
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

    void addEdge2(int vertice1, int vertice2) 
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

    void dfs(int src,int par, int c, vector<int> &colour, int f)
    {
        colour[src]=c;
        for(auto i: adjList[src])
        {
            if(colour[i]==-1)
            {
                dfs(i,src,3-c,colour,f);
            }
            else if(i!=par and colour[i]==c)
            {
                f=0;
                return;
            }
        }
    }

    bool bipartite()
    {
        int f=1;
        vector<int> colour(numVertices,-1);
        dfs(0,0,1,colour,f);
        return f;
    }

};

int main() 
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    graph.printGraph();
    cout<<"\n\n";

    Graph reverse_graph(graph.numVertices);
    

    vector<int> dummy(graph.numVertices,0);
    for(int i=0;i<graph.numVertices; i++)
    {
        dummy[i]=1;
        for(auto j: graph.adjList[i])
        dummy[j]=1;

        for(int j=0;j<graph.numVertices;j++)
        {
            if(dummy[j]==0)
            reverse_graph.addEdge2(i,j);
            else
            dummy[j]=0;
        }

        // dummy.clear();
    }
    reverse_graph.printGraph();

    if(reverse_graph.bipartite())
    cout<<"two clique possible"<<endl;
    else
    cout<<"not possible"<<endl;




    return 0;
}