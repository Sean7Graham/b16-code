#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE (Q9.1)

    for (int i = 0; i < V - 1; ++i) {
        has_negative_cycle = false;
        for (int u = 0; u < V; ++u) {
            for (const auto &edge : graph[u]) {
                auto distance = DP[edge.vertex].weight;
                auto new_distance = DP[u].weight + edge.weight;
                if (new_distance < distance) {
                    DP[edge.vertex] = {new_distance, u};
                    has_negative_cycle = true;
                }
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE (Q9.1)
    



    return DP;
}
