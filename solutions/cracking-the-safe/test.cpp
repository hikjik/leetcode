#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .k = 2,
          .expected = "10",
      },
      {
          .n = 2,
          .k = 2,
          .expected = "01100",
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::crackSafe(n, k);
    REQUIRE(expected == actual);
  }
}
