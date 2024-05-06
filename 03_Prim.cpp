#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

// Structure to represent a node in the graph
struct Node
{
    int vertex;
    int weight;
    Node(int v, int w) : vertex(v), weight(w) {}
};

// Comparator function for priority queue
struct Comp
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.weight > b.weight;
    }
};

// Function to perform Prim's algorithm
void prim(vector<vector<pair<int, int>>> &graph, int start)
{
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    priority_queue<Node, vector<Node>, Comp> pq;

    dist[start] = 0;
    pq.push(Node(start, 0));

    while (!pq.empty())
    {
        int u = pq.top().vertex;
        pq.pop();
        visited[u] = true;

        for (auto &[v, weight] : graph[u])
        {
            if (!visited[v] && weight < dist[v])
            {
                dist[v] = weight;
                parent[v] = u;
                pq.push(Node(v, weight));
            }
        }
    }

    // Print the MST
    for (int i = 1; i < V; ++i)
    {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << dist[i] << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create graph representation
    vector<vector<pair<int, int>>> graph(V);
    cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < E; ++i)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight}); // For undirected graph
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    // Call Prim's algorithm
    prim(graph, startVertex);

    return 0;
}
