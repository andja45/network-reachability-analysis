#include "Analyzer.h"
#include "BridgeDetector.h"

AnalysisResult analyze(const Graph& graph, int maxHops) {
    AnalysisResult result;

    result.bfs = runBFS(graph);

    for (int hostId : graph.getNodesByType(NodeType::Host)) {
        result.totalHosts++;

        if (result.bfs.distance[hostId] == -1) {
            result.unreachableHosts.push_back(hostId);
        } else {
            result.reachableHosts++;
            if (result.bfs.distance[hostId] > maxHops)
                result.underservedHosts.push_back(hostId);
        }
    }

    std::vector<Edge> bridges = findBridges(graph);

    for (const Edge& bridge : bridges) {
        BridgeImpact impact;
        impact.bridge = bridge;

        Graph copy = graph;
        copy.removeEdge(bridge.from, bridge.to);
        BFSResult impactBFS = runBFS(copy);

        for (int hostId : graph.getNodesByType(NodeType::Host)) {
            bool wasReachable = result.bfs.distance[hostId] != -1;
            bool nowUnreachable = impactBFS.distance[hostId] == -1;

            if (wasReachable && nowUnreachable)
                impact.disconnectedHosts.push_back(hostId);
        }

        result.bridgeImpacts.push_back(impact);
    }

    return result;
}
