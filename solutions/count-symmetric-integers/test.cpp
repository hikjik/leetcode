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
          .low = 1,
          .high = 100,
          .expected = 9,
      },
      {
          .low = 1200,
          .high = 1230,
          .expected = 4,
      },
  };

  for (const auto &[low, high, expected] : test_cases) {
    const auto actual = Solution::countSymmetricIntegers(low, high);
    REQUIRE(expected == actual);
  }
}
