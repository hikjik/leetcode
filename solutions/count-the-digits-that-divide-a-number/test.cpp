#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 7,
          .expected = 1,
      },
      {
          .num = 121,
          .expected = 2,
      },
      {
          .num = 1248,
          .expected = 4,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::countDigits(num);
    REQUIRE(expected == actual);
  }
}
