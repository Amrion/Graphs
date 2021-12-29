#include "ArcGraph.h"

ArcGraph::ArcGraph(int count) : kol(0) {
    vertices.resize(count);
}

ArcGraph::ArcGraph(const IGraph& graph)  {
    vertices.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); i++) {
        for (auto edge : graph.GetNextVertices(i)) {
            FromTo temp(i, edge);
            vertices.push_back(temp);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    FromTo temp(from, to);
    vertices[kol] = temp;
    ++kol;
}

int ArcGraph::VerticesCount() const {
    return kol;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (auto item : vertices) {
        if (item.first == vertex) {
            nextVertices.push_back(item.second);
        }
    }

    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (auto item : vertices) {
        if (item.second == vertex) {
            prevVertices.push_back(item.first);
        }
    }

    return prevVertices;
}




