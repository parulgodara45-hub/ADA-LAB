#include <iostream> 
#include <algorithm> 
using namespace std; 
 
#define V 4 
#define E 5 
 
struct Edge 
{ 
    int u, v, w; 
}; 
 
bool cmp(Edge a, Edge b) 
{ 
    return a.w < b.w; 
} 
 
// Disjoint Set (Union-Find) 
int parent[V]; 
 
int find(int i) 
{ 
    if (parent[i] == i) 
        return i; 
    return find(parent[i]); 
} 
 
void unite(int x, int y) 
{ 
    parent[x] = y; 
} 
 
int main() 
{ 
    Edge edges[E] = { 
        {0, 1, 10}, 
        {0, 2, 6}, 
        {0, 3, 5}, 
        {1, 3, 15}, 
        {2, 3, 4}}; 
 
    sort(edges, edges + E, cmp); 
 
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
 
    cout << "Edges in MST:\n"; 
 
    for (int i = 0; i < E; i++) 
    { 
        int u = find(edges[i].u); 
        int v = find(edges[i].v); 
 
        if (u != v) 
        { 
cout << edges[i].u << " - " << edges[i].v 
<< " : " << edges[i].w << endl; 
unite(u, v); 
} 
} 
return 0;
}