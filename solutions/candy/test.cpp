#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> ratings;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .ratings{1, 0, 2},
          .expected = 5,
      },
      {
          .ratings{1, 2, 2},
          .expected = 4,
      },
  };

  for (const auto &[ratings, expected] : test_cases) {
    const auto actual = Solution::candy(ratings);
    REQUIRE(expected == actual);
  }
}
