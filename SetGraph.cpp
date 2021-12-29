#include "SetGraph.h"

SetGraph::SetGraph(int count) : vertices(count, std::unordered_set<int>()) {
}

SetGraph::SetGraph(const IGraph& graph) : vertices(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        for (auto vert : graph.GetNextVertices(i)) {
            vertices[i].insert(vert);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVert;
    for (int i = 0; i < VerticesCount(); i++) {
        if (vertices[vertex].count(vertex) != 0) {
            prevVert.push_back(vertex);
        }
    }

    return prevVert;
}


