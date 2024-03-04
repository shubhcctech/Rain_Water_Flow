#include"stdafx.h"
#include "MaxFlowPathFinder.h"
#include "STL_Reader.h"
#include <iostream>
#include <limits>
#include <queue>

MaxFlowPathFinder::MaxFlowPathFinder() {}

MaxFlowPathFinder::~MaxFlowPathFinder() {}

// Function to calculate distance between two points
double distance(const Point3D& p1, const Point3D& p2) {
    return sqrt(pow(p1.X() - p2.X(), 2) + pow(p1.Y() - p2.Y(), 2) + pow(p1.Z() - p2.Z(), 2));
}

class MaxFlowGraph {
public:
    int numNodes;
    std::vector<std::vector<double>> capacities;
    std::vector<std::vector<double>> flows;

    MaxFlowGraph(int numNodes) : numNodes(numNodes), capacities(numNodes, std::vector<double>(numNodes, 0.0)), flows(numNodes, std::vector<double>(numNodes, 0.0)) {}

    void addEdge(int from, int to, double capacity) {
        capacities[from][to] = capacity;
        capacities[to][from] = 0.0; // Assuming undirected graph
    }

    double fordFulkerson(std::vector<int>& path) {
        double maxFlow = 0.0;

        // Continue augmenting paths until no more augmenting paths can be found
        while (true) {
            std::vector<int> parent(numNodes, -1);
            std::vector<bool> visited(numNodes, false);
            std::queue<int> q;

            q.push(0); // Assuming the source node is 0

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                visited[current] = true;

                for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                    if (!visited[neighbor] && capacities[current][neighbor] - flows[current][neighbor] > 0) {
                        q.push(neighbor);
                        parent[neighbor] = current;
                    }
                }
            }

            // If no more augmenting paths are found, break the loop
            if (!visited[numNodes - 1]) {
                break; // Assuming the sink node is numNodes - 1
            }

            // Find the minimum residual capacity along the augmenting path
            double pathCapacity = std::numeric_limits<double>::infinity();
            for (int v = numNodes - 1; v != 0; v = parent[v]) {
                path.push_back(v); // Store the nodes in the path
                pathCapacity = std::min(pathCapacity, capacities[parent[v]][v] - flows[parent[v]][v]);
            }

            // Update the flow along the augmenting path
            for (int v = numNodes - 1; v != 0; v = parent[v]) {
                flows[parent[v]][v] += pathCapacity;
                flows[v][parent[v]] -= pathCapacity;
            }

            maxFlow += pathCapacity;
        }

        // Reverse the path to get the correct order
        std::reverse(path.begin(), path.end());

        return maxFlow;
    }
};

QVector<Point3D> MaxFlowPathFinder::findMaxFlowPath(Triangulations& triangulations) {
    // Create a MaxFlowGraph object
    int numNodes = triangulations.uniquePoints().size();
    MaxFlowGraph graph(numNodes);

    // Add edges to the graph based on terrain data (connect neighboring vertices)
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            double cap = distance(triangulations.uniquePoints()[i], triangulations.uniquePoints()[j]);
            graph.addEdge(i, j, cap);
        }
    }

    // Assuming you have a source and sink node (replace these with your logic)
    int source = 0;
    int sink = numNodes - 1;

    std::vector<int> nodePath;
    double maxFlow = graph.fordFulkerson(nodePath);

    QVector<Point3D> coordinatesPath;
    for (int nodeIndex : nodePath) {
        coordinatesPath.push_back(triangulations.uniquePoints()[nodeIndex]);
    }

    std::cout << "Maximum flow of water through the terrain: " << maxFlow << std::endl;

    // Return the coordinates of the path
    return coordinatesPath;
}
