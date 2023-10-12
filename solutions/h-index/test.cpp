#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> citations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .citations{3, 0, 6, 1, 5},
          .expected = 3,
      },
      {
          .citations{1, 3, 1},
          .expected = 1,
      },
  };

  for (const auto &[citations, expected] : test_cases) {
    const auto actual = Solution::hIndex(citations);
    REQUIRE(expected == actual);
  }
}
