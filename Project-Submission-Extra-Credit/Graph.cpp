// Graph.cpp
#include "Graph.h"
#include <algorithm>

void Graph::addCity(const std::string& city) {
    if (adjacencyList.find(city) == adjacencyList.end()) {
        adjacencyList[city] = std::vector<std::pair<std::string, int>>();
    }
}

void Graph::addConnection(const std::string& city1, const std::string& city2, int distance) {
    adjacencyList[city1].push_back(std::make_pair(city2, distance));
    adjacencyList[city2].push_back(std::make_pair(city1, distance)); // For an undirected graph
}

std::vector<std::pair<std::string, int>> Graph::getNeighbors(const std::string& city) {
    return adjacencyList[city];
}
