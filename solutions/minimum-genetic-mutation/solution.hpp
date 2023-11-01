#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

/*
  433. Minimum Genetic Mutation
  https://leetcode.com/problems/minimum-genetic-mutation/
  Difficulty: Medium
  Tags: Hash Table, String, Breadth-First Search
  Time:
  Space:
*/

class Solution {
public:
  static int minMutation(std::string start_gene, std::string end_gene,
                         const std::vector<std::string> &bank) {
    std::unordered_set<std::string> mutations{bank.begin(), bank.end()};

    std::queue<std::pair<std::string, int>> queue;
    queue.emplace(start_gene, 0);
    mutations.erase(start_gene);
    while (!queue.empty()) {
      auto [gene, distance] = queue.front();
      queue.pop();

      if (gene == end_gene) {
        return distance;
      }

      for (size_t i = 0; i < gene.size(); ++i) {
        char symbol = gene[i];
        for (char c : {'A', 'C', 'G', 'T'}) {
          gene[i] = c;
          if (mutations.count(gene)) {
            queue.emplace(gene, distance + 1);
            mutations.erase(gene);
          }
        }
        gene[i] = symbol;
      }
    }
    return -1;
  }
};
