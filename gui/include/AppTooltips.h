#ifndef NETWORKANALYSISLAB_APPTOOLTIPS_H
#define NETWORKANALYSISLAB_APPTOOLTIPS_H

#include "imgui.h"
#include "graph/Edge.h"

namespace Tooltips {
    namespace {
        inline void hint(const char* text) {
            ImGui::SameLine(); ImGui::TextDisabled("(?)");
            if (ImGui::IsItemHovered()) ImGui::SetTooltip("%s", text);
        }
    }

    inline void bfs() {
        hint(
            "Reachable    - connected to a provider within the hop limit\n"
            "Underserved  - reachable but exceeds max hops\n"
            "Unreachable  - no path to any provider"
        );
    }

    inline void bridge() {
        hint(
            "Critical      - removal disconnects a host from all providers\n"
            "Semi-critical - removal doesn't break connectivity but exposes new critical edges\n"
            "Redundant     - removal has no effect on connectivity"
        );
    }

    inline void dci() {
        hint(
            "DCI = cost_without_edge / cost_with_edge\n"
            "Bridge        - no alternative path (destination unreachable)\n"
            "Critical      - DCI >= threshold (detour costs significantly more)\n"
            "Semi-critical - DCI between 1 and threshold (usable but worse)\n"
            "Redundant     - DCI close to 1 (near-equivalent alternative exists)"
        );
    }

    inline void edge(const Edge& e) {
        ImGui::BeginTooltip();
        ImGui::Text("Latency:     %.1f ms", e.latency);
        ImGui::Text("Price:       %.1f", e.price);
        ImGui::Text("Bandwidth:   %.0f Mbps", e.bandwidth);
        ImGui::Text("Load:        %.2f", e.load);
        ImGui::Text("Reliability: %.2f", e.reliability);
        ImGui::EndTooltip();
    }
}

#endif //NETWORKANALYSISLAB_APPTOOLTIPS_H
