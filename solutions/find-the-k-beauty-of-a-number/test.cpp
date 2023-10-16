#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 240,
          .k = 2,
          .expected = 2,
      },
      {
          .num = 430043,
          .k = 2,
          .expected = 2,
      },
  };

  for (const auto &[num, k, expected] : test_cases) {
    const auto actual = Solution::divisorSubstrings(num, k);
    REQUIRE(expected == actual);
  }
}
