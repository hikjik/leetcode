#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{10, 1, 2, 7, 1, 3};
    int p = 2;
    REQUIRE(1 == Solution().minimizeMax(nums, p));
  }
  {
    std::vector<int> nums{4, 2, 1, 2};
    int p = 1;
    REQUIRE(0 == Solution().minimizeMax(nums, p));
  }
  {
    std::vector<int> nums{50};
    int p = 0;
    REQUIRE(0 == Solution().minimizeMax(nums, p));
  }
}
