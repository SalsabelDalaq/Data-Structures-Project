// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjacencyList;

public:
    void addCity(const std::string& city);
    void addConnection(const std::string& city1, const std::string& city2, int distance);
    std::vector<std::pair<std::string, int>> getNeighbors(const std::string& city);
};

#endif // GRAPH_H
