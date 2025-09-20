//Pseudo-code :- 

//First create two lists : - open and closed
//Open -> Contains nodes that to be evaluated 
//Closed -> Already evaluated

//Add start node to open 
//In a loop now : -
//Create a temporary var "current" and set "current = node in open"
//Remove the "current" from "open" and add it to "closed"

//"Now check if the current matches to the goal node if yes return"

//Another loop for checking neighbours of current:-
//Now "if neighbours have a shortest path than current 'f(X)' or if neighbour is not in open"
//set the f(x) of it to neighbour node and set "parent node to current"

//If neighbour node is not added to open , "add it".

#include "A_star.h"
#include <iostream>
#include <climits>

namespace AStar {

// Node constructor
Node::Node(int r, int c) : x(r), y(c), f(0), g(0), h(0) {}

bool Node::operator==(const Node& other) const {
    return x == other.x && y == other.y;
}

// Manhattan heuristic function
static int Heuristic(const Node& a, const Node& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// A* algorithm implementation
std::vector<Node> FindPath(const std::vector<std::vector<int>>& graph, const Node& start, const Node& goal) {
    int rows = static_cast<int>(graph.size());
    int cols = static_cast<int>(graph[0].size());

    std::priority_queue<Node, std::vector<Node>, CompareF> openList;
    std::vector<std::vector<bool>> closedList(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<Node>> parent(rows, std::vector<Node>(cols));
    std::vector<std::vector<int>> gCost(rows, std::vector<int>(cols, INT_MAX));

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    Node startNode = start;
    startNode.g = 0;
    startNode.h = Heuristic(start, goal);
    startNode.f = startNode.g + startNode.h;

    openList.push(startNode);
    gCost[start.x][start.y] = 0;

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current == goal) {
            std::vector<Node> path;
            Node temp = current;
            while (!(temp == start)) {
                path.push_back(temp);
                temp = parent[temp.x][temp.y];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        if (closedList[current.x][current.y]) continue;
        closedList[current.x][current.y] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && graph[nx][ny] == 0) {
                int newG = current.g + 1;
                if (newG < gCost[nx][ny]) {
                    gCost[nx][ny] = newG;
                    Node neighbor(nx, ny);
                    neighbor.g = newG;
                    neighbor.h = Heuristic(neighbor, goal);
                    neighbor.f = neighbor.g + neighbor.h;
                    parent[nx][ny] = current;
                    openList.push(neighbor);
                }
            }
        }
    }

    return {}; // No path found
}

// Print path
void PrintPath(const std::vector<Node>& path) {
    for (const auto& node : path) {
        std::cout << "(" << node.x << ", " << node.y << ") ";
    }
    std::cout << "\n";
}

} // namespace AStar
