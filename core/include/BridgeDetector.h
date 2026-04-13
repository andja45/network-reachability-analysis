#ifndef NETWORKREACHABILITYANALYSIS_BRIDGEDETECTOR_H
#define NETWORKREACHABILITYANALYSIS_BRIDGEDETECTOR_H

#include <vector>
#include "Graph.h"
#include "Edge.h"

struct BridgeResult {
    std::vector<Edge> bridges;
    std::vector<Edge> dfsOrder;
};

BridgeResult findBridges(const Graph& graph);

#endif
