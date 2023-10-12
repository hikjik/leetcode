#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 12,
          .expected = 21,
      },
      {
          .n = 21,
          .expected = -1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::nextGreaterElement(n);
    REQUIRE(expected == actual);
  }
}
