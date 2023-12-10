#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> batteryPercentages;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .batteryPercentages{1, 1, 2, 1, 3},
          .expected = 3,
      },
      {
          .batteryPercentages{0, 1, 2},
          .expected = 2,
      },
  };

  for (const auto &[batteryPercentages, expected] : test_cases) {
    const auto actual = Solution::countTestedDevices(batteryPercentages);
    REQUIRE(expected == actual);
  }
}
