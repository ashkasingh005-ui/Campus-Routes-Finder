# Test Cases — Campus Route Finder (C)

Compile:
```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c -o campus_route_finder
```

| Test | Menu choice / input | Expected result |
|---|---|---|
| Display locations | `1` | Lists all eight locations |
| Display connections | `2` | Lists each location and its neighbours |
| Shortest route | `3`, source `1`, destination `8` | Prints a route with 3 edges |
| Direct route | `3`, source `1`, destination `2` | Main Gate -> Library; 1 edge |
| Unreachable destination | `3`, source `1`, destination `6` | Reports no route exists |
| DFS reachability | `4`, start `1` | Displays six locations in the first component |
| Connected components | `5` | Reports 2 connected components |
| Invalid location | `3`, source `0`, destination `8` | Displays invalid location message |
| Invalid menu choice | `9` | Displays invalid menu choice message |
| Exit | `6` | Displays exit message and ends |

## Example: shortest route
Input:
```text
3
1
8
```
Expected:
```text
Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab
Number of edges: 3
```

## Example: disconnected locations
Input:
```text
3
1
6
```
Expected:
```text
No route exists between Main Gate and Auditorium.
```
