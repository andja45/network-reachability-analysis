#include "RoutingAnalyzer.h"
#include <limits>

RoutingResult runRouting(const Graph& graph, int src, int dst, Metric metric, Heuristic h) {
    return {runDijkstra(graph, src, dst, metric), runAStar(graph, src, dst, metric, h)};
}

DCIResult computeDCI(const Graph& graph, int src, int dst, Metric metric, float maxDCI) {
    DijkstraResult beforeResult = runDijkstra(graph, src, dst, metric);

    DCIResult result;
    if (!beforeResult.found) return result;

    const auto& path = beforeResult.path;
    for (int i = 0; i + 1 < (int)path.size(); ++i) {
        const Edge* e = graph.findEdge(path[i], path[i+1]);

        Graph modified = graph;
        modified.removeEdge(e->from, e->to);

        DijkstraResult afterResult = runDijkstra(modified, src, dst, metric);

        float ratio = afterResult.found ? afterResult.totalCost / beforeResult.totalCost
                                : std::numeric_limits<float>::infinity();
        DetourCriticality dc = !afterResult.found ? DetourCriticality::Bridge
                             : ratio > maxDCI     ? DetourCriticality::Critical
                             : ratio > 1.0f       ? DetourCriticality::SemiCritical
                                                  : DetourCriticality::Redundant;
        result.dci[*e] = ratio;
        result.detourCriticality[*e] = dc;
    }
    return result;
}
