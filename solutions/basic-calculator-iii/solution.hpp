#pragma once

#include <functional>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(N)

class Tokenizer {
public:
  Tokenizer(std::istream *in) : in_{in} {}

  enum TokenType {
    kUnknown,
    kNumber,
    kOpen,
    kClose,
    kPlus,
    kMinus,
    kMul,
    kDiv,
    kEnd,
  };

  void Consume() {
    while (std::isspace(in_->peek())) {
      in_->ignore();
    }
    if (in_->eof()) {
      type_ = kEnd;
    } else if (std::isdigit(in_->peek())) {
      *in_ >> number_;
      type_ = kNumber;
    } else if (std::ispunct(in_->peek())) {
      symbol_ = in_->get();
      if (symbol_ == '(') {
        type_ = kOpen;
      } else if (symbol_ == ')') {
        type_ = kClose;
      } else if (symbol_ == '+') {
        type_ = kPlus;
      } else if (symbol_ == '-') {
        type_ = kMinus;
      } else if (symbol_ == '*') {
        type_ = kMul;
      } else if (symbol_ == '/') {
        type_ = kDiv;
      } else {
        type_ = kUnknown;
      }
    } else {
      type_ = kUnknown;
    }
  }

  TokenType GetType() const { return type_; }

  int GetNumber() const { return number_; }

  char GetSymbol() const { return symbol_; }

private:
  std::istream *in_;

  TokenType type_ = TokenType::kUnknown;
  int number_;
  char symbol_;
};

class Expression {
public:
  virtual ~Expression() = default;
  virtual int Evaluate() const = 0;
};

class Number : public Expression {
public:
  explicit Number(int number) : number_(number) {}

  int Evaluate() const override { return number_; }

private:
  int number_;
};

class BinaryOperation : public Expression {
private:
  using Function = std::function<int(int, int)>;

  static const inline std::unordered_map<char, Function> kOps{
      {'+', std::plus<int>()},
      {'-', std::minus<int>()},
      {'*', std::multiplies<int>()},
      {'/', std::divides<int>()},
  };

public:
  BinaryOperation(std::unique_ptr<Expression> left,
                  std::unique_ptr<Expression> right, char op)
      : left_(std::move(left)), right_(std::move(right)),
        function_(kOps.at(op)) {}

  int Evaluate() const override {
    return function_(left_->Evaluate(), right_->Evaluate());
  }

private:
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
  Function function_;
};

class UnaryMinus : public Expression {
public:
  UnaryMinus(std::unique_ptr<Expression> expr) : expr_(std::move(expr)) {}

  int Evaluate() const override { return -expr_->Evaluate(); }

private:
  std::unique_ptr<Expression> expr_;
};

std::unique_ptr<Expression> ParseExpression(Tokenizer *tok);

std::unique_ptr<Expression> ParseMultiplier(Tokenizer *tok) {
  if (tok->GetType() == Tokenizer::kMinus) {
    tok->Consume();
    return std::make_unique<UnaryMinus>(ParseMultiplier(tok));
  }
  if (tok->GetType() == Tokenizer::kNumber) {
    auto expr = std::make_unique<Number>(tok->GetNumber());
    tok->Consume();
    return expr;
  }
  return ParseExpression(tok);
}

std::unique_ptr<Expression> ParseSummand(Tokenizer *tok) {
  auto expr = ParseMultiplier(tok);
  while (tok->GetType() == Tokenizer::kMul ||
         tok->GetType() == Tokenizer::kDiv) {
    auto op = tok->GetSymbol();
    tok->Consume();
    expr = std::make_unique<BinaryOperation>(std::move(expr),
                                             ParseMultiplier(tok), op);
  }
  return expr;
}

std::unique_ptr<Expression> ParseExpression(Tokenizer *tok) {
  tok->Consume();
  auto expr = ParseSummand(tok);
  while (tok->GetType() == Tokenizer::kPlus ||
         tok->GetType() == Tokenizer::kMinus) {
    auto op = tok->GetSymbol();
    tok->Consume();
    expr = std::make_unique<BinaryOperation>(std::move(expr), ParseSummand(tok),
                                             op);
  }
  tok->Consume();
  return expr;
}

class Solution {
public:
  static int calculate(std::string expresion) {
    std::istringstream istream{expresion};
    Tokenizer tok{&istream};
    return ParseExpression(&tok)->Evaluate();
  }
};
