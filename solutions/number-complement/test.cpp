#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 5,
          .expected = 2,
      },
      {
          .num = 1,
          .expected = 0,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::findComplement(num);
    REQUIRE(expected == actual);
  }
}
