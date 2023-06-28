//~ author      : DSB
#include <iostream>
#include <vector>
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
#define for0(i,n)               for(int i=1;i<n;i++)
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

    vector<int> mintime(int n)
    {
        vector<int> indegree(n,0);
        vector<int> time(n,0);
        queue<int> q;

        for(int i=0;i<n;i++)
        {
            for(auto j: adjList[i])
            {
                indegree[j]++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                time[i]=1;
            }
        }

        while(!q.empty())
        {
            int front= q.front();
            q.pop();
            for(auto i: adjList[front])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    time[i]= time[front]+1;
                    q.push(i);

                }
            }
        }

        return time;
    }

};

int main() 
{
    int n=11;
    Graph graph(n);

    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 8);
    graph.addEdge(2, 9);
    graph.addEdge(3, 6);
    graph.addEdge(4, 6);
    graph.addEdge(4, 8);
    graph.addEdge(5, 8);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(8, 10);

    graph.printGraph();

    vector<int> time;
    time= graph.mintime(n);

    printvector(time, time.size());



    return 0;
}