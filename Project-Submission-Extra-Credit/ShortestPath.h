#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Graph.h"
#include <unordered_map>
#include <queue>
#include <string>

class ShortestPath {
private:
    Graph graph;

public:
    ShortestPath(const Graph& g);
    std::vector<std::string> findShortestPath(const std::string& start, const std::string& end);
};

#endif 
