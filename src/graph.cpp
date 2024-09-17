#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

/*
    @brief Creates a graph from the given edge list
    @param edges Adjacency list
    @return Root of graph

    Each vector<int> in edges is an edge between two nodes.

    TODO: Change to vector<pair<int, int>>
*/
GraphNode* CreateGraph(const vector<vector<int>>& edges) {

    if (edges.size() == 0) {
        cerr << "Cannot make graph from empty list\n";
        exit(0);
    }

    set<int> values;
    map<int, GraphNode*> nodes;
    

    // Init the unique set of all variables
    for (vector<int> link : edges) {
        values.insert(link[0]);
        values.insert(link[1]);
    }

    // Create nodes for each variable
    for (int val : values) {
        GraphNode* node = new GraphNode(val);
        nodes.insert({val, node});

        allocatedGraphNodes.push_back(node);
    }

    // Make the neighbours list
    for (vector<int> link : edges) 
        nodes[link[0]]->neighbors.push_back(nodes[link[1]]);
    

    return nodes[edges[0][0]];
}


/*
    @brief Driver for performing a DFS on the given graph
    @param root Node to start the DFS from
*/
void G_DFS(const GraphNode* root) {
    set<const GraphNode*> visited;
    G_DFS(root, visited);
}


/*
    @brief Actually performs the DFS
    @param node Node currently being visited
    @param visited Adjacency list
*/
void G_DFS(const GraphNode* node, set<const GraphNode*>& visited) {

    if (node == nullptr || visited.count(node) == 1)
        return;

    // Mark the node as visited
    visited.insert(node);

    // Process the current node (e.g., print its value)
    cout << node->val << " ";

    // Recursively visit all the neighbours
    for (GraphNode* neighbour : node->neighbors) 
        G_DFS(neighbour, visited);
}
