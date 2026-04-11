#include "BridgeDetector.h"
#include <unordered_map>
#include <algorithm>

// Tarjan's algorithm for finding bridges in an undirected graph
static void dfs(int u, int parent, const Graph& graph, std::unordered_map<int, int>& dfsNum,
                std::unordered_map<int, int>& lowlink, int& num, std::vector<Edge>& bridges) {

    dfsNum[u] = lowlink[u] = ++num; // discovery time

    for (int v : graph.neighbors(u)) {
        if (dfsNum[v] == 0) { // unvisited
            dfs(v, u, graph, dfsNum, lowlink, num, bridges);

            lowlink[u] = std::min(lowlink[u], lowlink[v]);

            if (lowlink[v] > dfsNum[u]) // v cannot reach nodes before u, so (u,v) is a bridge
                bridges.push_back({std::min(u, v), std::max(u, v)});
        } else if (v != parent) { // visited but not the parent, update lowlink
            lowlink[u] = std::min(lowlink[u], dfsNum[v]);
        }
    }
}

std::vector<Edge> findBridges(const Graph& graph) {
    std::unordered_map<int, int> dfsNum;
    std::unordered_map<int, int> lowLink;
    std::vector<Edge> bridges;
    int num = 0;

    for (const auto& [id, node] : graph.nodes()) {
        dfsNum[id] = 0;
    }

    for (const auto& [id, node] : graph.nodes()) {
        if (dfsNum[id] == 0) // run dfs from every unvisited node
            dfs(id, -1, graph, dfsNum, lowLink, num, bridges);
    }

    return bridges;
}
