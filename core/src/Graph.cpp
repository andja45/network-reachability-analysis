#include "../include/Graph.h"
#include <algorithm>
#include <stdexcept>

int Graph::addNode(const std::string& label, NodeType type) {
    int id = nextId_++;
    nodes_[id] = Node{id, label, type};
    adj_[id] = {};
    return id;
}

bool Graph::addEdge(int u, int v) {
    if (!hasNode(u) || !hasNode(v) || u == v) return false;

    auto& nu = adj_[u];
    auto& nv = adj_[v];

    if (std::find(nu.begin(), nu.end(), v) == nu.end()) nu.push_back(v);
    if (std::find(nv.begin(), nv.end(), u) == nv.end()) nv.push_back(u);

    return true;
}

bool Graph::hasNode(int id) const {
    return nodes_.find(id) != nodes_.end();
}

const Node& Graph::getNode(int id) const {
    return nodes_.at(id);
}

const std::vector<int>& Graph::neighbors(int id) const {
    return adj_.at(id);
}

const std::unordered_map<int, Node>& Graph::nodes() const {
    return nodes_;
}

std::vector<int> Graph::getNodesByType(NodeType type) const {
    std::vector<int> result;
    for (const auto& [id, node] : nodes_) {
        if (node.type == type) result.push_back(id);
    }
    return result;
}