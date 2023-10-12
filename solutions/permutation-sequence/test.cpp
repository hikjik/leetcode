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
          .n = 3,
          .k = 3,
          .expected = "213",
      },
      {
          .n = 4,
          .k = 9,
          .expected = "2314",
      },
      {
          .n = 3,
          .k = 1,
          .expected = "123",
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::getPermutation(n, k);
    REQUIRE(expected == actual);
  }
}
