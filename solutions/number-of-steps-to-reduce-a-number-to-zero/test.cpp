#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 14,
          .expected = 6,
      },
      {
          .num = 8,
          .expected = 4,
      },
      {
          .num = 123,
          .expected = 12,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::numberOfSteps(num);
    REQUIRE(expected == actual);
  }
}
