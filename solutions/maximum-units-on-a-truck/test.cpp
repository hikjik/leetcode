#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> boxTypes;
    int truckSize;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .boxTypes{{1, 3}, {2, 2}, {3, 1}},
          .truckSize = 4,
          .expected = 8,
      },
      {
          .boxTypes{{5, 10}, {2, 5}, {4, 7}, {3, 9}},
          .truckSize = 10,
          .expected = 91,
      },
  };

  for (const auto &[boxTypes, truckSize, expected] : test_cases) {
    const auto actual = Solution::maximumUnits(boxTypes, truckSize);
    REQUIRE(expected == actual);
  }
}
