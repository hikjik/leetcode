#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 5, 2};
    std::vector<int> cost{2, 3, 1, 14};
    REQUIRE(8 == Solution::minCost(nums, cost));
  }
  {
    std::vector<int> nums{2, 2, 2, 2, 2};
    std::vector<int> cost{4, 2, 8, 1, 3};
    REQUIRE(0 == Solution::minCost(nums, cost));
  }
  {
    std::vector<int> nums{735103, 366367, 132236, 133334, 808160, 113001,
                          49051,  735598, 686615, 665317, 999793, 426087,
                          587000, 649989, 509946, 743518};
    std::vector<int> cost{724182, 447415, 723725, 902336, 600863, 287644,
                          13836,  665183, 448859, 917248, 397790, 898215,
                          790754, 320604, 468575, 825614};
    REQUIRE(1907611126748 == Solution::minCost(nums, cost));
  }
}
