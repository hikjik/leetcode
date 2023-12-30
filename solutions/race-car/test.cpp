#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target = 127,
          .expected = 7,
      },
      {
          .target = 6,
          .expected = 5,
      },
      {
          .target = 5,
          .expected = 7,
      },
      {
          .target = 11,
          .expected = 10,
      },
      {
          .target = 12,
          .expected = 7,
      },
  };

  for (const auto &[target, expected] : test_cases) {
    const auto actual = Solution::racecar(target);
    REQUIRE(expected == actual);
  }
}
