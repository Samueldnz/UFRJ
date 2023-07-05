#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int src, dest, weight;
} Edge;


typedef struct {
    Edge* array;
    int capacity;
    int size;
} MinHeap;

typedef struct {
    int V, E;
    Edge* edge;
} Graph;


Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}


MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (Edge*)malloc(capacity * sizeof(Edge));
    return heap;
}


void swapNodes(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->array[leftChild].weight < heap->array[smallest].weight)
        smallest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild].weight < heap->array[smallest].weight)
        smallest = rightChild;

    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}


void insertHeapNode(MinHeap* heap, Edge* node) {
    if (heap->size >= heap->capacity) {
        printf("Heap is full. Cannot insert any more nodes.\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = *node;

    while (i != 0 && heap->array[i].weight < heap->array[(i - 1) / 2].weight) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Edge extractMinNode(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty. Cannot extract any node.\n");
        Edge emptyEdge = {-1, -1, -1};
        return emptyEdge;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    Edge minNode = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return minNode;
}


int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}


int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    parent[rootX] = rootY;
}


int kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];  
    int e = 0;  
    int i = 0;
    int v;
    int totalWeight = 0;  

  
    qsort(graph->edge, graph->E, sizeof(Edge), compareEdges);


    int* parent = (int*)malloc(V * sizeof(int));
    for (v = 0; v < V; v++)
        parent[v] = -1;


    MinHeap* heap = createMinHeap(graph->E);

    
    for (i = 0; i < graph->E; i++) {
        Edge* edge = (Edge*)malloc(sizeof(Edge));
        edge->src = graph->edge[i].src;
        edge->dest = graph->edge[i].dest;
        edge->weight = graph->edge[i].weight;
        insertHeapNode(heap, edge);
    }


    while (e < V - 1) {
        Edge minEdge = extractMinNode(heap);

        int rootSrc = find(parent, minEdge.src);
        int rootDest = find(parent, minEdge.dest);

    
        if (rootSrc != rootDest) {
            result[e++] = minEdge;
            unionSets(parent, rootSrc, rootDest);
            totalWeight += minEdge.weight;
        }
    }

    free(heap->array);
    free(heap);
    free(parent);

    return totalWeight;
}

int main() {
    int V = 4;  
    int E = 5;  
    Graph* graph = createGraph(V, E);


    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    int totalWeight = kruskalMST(graph);

    printf("Peso da Árvore Mínima de Extensão: %d\n", totalWeight);

    free(graph->edge);
    free(graph);

    return 0;
}
