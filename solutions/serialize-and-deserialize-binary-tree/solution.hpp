#pragma once

#include <tree_node.h>

#include <sstream>
#include <string>

class Codec {
public:
  std::string serialize(TreeNode *root) {
    std::ostringstream output;
    encode(root, output);
    return output.str();
  }

  TreeNode *deserialize(std::string data) {
    std::istringstream input(data);
    return decode(input);
  }

private:
  const std::string EMPTY = "#";

  void encode(TreeNode *root, std::ostringstream &output) {
    if (!root) {
      output << EMPTY << " ";
    } else {
      output << root->val << " ";
      encode(root->left, output);
      encode(root->right, output);
    }
  }

  TreeNode *decode(std::istringstream &input) {
    std::string val;
    input >> val;

    if (val == EMPTY) {
      return nullptr;
    }

    return new TreeNode(std::stoi(val), decode(input), decode(input));
  }
};