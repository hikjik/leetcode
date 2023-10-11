#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    std::vector<int> people{2, 3, 7, 11};
    std::vector<int> expected{1, 2, 2, 2};
    REQUIRE(expected == Solution::fullBloomFlowers(flowers, people));
  }
  {
    std::vector<std::vector<int>> flowers{{1, 10}, {3, 3}};
    std::vector<int> people{3, 3, 2};
    std::vector<int> expected{2, 2, 1};
    REQUIRE(expected == Solution::fullBloomFlowers(flowers, people));
  }
}
