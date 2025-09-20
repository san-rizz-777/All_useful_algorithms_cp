#pragma once

#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

namespace AStar {

struct Node {
    int x, y;   // Coordinates of the node
    int f, g, h; // A* values

    Node(int r = 0, int c = 0);

    bool operator==(const Node& other) const;
};

// Custom comparator for priority queue
struct CompareF {
    bool operator()(const Node& a, const Node& b) const {
        return a.f > b.f;
    }
};

// A* pathfinding algorithm
std::vector<Node> FindPath(const std::vector<std::vector<int>>& graph, const Node& start, const Node& goal);

// Function to print the path
void PrintPath(const std::vector<Node>& path);

} // namespace AStar
