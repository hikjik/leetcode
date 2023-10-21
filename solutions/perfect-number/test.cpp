#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 28,
          .expected = true,
      },
      {
          .num = 7,
          .expected = false,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::checkPerfectNumber(num);
    REQUIRE(expected == actual);
  }
}
