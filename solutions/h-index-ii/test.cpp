#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> citations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .citations{0, 1, 3, 5, 6},
          .expected = 3,
      },
      {
          .citations{1, 2, 100},
          .expected = 2,
      },
  };

  for (const auto &[citations, expected] : test_cases) {
    const auto actual = Solution::hIndex(citations);
    REQUIRE(expected == actual);
  }
}
