#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected{0, 1, 3, 2},
      },
      {
          .n = 1,
          .expected{0, 1},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::grayCode(n);
    REQUIRE(expected == actual);
  }
}
