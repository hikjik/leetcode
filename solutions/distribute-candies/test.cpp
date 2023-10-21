#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> candyType;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .candyType{1, 1, 2, 2, 3, 3},
          .expected = 3,
      },
      {
          .candyType{1, 1, 2, 3},
          .expected = 2,
      },
      {
          .candyType{6, 6, 6, 6},
          .expected = 1,
      },
  };

  for (const auto &[candyType, expected] : test_cases) {
    const auto actual = Solution::distributeCandies(candyType);
    REQUIRE(expected == actual);
  }
}
