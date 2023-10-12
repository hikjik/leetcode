#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> pizza;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pizza{"A..", "AAA", "..."},
          .k = 3,
          .expected = 3,
      },
      {
          .pizza{"A..", "AA.", "..."},
          .k = 3,
          .expected = 1,
      },
      {
          .pizza{"A..", "A..", "..."},
          .k = 1,
          .expected = 1,
      },
  };

  for (const auto &[pizza, k, expected] : test_cases) {
    const auto actual = Solution::ways(pizza, k);
    REQUIRE(expected == actual);
  }
}
