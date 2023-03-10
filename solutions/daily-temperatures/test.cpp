#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected{1, 1, 4, 2, 1, 1, 0, 0};
    REQUIRE(expected == Solution::dailyTemperatures(temperatures));
  }
  {
    std::vector<int> temperatures{30, 40, 50, 60};
    std::vector<int> expected{1, 1, 1, 0};
    REQUIRE(expected == Solution::dailyTemperatures(temperatures));
  }
  {
    std::vector<int> temperatures{90, 60, 30};
    std::vector<int> expected{0, 0, 0};
    REQUIRE(expected == Solution::dailyTemperatures(temperatures));
  }
}
