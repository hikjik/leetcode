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
          .k = 27,
          .expected = "aay",
      },
      {
          .n = 5,
          .k = 73,
          .expected = "aaszz",
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::getSmallestString(n, k);
    REQUIRE(expected == actual);
  }
}
