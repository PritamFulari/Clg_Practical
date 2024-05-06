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
    int distance;
    Node(int v, int d) : vertex(v), distance(d) {}
};

// Comparator function for priority queue
struct Comp
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.distance > b.distance;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>> &graph, int start)
{
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<Node, vector<Node>, Comp> pq;

    dist[start] = 0;
    pq.push(Node(start, 0));

    while (!pq.empty())
    {
        int u = pq.top().vertex;
        int distance = pq.top().distance;
        pq.pop();

        // If we've already found a better path, ignore this node
        if (distance > dist[u])
            continue;

        for (auto &[v, weight] : graph[u])
        {
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(Node(v, dist[v]));
            }
        }
    }

    // Print shortest distances from start vertex
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
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
        // For directed graph
        // graph[src].push_back({dest, weight});
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    // Call Dijkstra's algorithm
    dijkstra(graph, startVertex);

    return 0;
}

/*
Enter the number of vertices and edges: 5 7
Enter edges in the format: source destination weight
0 1 4
0 2 1
1 2 2
1 3 5
2 3 2
2 4 3
3 4 5
Enter the starting vertex: 0

*/