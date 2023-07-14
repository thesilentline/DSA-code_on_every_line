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
    int time;
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

    void dfs(vector<int> &intime, vector<int> &outtime, int src, int par)
    {
        
        intime[src]=time++;
        for(auto i: adjList[src])
        {
            if(i!=par)
            dfs(intime,outtime,i,src);
        }
        outtime[src]=time++;
    }

    bool check_subtree(vector<int> &intime, vector<int> &outtime,int x, int y)
    {
        if(intime[x]<intime[y] and outtime[x]>outtime[y])
        return true;
        else return false;
    }

};

int main() 
{
    Graph graph(10);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 6);
    graph.addEdge(2, 7);
    graph.addEdge(6, 9);
    graph.addEdge(7, 8);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.printGraph();

    

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        graph.time=1;
        int c,x,y;
        cin>>c>>x>>y;
        vector<int> intime(10,0);
        vector<int> outtime(10,0);
        vector<int> visit(10,0);
        graph.dfs(intime,outtime,1,0);

        if(!graph.check_subtree(intime,outtime,x,y) and !graph.check_subtree(intime,outtime,y,x))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(graph.check_subtree(intime,outtime,x,y) and c==0)
            cout<<"YES"<<endl;
            else if(graph.check_subtree(intime,outtime,y,x) and c==1)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }





    return 0;
}