#include "Graph.h"
#include "ShortestPath.h"
#include <iostream>
#include <algorithm>

int main() {
    Graph cityGraph; // Initialize the graph

    // Populate the graph with data (add cities and connections)
    cityGraph.addCity("City A");
    cityGraph.addCity("City B");
    cityGraph.addCity("City C");
    // Add connections between cities with distances
    cityGraph.addConnection("City A", "City B", 10); // Distance between City A and City B is 10
    cityGraph.addConnection("City A", "City C", 15); // Distance between City A and City C is 15
    // Add other connections as needed...

    // Find the shortest path between two cities
    ShortestPath shortestPath(cityGraph);

    // Example: Finding the shortest path from City A to City B
    std::vector<std::string> path = shortestPath.findShortestPath("City A", "City B");

    // Display the shortest path
    if (!path.empty()) {
        std::cout << "Shortest Path from City A to City B: ";
        for (const std::string& city : path) {
            std::cout << city << " -> ";
        }
        std::cout << "Destination Reached" << std::endl;
    } else {
        std::cout << "No path found between the cities." << std::endl;
    }

    return 0;
}
