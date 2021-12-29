#pragma once

#include "IGraph.h"

class ArcGraph : public IGraph {
    struct FromTo {
        int first;
        int second;

        explicit FromTo(int f = 0, int s = 0) : first(f), second(s) {}
    };

public:
    ~ArcGraph() {};

    explicit ArcGraph(int count);

    explicit ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<FromTo> vertices;
    int kol;
};
