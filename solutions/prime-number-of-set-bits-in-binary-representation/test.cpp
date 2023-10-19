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
          .left = 6,
          .right = 10,
          .expected = 4,
      },
      {
          .left = 10,
          .right = 15,
          .expected = 5,
      },
  };

  for (const auto &[left, right, expected] : test_cases) {
    const auto actual = Solution::countPrimeSetBits(left, right);
    REQUIRE(expected == actual);
  }
}
