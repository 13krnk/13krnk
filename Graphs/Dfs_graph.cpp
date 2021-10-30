/**
 * DFS - Depth first search 
 * For connected and Disconncted Graph USing Recursion.
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
        // directed graph
        adj[src].push_back(dst);
    }

    void DfsUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout<<v<<" ";
        for(auto i : adj[v])
        {
            if(!visited[i])
            {
                DfsUtil(i, visited);
            }
        }
    }
    // Grpah for connected and disconnected nodes.
    void Dfs()
    {
        cout<<"Disconnected Graph"<<endl;
        bool visited[size] = {false};
        for(auto i=0; i<size; i++)
        {
            if(!visited[i])
            {
                DfsUtil(i, visited);
            }
        }
    }
    
    // Only for connected nodes in a graph.
    #if 0
    void Dfs_Connected(int v)
    {
        cout<<"Connected Graph"<<endl;
        bool visited[size] = {false};
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                DfsUtil(i, visited);
            }
        }
    }
    #endif

    void Dfs_iterative(int i)
    {
        stack<int>s;
        bool visited[size] = {false};
        visited[i] = true;
        s.push(i);
        while(!s.empty())
        {
            int tp = s.top();
            cout<<tp<<" ";
            s.pop();
            for(auto i : adj[tp])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
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
    g.Dfs_iterative(0);   // 0 4 5 6
    //g.Dfs_Connected(0);
    g.Dfs();  // 0 4 5 6 1 3 2
    return 0;
}
