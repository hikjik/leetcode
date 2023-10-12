#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums{4, 5, 8, 2};
    auto kth_largest = KthLargest(k, nums);

    REQUIRE(4 == kth_largest.add(3));
    REQUIRE(5 == kth_largest.add(5));
    REQUIRE(5 == kth_largest.add(10));
    REQUIRE(8 == kth_largest.add(9));
    REQUIRE(8 == kth_largest.add(4));
  }
}
