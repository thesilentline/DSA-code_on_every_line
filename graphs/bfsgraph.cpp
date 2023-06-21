#include <iostream>
#include<queue>
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
template <class t>              void printvector(vector<t>& v, long long n) {for0(i,n) {cout<<v[i]<<" ";} cout<<endl;}

using namespace std;

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

    vector<int> bfs(int v)
    {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> visit(v,0);
        visit[0]=1;
        while(!q.empty())
        {
            int front= q.front();
            q.pop();
            ans.push_back(front);
            for(auto i: adjList[front])
            {
                if(!visit[i])
                {
                    visit[i]=1;
                    q.push(i);
                }
            }
        }
        return ans;
    }

};

int main() 
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    vector<int> v;
    v= graph.bfs(5);

    for(auto i: v)
    cout<<i<<" ";

    return 0;
}