#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int low;
    int high;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .low = 3,
          .high = 7,
          .expected = 3,
      },
      {
          .low = 8,
          .high = 10,
          .expected = 1,
      },
  };

  for (const auto &[low, high, expected] : test_cases) {
    const auto actual = Solution::countOdds(low, high);
    REQUIRE(expected == actual);
  }
}
