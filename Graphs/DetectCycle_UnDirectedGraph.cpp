/**
 * Detect cycle in UnDirected Grpah
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
public:
    Graph(int n)
    {
        size = n;
        adj = new list<int>[n];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int src, int dst)
    {
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    // Undirected Graph 
    bool DfsUtil(int v, bool visited[], int p)
    {
        visited[v] = true;
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                if(DfsUtil(i, visited, v))
                {
                    return true;
                }
            }
            // undirected graph, cycle is possible where back edge is eiher self node or 
            // node is one of the ancestor not a immediate parent(bcz undirected graph each vertix edge points both way)
            else if(i!=p)
            {
                return true;
            }
        }
        return false;
    }

    bool isCyclic()    
    {
        bool visited[size] = {false};
        // for disconnected Graph
        for(int i =0; i < size; i++)
        {
            if(!visited[i])
            {
                if(DfsUtil(i, visited, -1))
                {
                    return true;
                }
            }    
        }
        return false;
    }    
};

int main()
{
    Graph g1(4);    
    g1.addEdge(1,0);
    g1.addEdge(2,3);
    g1.addEdge(3,1);
    g1.addEdge(2,3);
    cout<< g1.isCyclic()<<endl; // 1        
    return 0;
}

