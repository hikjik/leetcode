#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int left;
    int right;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .left = 5,
          .right = 7,
          .expected = 4,
      },
      {
          .left = 0,
          .right = 0,
          .expected = 0,
      },
      {
          .left = 1,
          .right = 2147483647,
          .expected = 0,
      },
  };

  for (const auto &[left, right, expected] : test_cases) {
    const auto actual = Solution::rangeBitwiseAnd(left, right);
    REQUIRE(expected == actual);
  }
}
