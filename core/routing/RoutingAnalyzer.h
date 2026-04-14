#ifndef NETWORKANALYSISLAB_ROUTINGANALYZER_H
#define NETWORKANALYSISLAB_ROUTINGANALYZER_H

#include <unordered_map>
#include "Dijkstra.h"
#include "AStar.h"
#include "graph/Edge.h"

struct RoutingResult {
    DijkstraResult dijkstra;
    AStarResult astar;
};

enum class DetourCriticality { Bridge, Critical, SemiCritical, Redundant };

struct DCIResult { // DCI = Detour Cost Index = cost_after_removing_edge / cost_before_removing_edge
    std::unordered_map<Edge, float> dci;
    std::unordered_map<Edge, DetourCriticality> detourCriticality;
};

RoutingResult runRouting(const Graph& graph, int src, int dst, Metric metric, Heuristic h);
DCIResult computeDCI(const Graph& graph, int src, int dst, Metric metric, float maxDCI);

#endif //NETWORKANALYSISLAB_ROUTINGANALYZER_H
