#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> arrays;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arrays{{1, 5}, {3, 4}},
          .expected = 3,
      },
      {
          .arrays{{1, 2, 3}, {4, 5}, {1, 2, 3}},
          .expected = 4,
      },
      {
          .arrays{{1}, {1}},
          .expected = 0,
      },
  };

  for (const auto &[arrays, expected] : test_cases) {
    const auto actual = Solution::maxDistance(arrays);
    REQUIRE(expected == actual);
  }
}
