#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int primeOne;
    int primeTwo;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .primeOne = 2,
          .primeTwo = 5,
          .expected = 3,
      },
      {
          .primeOne = 5,
          .primeTwo = 7,
          .expected = 23,
      },
  };

  for (const auto &[primeOne, primeTwo, expected] : test_cases) {
    const auto actual = Solution::mostExpensiveItem(primeOne, primeTwo);
    REQUIRE(expected == actual);
  }
}
