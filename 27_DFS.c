#include <stdio.h>
#define MAX 10

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int node) {
    int i;
    printf("%d ", node);
    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n, i, j, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(graph, n, start);

    return 0;
}
