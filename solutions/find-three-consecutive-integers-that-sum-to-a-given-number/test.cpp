#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    long long num;
    std::vector<long long> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 33,
          .expected{10, 11, 12},
      },
      {
          .num = 4,
          .expected{},
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::sumOfThree(num);
    REQUIRE(expected == actual);
  }
}
