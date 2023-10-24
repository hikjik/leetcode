#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 9669,
          .expected = 9969,
      },
      {
          .num = 9996,
          .expected = 9999,
      },
      {
          .num = 9999,
          .expected = 9999,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::maximum69Number(num);
    REQUIRE(expected == actual);
  }
}
