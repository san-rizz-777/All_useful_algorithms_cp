#include "A_star.h"
#include <iostream>

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    AStar::Node start(0, 0);
    AStar::Node goal(4, 4);

    std::vector<AStar::Node> path = AStar::FindPath(grid, start, goal);

    if (!path.empty()) {
        std::cout << "Path found:\n";
        AStar::PrintPath(path);
    } else {
        std::cout << "No path found!\n";
    }

    return 0;
}
