#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(Q(M+N+KlogK))
// Space: O(QM)

struct TrieNode {
  std::unordered_map<std::string, std::unique_ptr<TrieNode>> children;
  std::string content;
};

class FileSystem : private TrieNode {
public:
  // O(M+N+KlogK)
  std::vector<std::string> ls(std::string path) {
    auto node = getPrefix(path);
    if (!node) {
      return {};
    }
    if (!node->content.empty()) {
      return {split(path).back()};
    }
    std::vector<std::string> names;
    for (const auto &[s, _] : node->children) {
      names.push_back(s);
    }
    std::ranges::sort(names);
    return names;
  }

  // O(M+N)
  void mkdir(std::string path) { insert(path); }

  // O(M+N)
  void addContentToFile(std::string filePath, std::string content) {
    insert(filePath, content);
  }

  // O(M+N)
  std::string readContentFromFile(std::string filePath) {
    auto node = getPrefix(filePath);
    return !node ? "" : node->content;
  }

private:
  TrieNode *getRoot() { return this; }

  void insert(std::string path, std::string content = "") {
    auto *node = getRoot();
    for (const auto &s : split(path)) {
      if (!node->children.contains(s)) {
        node->children[s] = std::make_unique<TrieNode>();
      }
      node = node->children[s].get();
    }
    node->content += content;
  }

  TrieNode *getPrefix(std::string path) {
    auto *node = getRoot();
    for (const auto &s : split(path)) {
      if (!node->children.contains(s)) {
        return nullptr;
      }
      node = node->children[s].get();
    }
    return node;
  }

  std::vector<std::string> split(std::string path) {
    std::vector<std::string> dirs;
    std::istringstream istream(path);
    for (std::string dir; std::getline(istream, dir, '/');) {
      if (!dir.empty()) {
        dirs.push_back(dir);
      }
    }
    return dirs;
  }
};
