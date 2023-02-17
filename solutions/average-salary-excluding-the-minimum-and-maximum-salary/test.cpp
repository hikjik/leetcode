#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{4000, 3000, 1000, 2000};
    REQUIRE_THAT(Solution::average(nums),
                 Catch::Matchers::WithinAbs(2500.00000, 1e5));
  }
  {
    std::vector<int> nums{1000, 2000, 3000};
    REQUIRE_THAT(Solution::average(nums),
                 Catch::Matchers::WithinAbs(2000.00000, 1e5));
  }
}
