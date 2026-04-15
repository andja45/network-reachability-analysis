#include "AppState.h"

void AppState::runAnalysis() {
    result = analyze(graph, maxHops);
}

static Metric toMetric(MetricChoice p) {
    switch (p) {
        case MetricChoice::Fastest: return costFastest();
        case MetricChoice::Cheapest: return costCheapest();
        case MetricChoice::LeastLoaded: return costLeastLoaded();
        case MetricChoice::MostReliable: return costMostReliable();
        default: return costBalanced();
    }
}

void AppState::runRouting(Heuristic h) {
    topCanvas.result = ::runRouting(graph, routingSrc, routingDst, toMetric(topCanvas.metric), h);
    bottomCanvas.result = ::runRouting(graph, routingSrc, routingDst, toMetric(bottomCanvas.metric), h);
    topCanvas.animationState = AnimationState::Running;
    topCanvas.animationStep = 0;
    topCanvas.packetPhase = false;
    topCanvas.packetT = 0.0f;
    topCanvas.packetEdgeIdx = 0;
    bottomCanvas.animationState = AnimationState::Running;
    bottomCanvas.animationStep = 0;
    bottomCanvas.packetPhase = false;
    bottomCanvas.packetT = 0.0f;
    bottomCanvas.packetEdgeIdx = 0;
    viewMode = ViewMode::Routing;
}

void AppState::runResilience() {
    topCanvas.dciResult = computeDCI(graph, routingSrc, routingDst, toMetric(topCanvas.metric), 2.0f);
    bottomCanvas.dciResult = computeDCI(graph, routingSrc, routingDst, toMetric(bottomCanvas.metric), 2.0f);
    viewMode = ViewMode::DCI;
}
