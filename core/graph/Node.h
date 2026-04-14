#ifndef NETWORKANALYSISLAB_NODE_H
#define NETWORKANALYSISLAB_NODE_H

#include <string>
#include "NodeType.h"

struct Node {
    int id;
    std::string label;
    NodeType type;
};

#endif //NETWORKANALYSISLAB_NODE_H
