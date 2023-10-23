#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> encoded;
    int first;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .encoded{1, 2, 3},
          .first = 1,
          .expected{1, 0, 2, 1},
      },
      {
          .encoded{6, 2, 7, 3},
          .first = 4,
          .expected{4, 2, 0, 7, 4},
      },
  };

  for (const auto &[encoded, first, expected] : test_cases) {
    const auto actual = Solution::decode(encoded, first);
    REQUIRE(expected == actual);
  }
}
