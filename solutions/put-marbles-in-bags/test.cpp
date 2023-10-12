#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> weights;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .weights{1, 3, 5, 1},
          .k = 2,
          .expected = 4,
      },
      {
          .weights{1, 3},
          .k = 2,
          .expected = 0,
      },
  };

  for (const auto &[weights, k, expected] : test_cases) {
    const auto actual = Solution::putMarbles(weights, k);
    REQUIRE(expected == actual);
  }
}
