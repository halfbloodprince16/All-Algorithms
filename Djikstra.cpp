#include"bits/stdc++.h"
using namespace std;



int minDistance(int dist[], bool sptSet[], int V) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 

    return min_index; 
} 

// A utility function to print the constructed distance array 
int printSolution(int dist[],int V,int src) 
{
    std::vector<int>v;
    std::vector<int>::iterator itr;

    for (int i = 0; i < V; i++) 
    {
        if(dist[i] == INT_MAX)
        {
            cout<<"-1"<<" ";
        }
        else if(src != i)
        {
            cout<<dist[i]<<" ";
        }
    }
    cout<<endl;

    return 0;
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[100][100], int src, int V) 
{ 
    int dist[V]; // The output array. dist[i] will hold the shortest 
    // distance from src to i 

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 

    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 

    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet, V); 

        // Mark the picked vertex as processed 
        sptSet[u] = true; 

        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 

            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 

    // print the constructed distance array 
    printSolution(dist,V,src); 
} 

// driver program to test above function 
int main() 
{ 
     
    int t,n,m,i,j,u,v,w;
    cin>>t;
    cin>>n>>m;
    int graph[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }


//everything under one test case;

    while(m)
    {
        cin>>u>>v>>w;
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
        m--;
    }
    int src;
    cin>>src;
    src--;
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    dijkstra(graph,src,n);
    return 0; 
} 
