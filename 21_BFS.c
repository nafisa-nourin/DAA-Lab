#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("BFS Traversal: ");
    bfs(graph, n, start);

    return 0;
}