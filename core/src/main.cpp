#include <iostream>
#include "../include/Graph.h"

int main() {
    Graph g;

    int p1 = g.addNode("Provider A", NodeType::Provider);
    int r1 = g.addNode("Router 1", NodeType::Router);
    int r2 = g.addNode("Router 2", NodeType::Router);
    int h1 = g.addNode("Host 1", NodeType::Host);
    int h2 = g.addNode("Host 2", NodeType::Host);

    g.addEdge(p1, r1);
    g.addEdge(r1, r2);
    g.addEdge(r2, h1);
    g.addEdge(r2, h2);

    for (const auto& [id, node] : g.nodes()) {
        std::cout << node.label << " -> ";
        for (int nb : g.neighbors(id)) {
            std::cout << g.getNode(nb).label << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
