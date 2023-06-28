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
    int n;
    cin>>n;
    Graph graph(n);

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph.addEdge(b,a);
    }

    graph.printGraph();

    vector<int> visit(n,0);
    vector<int> order(n,0);
    if(graph.solve(0,visit,order)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;


    return 0;
}