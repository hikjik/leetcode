#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{4, 4, 4, 5, 6};
    REQUIRE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{4, 4, 4, 10, 10, 1, 2, 3, 9, 9};
    REQUIRE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{4, 4, 4, 10, 10, 1, 2, 3, 50, 9, 9};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 1, 1, 2};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 2};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 1};
    REQUIRE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 1, 1};
    REQUIRE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{1, 1, 2};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
  {
    std::vector<int> nums{993335, 993336, 993337, 993338,
                          993339, 993340, 993341};
    REQUIRE_FALSE(Solution::validPartition(nums));
  }
}
