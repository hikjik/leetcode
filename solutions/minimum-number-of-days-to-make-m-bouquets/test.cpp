#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 1, m = 3;
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    REQUIRE(3 == Solution::minDays(bloom_days, m, k));
  }
  {
    int k = 2, m = 3;
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    REQUIRE(-1 == Solution::minDays(bloom_days, m, k));
  }
  {
    int k = 3, m = 2;
    std::vector<int> bloom_days{7, 7, 7, 7, 12, 7, 7};
    REQUIRE(12 == Solution::minDays(bloom_days, m, k));
  }
}
