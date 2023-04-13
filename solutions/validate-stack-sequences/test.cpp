#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> pushed{1, 2, 3, 4, 5};
    std::vector<int> popped{4, 5, 3, 2, 1};
    REQUIRE(Solution::validateStackSequences(pushed, popped));
  }
  {
    std::vector<int> pushed{1, 2, 3, 4, 5};
    std::vector<int> popped{4, 3, 5, 1, 2};
    REQUIRE_FALSE(Solution::validateStackSequences(pushed, popped));
  }
}
