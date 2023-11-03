#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> left;
    std::vector<int> right;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .left{4, 3},
          .right{0, 1},
          .expected = 4,
      },
      {
          .n = 7,
          .left{},
          .right{0, 1, 2, 3, 4, 5, 6, 7},
          .expected = 7,
      },
      {
          .n = 7,
          .left{0, 1, 2, 3, 4, 5, 6, 7},
          .right{},
          .expected = 7,
      },
  };

  for (const auto &[n, left, right, expected] : test_cases) {
    const auto actual = Solution::getLastMoment(n, left, right);
    REQUIRE(expected == actual);
  }
}
