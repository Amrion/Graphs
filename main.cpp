#include <iostream>
#include <stack>
#include <queue>

#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void DFS(const IGraph& graph, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::stack<int> stack;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        stack.push(vertex);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            if (!visited[current]) {
                visit(current);
                visited[current] = true;

                std::vector<int> list = graph.GetNextVertices(current);

                for (auto& i : list) {
                    stack.push(i);
                }
            }
        }
    }

}

void BFS(const IGraph& graph, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> queue;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            queue.push(vertex);
            visited[vertex] = true;
            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();
                visit(current);
                std::vector<int> list = graph.GetNextVertices(current);
                for (auto& i : list) {
                    if (!visited[i]) {
                        queue.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
}

int main() {
    IGraph* graphL = new ListGraph(9);
    graphL->AddEdge(0, 1);
    graphL->AddEdge(1, 5);
    graphL->AddEdge(6, 0);
    graphL->AddEdge(1, 2);
    graphL->AddEdge(2, 3);
    graphL->AddEdge(3, 4);
    graphL->AddEdge(4, 2);
    graphL->AddEdge(0, 7);
    graphL->AddEdge(0, 8);

    std::cout << "ListGraph" << std::endl;
    std::cout << "DFS" << std::endl;
    DFS(*graphL, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl;
    std::cout << "BFS" << std::endl;
    BFS(*graphL, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl << std::endl;

    IGraph* graphM = new MatrixGraph(9);
    graphM->AddEdge(0, 1);
    graphM->AddEdge(1, 5);
    graphM->AddEdge(6, 0);
    graphM->AddEdge(1, 2);
    graphM->AddEdge(2, 3);
    graphM->AddEdge(3, 4);
    graphM->AddEdge(4, 2);
    graphM->AddEdge(0, 7);
    graphM->AddEdge(0, 8);

    std::cout << "MatrixGraph" << std::endl;
    std::cout << "DFS" << std::endl;
    DFS(*graphM, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl;
    std::cout << "BFS" << std::endl;
    BFS(*graphM, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl << std::endl;

    IGraph* graphS = new SetGraph(9);
    graphS->AddEdge(0, 1);
    graphS->AddEdge(1, 5);
    graphS->AddEdge(6, 0);
    graphS->AddEdge(1, 2);
    graphS->AddEdge(2, 3);
    graphS->AddEdge(3, 4);
    graphS->AddEdge(4, 2);
    graphS->AddEdge(0, 7);
    graphS->AddEdge(0, 8);

    std::cout << "SetGraph" << std::endl;
    std::cout << "DFS" << std::endl;
    DFS(*graphS, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl;
    std::cout << "BFS" << std::endl;
    BFS(*graphS, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl << std::endl;

    IGraph* graphA = new ArcGraph(9);
    graphA->AddEdge(0, 1);
    graphA->AddEdge(1, 5);
    graphA->AddEdge(6, 0);
    graphA->AddEdge(1, 2);
    graphA->AddEdge(2, 3);
    graphA->AddEdge(3, 4);
    graphA->AddEdge(4, 2);
    graphA->AddEdge(0, 7);
    graphA->AddEdge(0, 8);

    std::cout << "ArcGraph" << std::endl;
    std::cout << "DFS" << std::endl;
    DFS(*graphA, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl;
    std::cout << "BFS" << std::endl;
    BFS(*graphA, [](int vertex) {
        std::cout << vertex << " ";
    });
    std::cout << std::endl;

    return 0;
}
