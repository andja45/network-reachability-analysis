#ifndef NETWORKREACHABILITYANALYSIS_ANALYZER_H
#define NETWORKREACHABILITYANALYSIS_ANALYZER_H

#include "BFS.h"
#include "Edge.h"

// Represents the impact of removing a bridge edge
struct BridgeImpact {
    Edge bridge;
    std::vector<int> disconnectedHosts;
};

struct AnalysisResult {
    BFSResult bfs;
    std::vector<BridgeImpact> bridgeImpacts;
    std::vector<int> unreachableHosts;
    std::vector<int> underservedHosts; // distance > maxHops
    int totalHosts = 0;
    int reachableHosts = 0;
};

AnalysisResult analyze(const Graph& graph, int maxHops);

#endif
