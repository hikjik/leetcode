#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 7, 7, 7, 10, 7, 7, 7},
          .expected = 4,
      },
      {
          .nums{6, 6, 12},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    ArrayReader reader(nums);
    const auto actual = Solution::getIndex(reader);
    REQUIRE(expected == actual);
    REQUIRE(reader.numOfCalls() <= 20);
  }
}
