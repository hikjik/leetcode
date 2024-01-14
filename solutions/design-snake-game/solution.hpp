#pragma once

#include <queue>
#include <string>
#include <vector>

// Time: O(Q+WH)
// Space: O(WH+N)

class SnakeGame {
public:
  // O(WH)
  SnakeGame(int width, int height, std::vector<std::vector<int>> food)
      : busy(height * width), snake{{0}}, food(std::move(food)), height(height),
        width(width) {
    busy[0] = true;
  }

  //  O(1)
  int move(std::string direction) {
    auto i = snake.back() / width, j = snake.back() % width;
    if (direction == "L" && --j < 0) {
      return -1;
    }
    if (direction == "R" && ++j >= width) {
      return -1;
    }
    if (direction == "U" && --i < 0) {
      return -1;
    }
    if (direction == "D" && ++i >= height) {
      return -1;
    }

    if (k < std::ssize(food) && food[k][0] == i && food[k][1] == j) {
      ++k;
    } else {
      busy[snake.front()] = false;
      snake.pop();
    }
    const auto head = i * width + j;
    if (busy[head]) {
      return -1;
    }
    busy[head] = true;
    snake.push(head);
    return k;
  }

private:
  std::vector<bool> busy;
  std::queue<int> snake;
  std::vector<std::vector<int>> food;
  int height, width;
  int k = 0;
};
