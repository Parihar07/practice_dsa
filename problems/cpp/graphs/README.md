# Graphs

Graph algorithms covering traversal, shortest paths, minimum spanning trees, and advanced topics.

## Key Concepts Covered
- Graph representations (adjacency list, matrix)
- Depth-First Search (DFS)
- Breadth-First Search (BFS)
- Shortest path algorithms (Dijkstra, Bellman-Ford)
- Minimum Spanning Tree (MST) - Kruskal's, Prim's
- Cycle detection (directed & undirected)
- Topological sorting
- Bipartite graph checking
- Articulation points and bridges
- Connected components

## Problems in this Directory

### Graph Basics
- [graphs_basics](graphs_basics/) - Graph fundamentals
- [graphs_build_adjacency_list_matrix](graphs_build_adjacency_list_matrix/) - Graph representations

### Bipartite Graphs
- [graph_bipartie](graph_bipartie/) - Bipartite graph detection
- [graph_check_biparte](graph_check_biparte/) - Check if bipartite
- [biprtiteGraph](biprtiteGraph/) - Bipartite graph
- [graph_edgestobipartie](graph_edgestobipartie/) - Edges to make bipartite
- [coloringGraph](coloringGraph/) - Graph coloring

### Cycle Detection
- [graph_cycledetectiondirectedgraph](graph_cycledetectiondirectedgraph/) - Cycle in directed graph
- [graphs_cycleindirectedgraph](graphs_cycleindirectedgraph/) - Cycle detection (directed)
- [graph_cycle_undirected_dfs](graph_cycle_undirected_dfs/) - Cycle in undirected graph
- [cycleInGraph](cycleInGraph/) - Cycle in graph
- [graph_cycle_bell_men_ford](graph_cycle_bell_men_ford/) - Negative cycle (Bellman-Ford)
- [graphs_bellmanford](graphs_bellmanford/) - Bellman-Ford algorithm

### Minimum Spanning Tree (MST)
- [graph_kruskal](graph_kruskal/) - Kruskal's MST algorithm
- [graph_prims_mst](graph_prims_mst/) - Prim's MST algorithm
- [graph_connecting_island_mst](graph_connecting_island_mst/) - Connecting islands MST
- [graph_construction_cost_mst](graph_construction_cost_mst/) - Construction cost MST
- [graph_damagedroad_mst](graph_damagedroad_mst/) - Damaged road MST
- [graph_damagedroads_prims_mst](graph_damagedroads_prims_mst/) - Damaged roads Prim's
- [graph_mstedges](graph_mstedges/) - MST edges
- [CommutableIslands](CommutableIslands/) - Commutable islands MST

### Topological Sorting
- [graph_toplogical_sort](graph_toplogical_sort/) - Topological sort
- [graph_topo_sort](graph_topo_sort/) - Topological sorting
- [topologicalSort2](topologicalSort2/) - Topological sort variant 2
- [topologySort](topologySort/) - Topology sort
- [graphs_course_problem](graphs_course_problem/) - Course prerequisite problem
- [PossibilityOfFinshing](PossibilityOfFinshing/) - Possibility of finishing courses

### Articulation Points & Bridges
- [graphs_articulation_point](graphs_articulation_point/) - Find articulation points
- [graphs_articulation_point_dfs](graphs_articulation_point_dfs/) - Articulation points DFS
- [graphs_bridges_dfs](graphs_bridges_dfs/) - Find bridges in graph
- [graphs_diameterofbridge](graphs_diameterofbridge/) - Diameter of bridge

### Island/Grid Problems
- [graphs_count_islands](graphs_count_islands/) - Island counting
- [graph_count_islands2](graph_count_islands2/) - Count islands variant
- [NoOfislands](NoOfislands/) - Number of islands
- [graphs_rottenorange](graphs_rottenorange/) - Rotten oranges (multi-source BFS)
- [rottenOrange](rottenOrange/) - Rotten orange problem

### Shortest Path
- [dijkstra](dijkstra/) - Dijkstra's algorithm
- [graph_short_distance_path](graph_short_distance_path/) - Shortest distance path
- [graph_lenghtofshortpath](graph_lenghtofshortpath/) - Length of shortest path
- [graph_min_distance_undire](graph_min_distance_undire/) - Min distance undirected
- [graphs_multiplesourcesdistance](graphs_multiplesourcesdistance/) - Multiple sources distance
- [MultiSourceLevel](MultiSourceLevel/) - Multi-source level
- [DistanceBwNodes](DistanceBwNodes/) - Distance between nodes

### Path Finding
- [graph_pathindirectedgraph](graph_pathindirectedgraph/) - Path in directed graph
- [PathInDirectedGraph](PathInDirectedGraph/) - Path in directed graph
- [graph_get_path_parenttable](graph_get_path_parenttable/) - Get path using parent table
- [graph_valid_path](graph_valid_path/) - Valid path checking

### Connectivity
- [graph_dfs_connectiedtowns](graph_dfs_connectiedtowns/) - Connected towns DFS
- [graph_dfs_ifconnected](graph_dfs_ifconnected/) - Check if connected
- [graph_count_components](graph_count_components/) - Count connected components
- [checkDistintionformSource](checkDistintionformSource/) - Check distinction from source

### DFS/BFS Applications
- [graphs_disc_end_time_dfs](graphs_disc_end_time_dfs/) - Discovery/end time DFS
- [graph_ifnodevisited](graph_ifnodevisited/) - Check if node visited

### Special Problems
- [graph_construct_roads](graph_construct_roads/) - Construct roads
- [graph_petrolbunkblast](graph_petrolbunkblast/) - Petrol bunk blast
- [graph_batchs2](graph_batchs2/) - Batches problem 2
- [graphs_batchs](graphs_batchs/) - Batches problem
- [AggressiveCows](AggressiveCows/) - Aggressive cows (binary search on graph)
- [AggresiveCows2](AggresiveCows2/) - Aggressive cows variant
- [ShaggyandDistances](ShaggyandDistances/) - Shaggy and distances

### Advanced Topics
- [trie_arrays](trie_arrays/) - Trie with arrays
- [unorderedmaps](unorderedmaps/) - Unordered maps in graphs
- [SocketProgramming](SocketProgramming/) - Socket programming

## Tips
- Choose the right representation for the problem
- DFS for connectivity, paths, cycles
- BFS for shortest paths in unweighted graphs
- Use visited array to avoid infinite loops
- Practice both recursive and iterative DFS
