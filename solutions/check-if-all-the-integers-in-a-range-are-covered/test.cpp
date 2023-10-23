#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> ranges;
    int left;
    int right;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .ranges{{1, 2}, {3, 4}, {5, 6}},
          .left = 2,
          .right = 5,
          .expected = true,
      },
      {
          .ranges{{1, 10}, {10, 20}},
          .left = 21,
          .right = 21,
          .expected = false,
      },
  };

  for (const auto &[ranges, left, right, expected] : test_cases) {
    const auto actual = Solution::isCovered(ranges, left, right);
    REQUIRE(expected == actual);
  }
}
