//7	
//Consider the undirected graph G, consisting of n nodes laid out in a 
//3 -by- 3 grid: Start searching at node 1, and break ties for exploring the next node 
//based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). 
//(a) In what order are nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS?
	


#include <stdio.h>
#define SIZE 9

int adj[SIZE+1][SIZE+1];   // Adjacency matrix
int visited[SIZE+1];

// Queue for BFS
int queue[SIZE+1], front = -1, rear = -1;

// Stack for DFS
int stack[SIZE+1], top = -1;

// Function to add edge in graph
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Enqueue operation for BFS
void enqueue(int value) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Push operation for DFS
void push(int value) {
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// BFS traversal
void BFS(int start) {
    for (int i = 1; i <= SIZE; i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Order: ");
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 1; i <= SIZE; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// DFS traversal
void DFS(int start) {
    for (int i = 1; i <= SIZE; i++) visited[i] = 0;
    push(start);

    printf("\nDFS Order: ");
    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for (int i = SIZE; i >= 1; i--) {
                if (adj[node][i] == 1 && visited[i] == 0)
                    push(i);
            }
        }
    }
}

// Main Function
int main() {
    // Connect the graph as a 3x3 grid
    addEdge(1, 2); 
    addEdge(1, 4);
    addEdge(2, 3); 
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(4, 5); 
    addEdge(5, 6); 
    addEdge(6, 9);
    addEdge(7, 8);
    addEdge(8, 9);

    BFS(1);
    DFS(1);
    return 0;
}
