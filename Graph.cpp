#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

#define MAX_CITIES 1000

// Struct to represent the graph node for a city (name and adjacency list)
struct City {
    string name;
    list<pair<int, int>> neighbors; // pair<neighbor_index, distance>
};

// Graph struct storing all cities and adjacency info
struct Graph {
    int cityCount;
    City cities[MAX_CITIES];
    unordered_map<string, int> cityIndexMap; // map city name to index for quick access

    // Initialize graph
    void init() {
        cityCount = 0;
    }

    // Add city to graph if not present, return its index
    int addCity(string cityName) {
        if (cityIndexMap.find(cityName) != cityIndexMap.end())
            return cityIndexMap[cityName];
        cities[cityCount].name = cityName;
        cityIndexMap[cityName] = cityCount;
        cityCount++;
        return cityCount - 1;
    }

    // Add bidirectional edge between two cities with given distance
    void addEdge(string fromCity, string toCity, int distance) {
        int u = addCity(fromCity);
        int v = addCity(toCity);
        cities[u].neighbors.push_back({v, distance});
        cities[v].neighbors.push_back({u, distance});
    }

    // BFS-based shortest path finder for unweighted or weighted graphs using distances as weights (Dijkstra could be used for weights, but here BFS with distances for simplicity)
    void shortestPath(string start, string end) {
        if (cityIndexMap.find(start) == cityIndexMap.end() || cityIndexMap.find(end) == cityIndexMap.end()) {
            cout << "One or both cities do not exist in the graph.\n";
            return;
        }

        int src = cityIndexMap[start];
        int dest = cityIndexMap[end];

        vector<int> dist(cityCount, INT32_MAX);
        vector<int> parent(cityCount, -1);
        dist[src] = 0;

        // Use priority queue for weighted graph shortest path (Dijkstra)
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int curDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (curDist > dist[u])
                continue;

            for (auto& nbr : cities[u].neighbors) {
                int v = nbr.first;
                int w = nbr.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[dest] == INT32_MAX) {
            cout << "No path found from " << start << " to " << end << ".\n";
            return;
        }

        cout << "Shortest distance from " << start << " to " << end << " is: " << dist[dest] << "\n";

        // Reconstruct path
        stack<int> pathStack;
        for (int at = dest; at != -1; at = parent[at])
            pathStack.push(at);

        cout << "Path: ";
        while (!pathStack.empty()) {
            cout << cities[pathStack.top()].name;
            pathStack.pop();
            if (!pathStack.empty())
                cout << " -> ";
        }
        cout << "\n";
    }

    // Print adjacency list (graph)
    void printGraph() {
        for (int i = 0; i < cityCount; i++) {
            cout << cities[i].name << " -> ";
            for (auto& nbr : cities[i].neighbors) {
                cout << "(" << cities[nbr.first].name << ", " << nbr.second << ") ";
            }
            cout << "\n";
        }
    }
};
