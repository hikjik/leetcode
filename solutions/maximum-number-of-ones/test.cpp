#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int width;
    int height;
    int sideLength;
    int maxOnes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .width = 3,
          .height = 3,
          .sideLength = 2,
          .maxOnes = 1,
          .expected = 4,
      },
      {
          .width = 3,
          .height = 3,
          .sideLength = 2,
          .maxOnes = 2,
          .expected = 6,
      },
  };

  for (const auto &[width, height, sideLength, maxOnes, expected] :
       test_cases) {
    const auto actual =
        Solution::maximumNumberOfOnes(width, height, sideLength, maxOnes);
    REQUIRE(expected == actual);
  }
}
