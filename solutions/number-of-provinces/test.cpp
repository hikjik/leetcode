#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> isConnected;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .isConnected{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}},
          .expected = 2,
      },
      {
          .isConnected{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
          .expected = 3,
      },
  };

  for (const auto &[isConnected, expected] : test_cases) {
    const auto actual = Solution::findCircleNum(isConnected);
    REQUIRE(expected == actual);
  }
}
