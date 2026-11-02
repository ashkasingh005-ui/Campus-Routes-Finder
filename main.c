#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define V 8
#define MAX_DEGREE 8
#define INPUT_SIZE 100

/* Campus Route Finder: undirected graph using an adjacency list. */
typedef struct {
    int neighbours[MAX_DEGREE];
    int count;
} AdjList;

typedef struct {
    char locations[V][20];
    AdjList adj[V];
} CampusGraph;

void addEdge(CampusGraph *campus, int u, int v) {
    if (u < 0 || u >= V || v < 0 || v >= V) return;
    if (campus->adj[u].count < MAX_DEGREE &&
        campus->adj[v].count < MAX_DEGREE) {
        campus->adj[u].neighbours[campus->adj[u].count++] = v;
        campus->adj[v].neighbours[campus->adj[v].count++] = u;
    }
}

void initializeGraph(CampusGraph *campus) {
    const char *names[V] = {
        "Main Gate", "Library", "Block 1", "Block 2",
        "Cafeteria", "Auditorium", "Parking", "Lab"
    };
    int i;

    memset(campus, 0, sizeof(*campus));
    for (i = 0; i < V; i++) {
        strcpy(campus->locations[i], names[i]);
    }

    /* Undirected campus paths. */
    addEdge(campus, 0, 1); /* Main Gate - Library */
    addEdge(campus, 0, 2); /* Main Gate - Block 1 */
    addEdge(campus, 1, 3); /* Library - Block 2 */
    addEdge(campus, 2, 3); /* Block 1 - Block 2 */
    addEdge(campus, 2, 4); /* Block 1 - Cafeteria */
    addEdge(campus, 3, 7); /* Block 2 - Lab */
    addEdge(campus, 4, 7); /* Cafeteria - Lab */
    addEdge(campus, 5, 6); /* Auditorium - Parking */
}

int readInteger(const char *prompt) {
    char input[INPUT_SIZE];
    char *end;
    long value;

    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return -1;
        }

        errno = 0;
        value = strtol(input, &end, 10);
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
            end++;
        }

        if (end != input && *end == '\0' && errno == 0 &&
            value >= -2147483647L && value <= 2147483647L) {
            return (int)value;
        }
        printf("Invalid input. Please enter a number.\n");
    }
}

void displayLocations(const CampusGraph *campus) {
    int i;
    printf("\n--- CAMPUS LOCATIONS ---\n");
    for (i = 0; i < V; i++) {
        printf("%d. %s\n", i + 1, campus->locations[i]);
    }
}

void displayConnections(const CampusGraph *campus) {
    int i, j;
    printf("\n--- CAMPUS CONNECTIONS ---\n");
    for (i = 0; i < V; i++) {
        printf("%s: ", campus->locations[i]);
        for (j = 0; j < campus->adj[i].count; j++) {
            printf("%s", campus->locations[campus->adj[i].neighbours[j]]);
            if (j + 1 < campus->adj[i].count) printf(", ");
        }
        printf("\n");
    }
}

int validLocation(int choice) {
    return choice >= 1 && choice <= V;
}

/* Breadth-First Search finds a minimum-edge route in an unweighted graph. */
void shortestRoute(const CampusGraph *campus, int sourceChoice, int destinationChoice) {
    int visited[V] = {0};
    int parent[V];
    int queue[V];
    int front = 0, rear = 0;
    int source, destination, i, current;
    int path[V], pathCount = 0;

    if (!validLocation(sourceChoice) || !validLocation(destinationChoice)) {
        printf("Invalid location number. Please choose 1-%d.\n", V);
        return;
    }

    source = sourceChoice - 1;
    destination = destinationChoice - 1;

    for (i = 0; i < V; i++) parent[i] = -1;

    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        current = queue[front++];
        if (current == destination) break;

        for (i = 0; i < campus->adj[current].count; i++) {
            int neighbour = campus->adj[current].neighbours[i];
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                parent[neighbour] = current;
                queue[rear++] = neighbour;
            }
        }
    }

    if (!visited[destination]) {
        printf("\nNo route exists between %s and %s.\n",
               campus->locations[source], campus->locations[destination]);
        return;
    }

    current = destination;
    while (current != -1 && pathCount < V) {
        path[pathCount++] = current;
        current = parent[current];
    }

    printf("\nShortest Route: ");
    for (i = pathCount - 1; i >= 0; i--) {
        printf("%s", campus->locations[path[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\nNumber of edges: %d\n", pathCount - 1);
}

/* Recursive DFS prints all vertices reachable from the selected vertex. */
void dfsVisit(const CampusGraph *campus, int vertex, int visited[]) {
    int i;
    visited[vertex] = 1;
    printf("%s\n", campus->locations[vertex]);

    for (i = 0; i < campus->adj[vertex].count; i++) {
        int neighbour = campus->adj[vertex].neighbours[i];
        if (!visited[neighbour]) {
            dfsVisit(campus, neighbour, visited);
        }
    }
}

void reachableLocations(const CampusGraph *campus, int startChoice) {
    int visited[V] = {0};

    if (!validLocation(startChoice)) {
        printf("Invalid location number. Please choose 1-%d.\n", V);
        return;
    }

    printf("\nLocations reachable from %s using DFS:\n",
           campus->locations[startChoice - 1]);
    dfsVisit(campus, startChoice - 1, visited);
}

void connectedComponents(const CampusGraph *campus) {
    int visited[V] = {0};
    int i, components = 0;

    printf("\n--- CONNECTED COMPONENTS ---\n");
    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            printf("\nComponent %d:\n", components);
            dfsVisit(campus, i, visited);
        }
    }
    printf("\nTotal connected components: %d\n", components);
}

int main(void) {
    CampusGraph campus;
    int choice;

    initializeGraph(&campus);

    do {
        printf("\n========== CAMPUS ROUTE FINDER (C) ==========\n");
        printf("1. Display campus locations\n");
        printf("2. Display graph connections\n");
        printf("3. Find shortest route (BFS)\n");
        printf("4. Find reachable locations (DFS)\n");
        printf("5. Display connected components\n");
        printf("6. Exit\n");

        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                displayLocations(&campus);
                break;
            case 2:
                displayConnections(&campus);
                break;
            case 3: {
                int source, destination;
                displayLocations(&campus);
                source = readInteger("Enter starting location number: ");
                destination = readInteger("Enter destination location number: ");
                shortestRoute(&campus, source, destination);
                break;
            }
            case 4: {
                int start;
                displayLocations(&campus);
                start = readInteger("Enter starting location number: ");
                reachableLocations(&campus, start);
                break;
            }
            case 5:
                connectedComponents(&campus);
                break;
            case 6:
                printf("Thank you for using Campus Route Finder!\n");
                break;
            case -1:
                printf("\nInput ended. Exiting program.\n");
                return 0;
            default:
                printf("Invalid menu choice. Please choose 1-6.\n");
        }
    } while (choice != 6);

    return 0;
}
