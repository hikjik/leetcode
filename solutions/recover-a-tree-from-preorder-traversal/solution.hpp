#pragma once

#include <tree_node.h>

#include <string>

// Time:
// Space:

class Tokenizer {
public:
  struct Token {
    int depth = 0;
    int value = 0;
  };

  explicit Tokenizer(const std::string &s) {
    for (size_t i = 0; i < s.size();) {
      Token token;
      while (s[i] == '-') {
        token.depth++, i++;
      }
      while (i < s.size() && s[i] != '-') {
        token.value = token.value * 10 + (s[i++] - '0');
      }
      tokens.push_back(token);
    }
  }

  bool HasNext() const { return position != tokens.size(); }

  const Token &Peek() const { return tokens[position]; }

  void Next() { position++; }

private:
  std::vector<Token> tokens;
  size_t position = 0;
};

class Solution {
public:
  static TreeNode *recoverFromPreorder(std::string traversal) {
    Tokenizer tokenizer(traversal);
    return dfs(-1, &tokenizer);
  }

  static TreeNode *dfs(int depth, Tokenizer *tokenizer) {
    if (!tokenizer->HasNext()) {
      return nullptr;
    }
    auto peek = tokenizer->Peek();
    if (peek.depth != depth + 1) {
      return nullptr;
    }
    tokenizer->Next();
    return new TreeNode(peek.value, dfs(depth + 1, tokenizer),
                        dfs(depth + 1, tokenizer));
  }
};
