#include "RoutingAnalyzer.h"
#include <limits>

RoutingResult runRouting(const Graph& graph, int src, int dst, Metric metric, Heuristic h) {
    return {runDijkstra(graph, src, dst, metric), runAStar(graph, src, dst, metric, h)};
}

DCIResult computeDCI(const Graph& graph, int src, int dst, Metric metric, float maxDCI) {
    float beforeCost = runDijkstra(graph, src, dst, metric).totalCost;

    DCIResult result;
    for (const auto& edge : graph.edges()) {
        Graph modified = graph;
        modified.removeEdge(edge.from, edge.to);

        DijkstraResult impactDCI = runDijkstra(modified, src, dst, metric);

        float ratio;
        DetourCriticality dc;

        if (!impactDCI.found) {
            ratio = std::numeric_limits<float>::infinity();
            dc = DetourCriticality::Bridge;
        } else {
            ratio = impactDCI.totalCost / beforeCost;
            if (ratio > maxDCI)
                dc = DetourCriticality::Critical;
            else if (ratio > 1.0f)
                dc = DetourCriticality::SemiCritical;
            else
                dc = DetourCriticality::Redundant;
        }

        result.dci[edge] = ratio;
        result.detourCriticality[edge] = dc;
    }

    return result;
}
