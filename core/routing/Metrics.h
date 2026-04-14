#ifndef NETWORKANALYSISLAB_METRICS_H
#define NETWORKANALYSISLAB_METRICS_H

#include <functional>
#include <cmath>
#include "graph/Edge.h"

using Metric = std::function<float(const Edge&)>;
using Heuristic = std::function<float(int, int)>;

inline Metric costFastest() {
    return [](const Edge& e) { return e.latency; };
}

inline Metric costCheapest() {
    return [](const Edge& e) { return e.price; };
}

inline Metric costLeastLoaded() {
    // M/M/1 queueing model: wait = 1/(1-load)
    return [](const Edge& e) { return 1.0f / (1.0f - std::min(e.load, 0.99f)); };
}

inline Metric costMostReliable() {
    // max r1 x r2 x r3 is max log(r1) + log(r2) + log(r3) is min -log(r1) - log(r2) - log(r3)
    return [](const Edge& e) { return -std::log(std::max(e.reliability, 1e-6f)); };
}

inline Metric costBalanced() {
    // weights chosen so all three metrics contribute on similar scales
    return [](const Edge& e) {
        return 0.4f * e.latency + 0.4f * e.price + 0.2f * (-std::log(std::max(e.reliability, 1e-6f)));
    };
}

#endif //NETWORKANALYSISLAB_METRICS_H
