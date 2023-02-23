#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> profits{1, 2, 3};
    std::vector<int> capital{0, 1, 1};
    int k = 2, w = 0;
    REQUIRE(4 == Solution::findMaximizedCapital(k, w, profits, capital));
  }
  {
    std::vector<int> profits{1, 2, 3};
    std::vector<int> capital{0, 1, 2};
    int k = 3, w = 0;
    REQUIRE(6 == Solution::findMaximizedCapital(k, w, profits, capital));
  }
  {
    std::vector<int> profits{1, 2, 3};
    std::vector<int> capital{1, 1, 2};
    int k = 1, w = 0;
    REQUIRE(0 == Solution::findMaximizedCapital(k, w, profits, capital));
  }
}
