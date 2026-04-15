#ifndef NETWORKANALYSISLAB_APPTHEME_H
#define NETWORKANALYSISLAB_APPTHEME_H

#include "imgui.h"

namespace AppTheme {
    static constexpr ImVec4 BG_WINDOW    = {0.95f, 0.95f, 0.95f, 1.0f};
    static constexpr ImVec4 BG_PANEL     = {0.92f, 0.92f, 0.92f, 1.0f};
    static constexpr ImVec4 BG_CANVAS    = {1.0f, 1.0f, 1.0f, 1.0f};
    static constexpr ImVec4 BTN_SELECTED = {0.15f, 0.35f, 0.65f, 1.0f};

    static constexpr ImVec4 TEXT_RED = {0.86f, 0.23f, 0.23f, 1.0f};
    static constexpr ImVec4 TEXT_ORANGE = {0.90f, 0.55f, 0.15f, 1.0f};
    static constexpr ImVec4 TEXT_GREEN = {0.23f, 0.70f, 0.31f, 1.0f};

    static constexpr ImU32 NODE_DEFAULT = IM_COL32(80, 80, 80, 255);
    static constexpr ImU32 EDGE_DEFAULT = IM_COL32(100, 100, 100, 255);
    static constexpr ImU32 ROUTER = IM_COL32(100, 100, 100, 255);
    static constexpr ImU32 LABEL = IM_COL32(50, 50, 50, 255);
    static constexpr ImU32 PENDING_EDGE = IM_COL32(255, 255, 100, 200);

    static constexpr ImU32 UNREACHABLE = IM_COL32(220, 60, 60, 255);
    static constexpr ImU32 CRITICAL = IM_COL32(220, 60, 60, 255);
    static constexpr ImU32 SEMICRIT = IM_COL32(230, 140, 40, 255);
    static constexpr ImU32 REDUNDANT = IM_COL32(60, 180, 80, 255);

    static constexpr ImU32 DIJKSTRA_VISITED = IM_COL32(80, 140, 210, 255);
    static constexpr ImU32 ASTAR_VISITED = IM_COL32(60, 180, 140, 255);
    static constexpr ImU32 PATH_DIJKSTRA = IM_COL32(40, 100, 200, 255);
    static constexpr ImU32 PATH_ASTAR = IM_COL32(30, 160, 110, 255);

    static constexpr ImU32 PROVIDER_PALETTE[] = {
        IM_COL32(80, 140, 220, 255),
        IM_COL32(140, 80, 220, 255),
        IM_COL32(40, 180, 160, 255),
        IM_COL32(220, 160, 40, 255),
        IM_COL32(200, 80, 140, 255),
    };
    static constexpr int PALETTE_SIZE = 5;
}

#endif
