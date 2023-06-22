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

    void addEdgeundirected(int vertice1, int vertice2) 
    {
        adjList[vertice1].push_back(vertice2);
        adjList[vertice2].push_back(vertice1);
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

    bool solve(int src,vector<int> &visit, vector<int> &order)
    {
        visit[src]=1;
        order[src]=1;
        for(auto i: adjList[src])
        {
            if(!visit[i])
            {
                bool c= solve(i, visit, order);
                if(c==true)
                return true;
            }
            else if(order[i])
            return true;
        }
        order[src]=0;
        return false;
    }

};

int main() 
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    g.printGraph();
    vector<int> visit(6,0);
    vector<int> order(6,0);
    for(int i=0;i<6;i++)
    {
        if(!visit[i])
        {
            bool c= g.solve(i,visit,order);
            if(c==true)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}