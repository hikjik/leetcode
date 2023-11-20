#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Fenwick Tree") {
  std::vector<int> nums{1, 3, 5};
  fenwick_tree::NumArray array(nums);

  REQUIRE(9 == array.sumRange(0, 2));
  array.update(1, 2);
  REQUIRE(8 == array.sumRange(0, 2));
}

TEST_CASE("Segment Tree") {
  std::vector<int> nums{1, 3, 5};
  segment_tree::NumArray array(nums);

  REQUIRE(9 == array.sumRange(0, 2));
  array.update(1, 2);
  REQUIRE(8 == array.sumRange(0, 2));
}
