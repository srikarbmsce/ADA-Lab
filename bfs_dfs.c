#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1, rear = -1;
int n;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("\nBFS: ");
    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(start);

    return 0;
}
