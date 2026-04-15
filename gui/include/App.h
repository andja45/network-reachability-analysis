#ifndef NETWORKANALYSISLAB_APP_H
#define NETWORKANALYSISLAB_APP_H

#include "AppState.h"
#include "GraphRenderer.h"
#include "GLFW/glfw3.h"

class App {
private:
    GLFWwindow* m_window = nullptr;
    AppState m_state;
    GraphRenderer m_top;
    GraphRenderer m_bot;
    ImVec2 m_canvasSize = {0, 0};
    int m_labelSeq[3] = {}; // {P, R, H} label counters for auto-naming nodes

    void leftPanel();
    void canvas();
    void rightPanel();
    void loadExample(const Graph& g, const ImVec2* positions = nullptr, int count = 0);

    void syncAddNode(int id, ImVec2 pos);
    void syncRemoveNode(int id);
    void syncAddEdge(const Edge& e);
    void syncRemoveEdge(const Edge& e);
    void syncMoveNode(int id, ImVec2 delta);
    void syncSetNodePosition(int id, ImVec2 pos);
    void syncClear();
    void syncReset();
public:
    App();
    ~App();
    void run();
};

#endif
