#include <stdio.h>
#include <stdlib.h>


typedef struct _EDGE{
    int originVertex;
    int destinyVertex;
    int edgeWeight;
}Edge;


typedef struct _MINHEAP {
    Edge* array;
    int capacity;
    int size;
} MinHeap;

typedef struct _GRAPH {
    int V, E;
    Edge* edge;
} Graph;


Graph* createTemporaryGraph(int V, int E) {
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

    if (leftChild < heap->size && heap->array[leftChild].edgeWeight < heap->array[smallest].edgeWeight)
        smallest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild].edgeWeight < heap->array[smallest].edgeWeight)
        smallest = rightChild;

    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

void addHeapNode(MinHeap* heap, Edge* node) {
    if (heap->size >= heap->capacity) {
        /*printf("Heap is full. Cannot insert any more nodes.\n");*/
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = *node;

    while (i != 0 && heap->array[i].edgeWeight < heap->array[(i - 1) / 2].edgeWeight) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Edge removeMinNode(MinHeap* heap) {
    if (heap->size <= 0) {
        /*printf("Heap is empty. Cannot extract any node.\n");*/
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
    return edgeA->edgeWeight - edgeB->edgeWeight;
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
        edge->originVertex = graph->edge[i].originVertex;
        edge->destinyVertex = graph->edge[i].destinyVertex;
        edge->edgeWeight = graph->edge[i].edgeWeight;
        addHeapNode(heap, edge);
    }


    while (e < V - 1) {
        Edge minEdge = removeMinNode(heap);

        int rootSrc = find(parent, minEdge.originVertex);
        int rootDest = find(parent, minEdge.destinyVertex);

        if (rootSrc != rootDest) {
            result[e++] = minEdge;
            unionSets(parent, rootSrc, rootDest);
            totalWeight += minEdge.edgeWeight;
        }
    }

    free(heap->array);
    free(heap);
    free(parent);

    return totalWeight;
}

int main() {
    int V;  
    int E, i; 

    scanf("%d %d", &V, &E);

     Graph* graph = createTemporaryGraph(V, E);

    for(i = 0; i < E; i++){
        scanf("%d %d %d", 
                &(graph->edge[i].originVertex),
                &(graph->edge[i].destinyVertex),
                &(graph->edge[i].edgeWeight));
    }

    int totalWeight = kruskalMST(graph);

    printf("%d", totalWeight);

    free(graph->edge);
    free(graph);

    return 0;
}
