#pragma once

#include <queue>
#include <vector>

template <class T> using Grid2D = std::vector<std::vector<T>>;

/*
  1905. Count Sub Islands
  https://leetcode.com/problems/count-sub-islands/
  Difficulty: Medium
  Tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
  Time:
  Space:
*/

class Graph {
private:
  using Cell = std::pair<size_t, size_t>;

  const int LAND = 1;
  const int WATER = 0;

  const Grid2D<int> &grid_;

public:
  Graph(const Grid2D<int> &grid) : grid_(grid) {}

  bool IsLand(size_t i, size_t j) const { return grid_[i][j] == LAND; }
  bool IsWater(size_t i, size_t j) const { return grid_[i][j] == WATER; }

  size_t Rows() const { return grid_.size(); }
  size_t Cols() const { return grid_.back().size(); }

  std::vector<Cell> AdjacentCells(size_t i, size_t j) const {
    std::vector<Cell> cells;
    if (i > 0) {
      cells.emplace_back(i - 1, j);
    }
    if (i + 1 < grid_.size()) {
      cells.emplace_back(i + 1, j);
    }
    if (j > 0) {
      cells.emplace_back(i, j - 1);
    }
    if (j + 1 < grid_.back().size()) {
      cells.emplace_back(i, j + 1);
    }
    return cells;
  }
};

template <typename Visitor>
void ExploreCell(size_t i, size_t j, const Graph &graph, Visitor visitor,
                 Grid2D<bool> *explored) {
  (*explored)[i][j] = true;

  visitor.DiscoverCell(i, j);
  for (const auto &[r, c] : graph.AdjacentCells(i, j)) {
    if (!(*explored)[r][c] && graph.IsLand(r, c)) {
      ExploreCell(r, c, graph, visitor, explored);
    }
  }
  visitor.FinishCell(i, j);
}

template <typename Visitor>
void TraverseGraphInDFSOrder(const Graph &graph, Visitor visitor) {
  Grid2D<bool> explored(graph.Rows(), std::vector<bool>(graph.Cols(), false));

  for (size_t i = 0; i < graph.Rows(); ++i) {
    for (size_t j = 0; j < graph.Cols(); ++j) {
      if (!explored[i][j] && graph.IsLand(i, j)) {
        visitor.StartCell(i, j);
        ExploreCell(i, j, graph, visitor, &explored);
        visitor.EndCell(i, j);
      }
    }
  }
}

template <typename Visitor>
void TraverseGraphInBFSOrder(const Graph &graph, Visitor visitor) {
  Grid2D<bool> explored(graph.Rows(), std::vector<bool>(graph.Cols(), false));
  std::queue<std::pair<size_t, size_t>> queue;

  for (size_t i = 0; i < graph.Rows(); ++i) {
    for (size_t j = 0; j < graph.Cols(); ++j) {
      if (!explored[i][j] && graph.IsLand(i, j)) {
        visitor.StartCell(i, j);

        queue.emplace(i, j);
        explored[i][j] = true;
        while (!queue.empty()) {
          const auto [i, j] = queue.front();
          queue.pop();
          visitor.DiscoverCell(i, j);
          for (auto [r, c] : graph.AdjacentCells(i, j)) {
            if (!explored[r][c] && graph.IsLand(r, c)) {
              queue.emplace(r, c);
              explored[r][c] = true;
            }
          }
        }

        visitor.EndCell(i, j);
      }
    }
  }
}

class DepthFirstSearchVisitor {
public:
  virtual ~DepthFirstSearchVisitor() = default;
  virtual void StartCell(size_t, size_t) = 0;
  virtual void EndCell(size_t, size_t) = 0;
  virtual void DiscoverCell(size_t, size_t) = 0;
  virtual void FinishCell(size_t, size_t) = 0;
};

class SubIslandsCounter {
private:
  size_t total_;
  bool status_;

public:
  SubIslandsCounter() : total_(0), status_(false) {}

  size_t GetTotal() const { return total_; }

  void SetIslandStatus(bool status) { status_ = status; }
  void UpdateTotal() { total_ += status_; }
};

class SubIslandsVisitor : public DepthFirstSearchVisitor {
private:
  const Graph &graph_;
  SubIslandsCounter *counter_;

public:
  SubIslandsVisitor(const Graph &graph, SubIslandsCounter *counter)
      : graph_(graph), counter_(counter) {}

  void StartCell(size_t, size_t) override { counter_->SetIslandStatus(true); }
  void EndCell(size_t, size_t) override { counter_->UpdateTotal(); }
  void DiscoverCell(size_t i, size_t j) override {
    if (graph_.IsWater(i, j)) {
      counter_->SetIslandStatus(false);
    }
  }
  void FinishCell(size_t, size_t) override {}
};

class Solution {
public:
  static int countSubIslands(const Grid2D<int> &grid1,
                             const Grid2D<int> &grid2) {
    const Graph graph1(grid1);
    const Graph graph2(grid2);

    SubIslandsCounter counter;
    SubIslandsVisitor visitor(graph1, &counter);
    TraverseGraphInBFSOrder(graph2, visitor);
    return counter.GetTotal();
  }
};
