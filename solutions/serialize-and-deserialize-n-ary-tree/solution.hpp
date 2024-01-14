#pragma once

#include <optional>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include <node.h>

// Time: O(N)
// Space: O(N)

namespace lc {

// Time: O(N)
// Space: O(N)
class Codec {
public:
  static std::string serialize(Node *root) {
    if (!root) {
      return "";
    }

    std::queue<Node *> queue{{root}};
    std::string ans = std::to_string(root->val) + " #";
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      for (auto *child : node->children) {
        ans += " " + std::to_string(child->val);
        queue.push(child);
      }
      ans += " #";
    }
    while (ans.ends_with('#')) {
      ans.pop_back();
      ans.pop_back();
    }
    return ans;
  }

  static Node *deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }

    std::stringstream sstream(data);
    std::vector<std::optional<int>> values;
    for (std::string token; sstream >> token;) {
      if (token == "#") {
        values.push_back(std::nullopt);
      } else {
        values.push_back(std::stoi(token));
      }
    }
    const int n = values.size();

    auto *root = new Node(values.front().value());
    std::queue<Node *> queue{{root}};

    for (int i = 1; !queue.empty();) {
      auto node = queue.front();
      queue.pop();

      for (++i; i < n && values[i].has_value(); ++i) {
        auto *child = new Node(values[i].value());
        node->children.push_back(child);
        queue.push(child);
      }
    }
    return root;
  }
};

} // namespace lc

namespace dfs {

// Time: O(N)
// Space: O(N)
class Codec {
public:
  static std::string serialize(Node *root) {
    std::ostringstream ostream;
    encode(root, ostream);
    return ostream.str();
  }

  static Node *deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }
    std::istringstream istream(data);
    return decode(istream);
  }

private:
  static void encode(Node *node, std::ostringstream &ostream) {
    if (!node) {
      return;
    }
    ostream << " " << node->val << " " << node->children.size();
    for (auto *child : node->children) {
      encode(child, ostream);
    }
  }

  static Node *decode(std::istringstream &istream) {
    int val, n;
    istream >> val >> n;

    auto *node = new Node(val);
    for (int i = 0; i < n; ++i) {
      node->children.push_back(decode(istream));
    }
    return node;
  }
};

} // namespace dfs
