#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int count) : vertices(count, std::vector<int>(count)) {
}

MatrixGraph::MatrixGraph(const IGraph& graph) : vertices(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        vertices[i] = graph.GetNextVertices(i);
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (int i = 0; i < vertices[vertex].size(); i++) {
        if (vertices[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVert;
    for (int i = 0; i < VerticesCount(); i++) {
        if (vertices[i][vertex] == 1) {
            prevVert.push_back(i);
        }
    }
    return prevVert;
}
