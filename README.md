
# 🗺️ Google Maps Simulation using Graphs (DSA Project)

This project simulates a basic version of Google Maps using **graphs** in C++. It supports adding cities as nodes, connecting them with distances, and finding the shortest path using **Dijkstra’s Algorithm**.

## 📂 Files

- `graph.cpp` → Contains the full graph implementation using adjacency lists and Dijkstra's algorithm.
- `main.txt` → Used to test the project (contains a sample setup).
- `README.md` → This file!

## ⚙️ Features

- Add cities and roads with distances
- Print graph structure
- Find the **shortest path** between any two cities
- Output the total distance and actual path

## 🧪 Sample Input (from `main.txt`)

```cpp
Graph g;
g.init();

g.addEdge("Delhi", "Noida", 10);
g.addEdge("Delhi", "Gurgaon", 20);
g.addEdge("Noida", "Greater Noida", 15);
g.addEdge("Gurgaon", "Faridabad", 25);
g.addEdge("Greater Noida", "Faridabad", 30);

g.printGraph();

g.shortestPath("Delhi", "Faridabad");
```

## ✅ Expected Output

```
Delhi -> Noida (10), Gurgaon (20)
Noida -> Greater Noida (15)
Gurgaon -> Faridabad (25)
Greater Noida -> Faridabad (30)
Faridabad -> 

Shortest distance from Delhi to Faridabad is: 45
Path: Delhi -> Gurgaon -> Faridabad
```

## 🧠 Algorithms Used

- **Graph Representation**: Adjacency List using arrays and linked lists
- **Shortest Path**: Dijkstra's algorithm using a **priority queue**

## 📌 Notes

- The project follows **DSA course conventions** using procedural programming and `struct`s.
- The graph is initialized using `Graph::init()`.
- STL containers like `unordered_map` and `list` are used internally for performance.
- Avoids use of full-fledged OOP to maintain simplicity and focus on DSA concepts.

## 💻 Requirements

- **C++11 or higher**
- Any standard C++ compiler: `g++`, `clang++`, MSVC, etc.

## 📬 Author

**Yashraj Omar**  
B.Tech. Electrical Engineering  
IIT Ropar  
