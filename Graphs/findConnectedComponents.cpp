/**
 * find all the connected components of an undirected graph.
   Using Dfs
 * O(V+E)  Time
 * O(V) space
 */ 
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int size;
    list<int>*adj;
    int componentCount;
    int *components;
public:
    Graph(int n)
    {
        size = n;
        adj = new list<int>[n];
        componentCount = 0;
        components =  new int[n];
    }
    ~Graph()
    {
        delete[] adj;
        delete[] components;
    }
    void addEdge(int src, int dst)
    {
        // directed graph
        adj[src].push_back(dst);
    }

    void DfsUtil(int v, bool visited[])
    {
        visited[v] = true;
        components[v] = componentCount;  
        // cout<<v<<" ";
        for(auto i : adj[v])
        {
            if(!visited[i])
            {
                DfsUtil(i, visited);
            }
        }
    }
    // connected components in graph
    void Dfs()
    {
        bool visited[size] = {false};
        for(auto i=0; i<size; i++)
        {
            if(!visited[i])
            {
                componentCount ++;
                DfsUtil(i, visited);
            }
        }
    }
    
    int getComponentCount()
    {
        Dfs();
        return componentCount; 
    }
    void getcomponets()
    {
        for(int i =0; i<size; i++)
        {
            cout<<i<<" "<<components[i]<<endl;
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(4,5);
    g.addEdge(5,6);    
   // g.Dfs();  // 0 4 5 6 1 3 2
    int k = g.getComponentCount();  // 3
    cout<<k<<endl;
    g.getcomponets(); // 0 1
                      // 1 2
                      // 2 2
                      // :
                      // 6 1
    // 0-4-5-6  => connected components in 1 cycle
    // 1-3 => connected 2nd cycle
    // 2-3 => 2 no edge connected to 3 so 3rd cycle
    return 0;
}
