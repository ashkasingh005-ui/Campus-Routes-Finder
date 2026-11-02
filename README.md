# Campus Route Finder (C Language)

A menu-driven **C Data Structures and Algorithms mini-project** that models a college campus as an undirected graph. It uses an adjacency list, Breadth-First Search (BFS), and Depth-First Search (DFS).

## Features
1. Display all campus locations.
2. Display connections between locations.
3. Find a shortest route using BFS.
4. Display reachable locations using DFS.
5. Find connected components.
6. Validate user input and handle unreachable destinations.

## Campus locations
| No. | Location |
|---:|---|
| 1 | Main Gate |
| 2 | Library |
| 3 | Block 1 |
| 4 | Block 2 |
| 5 | Cafeteria |
| 6 | Auditorium |
| 7 | Parking |
| 8 | Lab |

There are 8 vertices and 8 undirected edges. Auditorium and Parking form a separate connected component.

## Technologies and concepts
- Language: C (C99)
- Data structure: Graph using adjacency list
- Algorithms: BFS, DFS, connected components
- Other concepts: arrays, structures, queue, recursion, functions
- External libraries: None

## Compile and run

### Windows (MinGW GCC)
```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c -o campus_route_finder.exe
.\campus_route_finder.exe
```

### Linux / macOS
```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c -o campus_route_finder
./campus_route_finder
```

## Menu
```text
1. Display campus locations
2. Display graph connections
3. Find shortest route (BFS)
4. Find reachable locations (DFS)
5. Display connected components
6. Exit
```

## Example
Choose option `3`, source `1`, destination `8`:
```text
Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab
Number of edges: 3
```
The route is one of the possible shortest routes. BFS guarantees the minimum number of edges.

## Complexity
Let V be vertices and E be edges:
| Operation | Time complexity | Auxiliary space |
|---|---:|---:|
| Display locations | O(V) | O(1) |
| BFS shortest route | O(V + E) | O(V) |
| DFS traversal | O(V + E) | O(V) |
| Connected components | O(V + E) | O(V) |
| Adjacency-list storage | — | O(V + E) |

## Project files
- `main.c` — complete C source code
- `Project_Report.md` — project report
- `TEST_CASES.md` — test inputs and expected results
- `Makefile` — optional GCC build commands
- `.gitignore` — ignores compiled output and editor files

## Author
**Ashka Singh**  
B.Tech CSE | Section A | Roll No. 2556438

## Reference
The project uses the general graph-based campus navigation idea from the reference repository: https://github.com/vanshikat549-cpu/Campus-Route-Finder. This folder contains a separate implementation written in C.
