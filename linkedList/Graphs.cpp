#include <bits/stdc++.h>

using namespace std;

void createAdjacencyMatrix(int n, int m)
{
    int adjMat[1000][1000] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    cout << "printing adjacency matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}
unordered_map<int, vector<int> > createAdjacencyList(int n, int m)
{

    vector<int> adjList[n + 1];
    unordered_map<int, vector<int> > mal;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        mal[u].push_back(v);
        mal[v].push_back(u);
    }

    cout << "printing adjacency list for vector" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":";
        for (auto x : adjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << "printing adjaceny list for map" << endl;
    for (auto i : mal)
    {
        cout << i.first << ":";
        for (auto x : i.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return mal;
}

void bfs(int n, unordered_map<int, vector<int> > adjMap)
{
    int vis[n];
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int f = q.front();
        cout << f << " ";
        q.pop();

        for (auto x : adjMap[f])
        {

            if (!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}
void dfs(int vis[], unordered_map<int, vector<int> > adjMap, int node)
{
    vis[node] = 1;
    cout << node << " ";

    for (auto x : adjMap[node])
    {
        if (!vis[x])
            dfs(vis, adjMap, x);
    }
}
unordered_map<int, vector<pair<int, int> > > createWeightedGraph(int n, int m)
{
    /*
    6 8
    1 2 2
    1 3 4
    2 3 1
    2 4 7
    3 5 3
    5 4 2
    4 6 1
    5 6 5
    */

    unordered_map<int, vector<pair<int, int> > > graph;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    return graph;
}

void dijkstraAlgo(unordered_map<int, vector<pair<int, int> > > &graph, int n, int m)
{

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    unordered_map<int, int> path;
    int source = 1, end = n;
    pq.push(make_pair(0, source));

    int distance[100];
    fill(distance, distance + 100, INT_MAX);
    distance[1] = 0;
    int minDistance = INT_MAX;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int dist = top.first;
        int node = top.second;
        if (node == end)
        {
            minDistance = dist;
            break;
        }
        for (auto x : graph[node])
        {

            int curDis = x.second;
            int curNode = x.first;

            if (dist + curDis < distance[curNode])
            {
                distance[curNode] = dist + curDis;
                path[curNode] = node;
                pq.push(make_pair(distance[curNode], curNode));
            }
        }
    }
    if (minDistance != INT_MAX)
    {
        cout << endl
             << "minDistance via dijkstra algorithm is : " << minDistance << endl;

        int curNode = end;
        stack<int> s;
        while (curNode != source)
        {
            s.push(curNode);
            curNode = path[curNode];
        }
        s.push(source);
        cout << "Path Taken was : ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    else
    {
        cout << endl
             << "No path was found" << endl;
    }
}

void bellmanFordAlgo(unordered_map<int, vector<pair<int, int> > > & graph, int n, int m) {

    /*
    graph for negative cycle
    4 5
    3 2 -10
    4 3 3
    1 4 5
    1 2 4
    2 4 5
    */
    int source = 1;
    vector<int> distance(n+1, INT_MAX);
    distance[1] = 0;
    int i;
    for(i = 1; i<=n;i++) {
        bool isChanged = false;

        for(int j=1;j<=n;j++) {
            for(auto[curNode, weight] : graph[j]) {
                
                if (distance[j] + weight < distance[curNode]) {
                    distance[curNode] = distance[j] + weight;
                    isChanged = true;
                }
            }
        }
        if (isChanged == false)
        break;

    }
    if (i > n){
        cout<<endl<<"There is a Negative cycle in the graph"<<endl;
        return;
    }
    cout<<endl<<"Belmann Ford Distance from 1 to all nodes is : ";
    for(int i=1;i<=n;i++) {
        cout<<"("<<i<<")"<<"->"<<distance[i]<<", ";
    }
    
}
void floydwarshallAlgo(unordered_map<int, vector<pair<int, int> > > & graph, int n, int m){
    /*
    4 7
    1 4 7
    1 2 3
    2 1 8
    2 3 2
    3 1 5
    3 4 1
    4 1 2
    */

    vector<vector<int> > mat(n+1, vector<int> (n+1,INT_MAX));
    for(int i=1;i<=n;i++) {
        mat[i][i] = 0;
    }

    for (auto [u, nodes] : graph) {
        for(auto [v , w] : nodes) {
            mat[u][v] = w;
        }
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && (mat[i][k] + mat[k][j] < mat[i][j])) {
                mat[i][j] = mat[i][k] + mat[k][j];

                }
            }
        }
    }
    cout<<endl<<"printing all pairs shortest path"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<"for node: "<<i<<" ->";
        for(int j=1;j<=n;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int find(vector<int> & parent, int node) {

    if (parent[node] != node) {
        return find(parent, parent[node]);
    }else {
        return node;
    }
}
void doUnion(vector<int> &parent, int a, int b) {

    parent[find(parent,b)] = find(parent, a);
}

bool validPathWithUnionFind(int n, vector<vector<int> >& edges, int source, int destination) {
    vector<int> parent(n);
    for(int i=0;i<n;i++) {
        parent[i] = i;
    }

    for (int i=0;i<edges.size();i++) {
        doUnion(parent, edges[i][0],edges[i][1]);
    }


    int sp = find(parent, source);
    int dp = find(parent, destination);

    if (sp == dp){
        return true;
    }

    return false;
}


int primsMininSpanningTree(vector<vector<int> >& points) {

    unordered_map<int, vector<pair<int,int> > > graph;
    int n = points.size();

    for (int i=0;i<n-1;i++) {
        for (int j = i+1; j<n;j++) {
            int x = points[i][0];
            int y = points[i][1];
            int x1 = points[j][0];
            int y1 = points[j][1];
            int val = abs(x - x1) + abs(y - y1);
    
            graph[i].push_back(make_pair(j, val));
            graph[j].push_back(make_pair(i, val));
        }
    }


    int mst = 0;
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >  pq;
    pq.push(make_pair(0, make_pair(0,-1)));
    vector<int> vis(n, 0);

    while(!pq.empty()) {
        pair<int, pair<int, int> > top = pq.top();
        pq.pop();
        int val = top.first;
        int node = top.second.first;
        int parent = top.second.second;
        if (!vis[node]) {
            vis[node] = 1;
            mst += val;
            for (auto [cnode,cval] : graph[node]) {
                if (!vis[cnode]) {
                    pq.push(make_pair(cval, make_pair(cnode,node)));
                }
            }
        }
    }


    return mst;

}
int main()
{

    int n, m;
    cin >> n >> m;
    // adjacency matrix representation
    //  createAdjacencyMatrix(n,m);
    bool weightedGraph = true;
    if (!weightedGraph)
    {
        unordered_map<int, vector<int> > adjMap = createAdjacencyList(n, m);

        // Graph Traversal
        // BFS
        cout << "doing BFS Traversal" << endl;
        bfs(n, adjMap);
        // DFS
        cout << "doing DFS Traversal" << endl;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        dfs(vis, adjMap, 1);
    }
    else
    {
        unordered_map<int, vector<pair<int, int> > > weightedGraph = createWeightedGraph(n, m);
        dijkstraAlgo(weightedGraph, n, m);
        bellmanFordAlgo(weightedGraph, n,m);
        floydwarshallAlgo(weightedGraph, n, m);
    }
}

/*
Graph Topics for Competitive Programming
1. Graph Representation & Input Handling
✅ Adjacency List (Most used, efficient for large graphs)✅
✅ Adjacency Matrix (Useful for dense graphs)✅
✅ Edge List (Used in Kruskal’s Algorithm)✅
✅ Implicit Graphs (Grids, String Transforms, Bitmask Graphs)
📌 Common Edge Cases:
0-based vs 1-based indexing
Handling large inputs efficiently (Fast I/O)
Self-loops & Multiple Edges
Disconnected Graphs & Single-node Graphs

2. Graph Traversal (Fundamental & Must-Know)
✅ Breadth-First Search (BFS) (Shortest path in an unweighted graph)✅
✅ Depth-First Search (DFS) (Connected components, cycle detection)✅
✅ 0/1 BFS (Shortest path in graphs with edge weights of 0 or 1)✅
✅ Dijkstra’s Algorithm (For weighted graphs, priority queue usage)✅
✅ Bellman-Ford Algorithm (Detecting negative cycles)✅
✅ Floyd-Warshall Algorithm (All-pairs shortest paths)✅
📌 Common Edge Cases:
Disconnected components
Negative weight cycles (Use Bellman-Ford)
Multiple shortest paths
Floating-point precision issues (For weighted graphs)

3. Shortest Path Algorithms (Critical for CP)✅
✅ BFS for Unweighted Graphs (Fastest way to find shortest path)✅
✅ Dijkstra’s Algorithm (Greedy Approach)✅
✅ Bellman-Ford Algorithm (Negative Weights Allowed)
✅ Floyd-Warshall Algorithm (All-Pairs Shortest Path, O(N³))✅
✅ A* Algorithm (Heuristic-based pathfinding, useful in AI & Games)
✅ 0/1 BFS (Deque Optimization for Faster Execution)
📌 Common Edge Cases:
Graph with multiple shortest paths
Handling negative weights correctly
Disconnected nodes (Infinity in distance array)

4. Cycle Detection (Must-Know for Contests)
✅ Undirected Graph Cycle Detection (DFS + Parent Check, Union-Find)✅
✅ Directed Graph Cycle Detection (DFS Recursion Stack, Kahn’s Algorithm)✅
✅ Cycle Detection in a Graph using Disjoint Set (Union-Find Approach)✅
✅ Detecting Negative Weight Cycles (Bellman-Ford Algorithm)✅
📌 Common Edge Cases:
Self-loops and multiple edges
Handling graphs with disconnected components
Cycle involving only a subset of nodes

5. Minimum Spanning Tree (MST) Algorithms
✅ Kruskal’s Algorithm (Greedy + Union-Find Approach)✅
✅ Prim’s Algorithm (Priority Queue-Based Approach)✅
📌 Common Edge Cases:
Disconnected graphs (Handle components separately)
Multiple valid MSTs (Consider lexicographically smallest one)
Large number of edges (Use adjacency list instead of adjacency matrix)

6. Topological Sorting (Critical for DAG Problems)
✅ Kahn’s Algorithm (BFS-Based Topological Sorting)✅
✅ DFS-Based Topological Sorting✅
✅ Cycle Detection in a Directed Graph Using Topological Sort✅
📌 Common Edge Cases:
Multiple valid topological orderings
Graph with cycles (Not a DAG, return failure)

7. Strongly Connected Components (SCCs) & Condensation Graph
✅ Kosaraju’s Algorithm (2-pass DFS)(will use Kosaraju’s algorithm)✅
✅ Tarjan’s Algorithm (DFS-based, Low-Link Values) 
✅ Condensation Graph (Compressing SCCs into a DAG for further processing)
📌 Common Edge Cases:
Graph already strongly connected
Graph with self-loops forming SCCs

8. Graph Coloring (Used in Competitive Problems like Bipartiteness Check)
✅ Bipartite Graph Check using BFS/DFS
✅ Graph M-Coloring Problem (Backtracking)
📌 Common Edge Cases:
Odd-length cycles (Not bipartite)
Disconnected graph components

9. Eulerian Path & Circuit (Common in CP Graph Problems)
✅ Eulerian Path vs Eulerian Circuit (Degree Conditions)
✅ Hierholzer’s Algorithm (Finding Eulerian Circuit in O(E))
📌 Common Edge Cases:
Disconnected components
Graph with exactly two vertices of odd degree (Eulerian Path exists but not a circuit)

10. Network Flow (Important for Advanced CP Problems)
✅ Ford-Fulkerson Algorithm (Max Flow via Augmenting Paths)
✅ Edmonds-Karp Algorithm (BFS-based Max Flow, O(VE²))
✅ Dinic’s Algorithm (Optimized Max Flow, O(V²E))
✅ Bipartite Matching using Max Flow
📌 Common Edge Cases:
Graph with multiple sources & sinks
Capacity constraints & large input sizes

11. Tree Algorithms (Essential for CP Problems with Trees as Graphs)
✅ Lowest Common Ancestor (LCA) using Binary Lifting
✅ Tree Diameter using BFS/DFS
✅ Heavy-Light Decomposition (Path Queries in Trees)
✅ Centroid Decomposition (Tree Queries Optimization)
✅ Euler Tour Technique (Flattening a Tree for Efficient Queries)
📌 Common Edge Cases:
Rooted vs Unrooted Trees
Handling queries on subtree nodes efficiently

12. Special Graph Algorithms (Occasionally Asked in CP Contests)
✅ Meet-in-the-Middle Search (Bidirectional BFS for Shortest Paths)
✅ Hopcroft-Karp Algorithm (Maximum Bipartite Matching in O(√V * E))
✅ Karger’s Algorithm (Minimum Cut using Randomized Contractions)
📌 Common Edge Cases:
Handling large inputs efficiently (Use appropriate data structures)

13. Grid-Based Graph Problems (Frequently Asked in CP Contests)
✅ Flood Fill Algorithm (Connected Components in a Grid)
✅ Lee Algorithm (Shortest Path in a Grid using BFS)
✅ Knight’s Tour Problem (Graph Representation of Chessboard)
✅ A Algorithm (Optimized Pathfinding in a Grid)*
📌 Common Edge Cases:
Handling obstacles in the grid
Multiple valid shortest paths in a grid
*/