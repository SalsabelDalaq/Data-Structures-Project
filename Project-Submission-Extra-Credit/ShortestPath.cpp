#include "ShortestPath.h"
#include <unordered_set>
#include <algorithm>

ShortestPath::ShortestPath(const Graph& g) : graph(g) {}

std::vector<std::string> ShortestPath::findShortestPath(const std::string& start, const std::string& end) {
    std::unordered_map<std::string, std::string> previous;
    std::unordered_map<std::string, int> distance;
    std::unordered_set<std::string> visited;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;

    for (const auto& city : graph.getNeighbors(start)) {
        distance[city.first] = city.second;
        previous[city.first] = start;
        pq.push(std::make_pair(city.second, city.first));
    }

    while (!pq.empty()) {
        std::string currentCity = pq.top().second;
        pq.pop();

        if (visited.find(currentCity) != visited.end()) {
            continue;
        }

        visited.insert(currentCity);

        for (const auto& neighbor : graph.getNeighbors(currentCity)) {
            int newDistance = distance[currentCity] + neighbor.second;

            if (newDistance < distance[neighbor.first]) {
                distance[neighbor.first] = newDistance;
                previous[neighbor.first] = currentCity;
                pq.push(std::make_pair(newDistance, neighbor.first));
            }
        }
    }

    std::vector<std::string> path;
    std::string current = end;
    while (current != start) {
        path.push_back(current);
        current = previous[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}
