#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numOnes;
    int numZeros;
    int numNegOnes;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numOnes = 3,
          .numZeros = 2,
          .numNegOnes = 0,
          .k = 2,
          .expected = 2,
      },
      {
          .numOnes = 3,
          .numZeros = 2,
          .numNegOnes = 0,
          .k = 4,
          .expected = 3,
      },
  };

  for (const auto &[numOnes, numZeros, numNegOnes, k, expected] : test_cases) {
    const auto actual =
        Solution::kItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);
    REQUIRE(expected == actual);
  }
}
