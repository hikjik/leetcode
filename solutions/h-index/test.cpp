#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> citations{3, 0, 6, 1, 5};
    REQUIRE(3 == Solution::hIndex(citations));
  }
  {
    std::vector<int> citations{100, 0, 2};
    REQUIRE(2 == Solution::hIndex(citations));
  }
  {
    std::vector<int> citations{1, 3, 1};
    REQUIRE(1 == Solution::hIndex(citations));
  }
  {
    std::vector<int> citations{0, 0, 0, 0};
    REQUIRE(0 == Solution::hIndex(citations));
  }
  {
    std::vector<int> citations{1, 1, 1, 1};
    REQUIRE(1 == Solution::hIndex(citations));
  }
}
