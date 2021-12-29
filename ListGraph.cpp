#include "ListGraph.h"

ListGraph::ListGraph(int count) {
    vertices.resize(count);
}

ListGraph::ListGraph(const IGraph &iGraph) {
    vertices.resize(iGraph.VerticesCount());
    for (int i = 0; i < iGraph.VerticesCount(); i++) {
        vertices[i] = iGraph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());

    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std:: vector<int> result;

    for (size_t parent = 0; parent < vertices.size(); ++parent) {
        for (auto& child : vertices[parent]) {
            if (child == vertex) {
                result.push_back(parent);
                break;
            }
        }
    }

    return result;
}