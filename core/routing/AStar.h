#ifndef NETWORKANALYSISLAB_ASTAR_H
#define NETWORKANALYSISLAB_ASTAR_H

#include "Dijkstra.h"

using AStarResult = PathResult;

PathResult runAStar(const Graph& graph, int src, int dst, Metric metric, Heuristic h);

#endif //NETWORKANALYSISLAB_ASTAR_H
