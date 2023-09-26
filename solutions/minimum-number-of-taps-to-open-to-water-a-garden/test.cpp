#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 5;
    std::vector<int> ranges{3, 4, 1, 1, 0, 0};
    REQUIRE(1 == Solution::minTaps(n, ranges));
  }
  {
    int n = 3;
    std::vector<int> ranges{0, 0, 0, 0};
    REQUIRE(-1 == Solution::minTaps(n, ranges));
  }
  {
    int n = 5;
    std::vector<int> ranges{4, 1, 1, 1, 1, 1};
    REQUIRE(2 == Solution::minTaps(n, ranges));
  }
}
