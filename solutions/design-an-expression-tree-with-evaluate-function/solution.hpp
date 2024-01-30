#pragma once

#include <stack>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

class Node {
public:
  virtual ~Node() = default;
  virtual int evaluate() const = 0;
};

class Number : public Node {
public:
  explicit Number(int value) : value(value) {}

  int evaluate() const override { return value; }

private:
  int value;
};

class BinaryExpression : public Node {
public:
  BinaryExpression(Node *left, Node *right, std::string op)
      : left(left), right(right), op(op) {}

  int evaluate() const override {
    if (op == "+") {
      return left->evaluate() + right->evaluate();
    }
    if (op == "-") {
      return left->evaluate() - right->evaluate();
    }
    if (op == "*") {
      return left->evaluate() * right->evaluate();
    }
    if (op == "/") {
      return left->evaluate() / right->evaluate();
    }
    throw;
  }

private:
  Node *left, *right;
  std::string op;
};

class TreeBuilder {
public:
  static Node *buildTree(const std::vector<std::string> &postfix) {
    std::stack<Node *> stack;
    for (const auto &token : postfix) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        auto *right = stack.top();
        stack.pop();
        auto *left = stack.top();
        stack.pop();
        stack.push(new BinaryExpression(left, right, token));
      } else {
        stack.push(new Number(stoi(token)));
      }
    }
    return stack.top();
  }
};
