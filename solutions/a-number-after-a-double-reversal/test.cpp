#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 526,
          .expected = true,
      },
      {
          .num = 1800,
          .expected = false,
      },
      {
          .num = 0,
          .expected = true,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::isSameAfterReversals(num);
    REQUIRE(expected == actual);
  }
}
