#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .expected = 2,
      },
      {
          .n = 7,
          .expected = 0,
      },
      {
          .n = 10,
          .expected = 5,
      },
      {
          .n = 0,
          .expected = 1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::bitwiseComplement(n);
    REQUIRE(expected == actual);
  }
}
