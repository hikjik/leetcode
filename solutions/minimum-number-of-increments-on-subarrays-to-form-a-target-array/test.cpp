#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target{1, 2, 3, 2, 1},
          .expected = 3,
      },
      {
          .target{3, 1, 1, 2},
          .expected = 4,
      },
      {
          .target{3, 1, 5, 4, 2},
          .expected = 7,
      },
  };

  for (const auto &[target, expected] : test_cases) {
    const auto actual = Solution::minNumberOperations(target);
    REQUIRE(expected == actual);
  }
}
