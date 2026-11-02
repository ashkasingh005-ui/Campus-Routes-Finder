# PROJECT REPORT
# CAMPUS ROUTE FINDER (C LANGUAGE)

## Student Details
- **Name:** Ashka Singh
- **Roll Number:** 2556438
- **Branch:** Computer Science and Engineering (CSE)
- **Section:** A
- **Subject:** Data Structures and Algorithms

## 1. Introduction
Campus Route Finder is a menu-driven C application that represents a college campus as an undirected graph. Each campus location is a vertex, and each path between two locations is an edge. The project uses graph traversal algorithms to explore campus connections and find a shortest route.

## 2. Problem Statement
A campus contains buildings and facilities connected by paths. The objective is to represent these places using a graph and provide operations to display locations, view connections, find a shortest route, explore reachable places, and identify separate connected groups.

## 3. Objectives
1. Represent campus locations using a graph.
2. Implement the graph using an adjacency list.
3. Apply BFS to find the shortest route in an unweighted graph.
4. Apply DFS to explore reachable locations.
5. Identify connected components.
6. Understand arrays, structures, queues, recursion, and graph traversal in C.

## 4. Software and Hardware Requirements
**Software:** GCC/MinGW C compiler, VS Code or another C IDE, Windows/Linux/macOS.  
**Hardware:** A computer capable of running a C compiler, keyboard, and display.

## 5. Data Structure Used
The project uses an **undirected adjacency-list graph**. A structure stores the neighbours of each vertex. The campus location names are stored in a character array.

### Vertices
| Vertex | Location |
|---:|---|
| 1 | Main Gate |
| 2 | Library |
| 3 | Block 1 |
| 4 | Block 2 |
| 5 | Cafeteria |
| 6 | Auditorium |
| 7 | Parking |
| 8 | Lab |

### Edges
- Main Gate — Library
- Main Gate — Block 1
- Library — Block 2
- Block 1 — Block 2
- Block 1 — Cafeteria
- Block 2 — Lab
- Cafeteria — Lab
- Auditorium — Parking

Every edge is stored in both vertices' adjacency lists because the graph is undirected.

## 6. Algorithms

### Breadth-First Search (BFS)
BFS explores vertices level by level using a queue. In an unweighted graph, it finds a route with the minimum number of edges. A parent array records the previous vertex so the route can be reconstructed.

**Steps:**
1. Mark all vertices unvisited and initialize parent values to -1.
2. Insert the source vertex into the queue and mark it visited.
3. Remove the front vertex from the queue.
4. Add each unvisited neighbour to the queue and record its parent.
5. Continue until the destination is reached or the queue is empty.
6. Reconstruct and print the route using the parent array.

### Depth-First Search (DFS)
DFS explores one branch as far as possible before backtracking. This project uses recursive DFS to display all locations reachable from a selected point.

**Steps:**
1. Mark the current vertex visited.
2. Display its location.
3. Visit every unvisited neighbour recursively.
4. Stop when all reachable vertices have been visited.

### Connected Components
The program checks every vertex. Whenever it finds an unvisited vertex, it starts a DFS and counts a new component. The sample campus graph has two components:
- Main Gate, Library, Block 1, Block 2, Cafeteria, Lab
- Auditorium, Parking

## 7. Features
1. Display campus locations.
2. Display direct connections of each location.
3. Find a minimum-edge route using BFS.
4. Display reachable locations using DFS.
5. Display connected components.
6. Exit the application.

## 8. Complexity Analysis
Let V be the number of vertices and E be the number of edges.

| Operation | Time Complexity | Auxiliary Space |
|---|---:|---:|
| Display locations | O(V) | O(1) |
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |
| Connected components | O(V + E) | O(V) |
| Adjacency list | — | O(V + E) |

## 9. Sample Output
For a route from Main Gate (1) to Lab (8):
```text
Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab
Number of edges: 3
```
For a route from Main Gate (1) to Auditorium (6):
```text
No route exists between Main Gate and Auditorium.
```
The connected-components option reports two components.

## 10. Advantages
- Demonstrates a practical graph application.
- BFS finds a minimum-edge route in an unweighted graph.
- DFS explores connected locations.
- Adjacency lists store only actual connections.
- The menu makes the application simple to use.

## 11. Limitations
- Locations and connections are predefined.
- All paths are treated as having equal cost.
- The shortest route is based on edge count, not actual distance or travel time.
- The program is console-based and has no graphical map.

## 12. Future Scope
- Allow users to add or remove locations.
- Store actual distances or travel times.
- Use Dijkstra's algorithm for weighted shortest paths.
- Add a graphical campus map.
- Save campus data in a file or database.

## 13. Conclusion
Campus Route Finder demonstrates how a graph can model real campus connections. BFS finds a shortest route in an unweighted graph, while DFS is used for reachability and connected-component detection. The project provides practical understanding of graphs, adjacency lists, queues, recursion, and algorithm complexity in C.

## 14. Reference
General campus navigation concept: https://github.com/vanshikat549-cpu/Campus-Route-Finder
