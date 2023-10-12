#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 234,
          .expected = 15,
      },
      {
          .n = 4421,
          .expected = 21,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::subtractProductAndSum(n);
    REQUIRE(expected == actual);
  }
}
