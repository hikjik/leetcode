#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int candies;
    int num_people;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .candies = 7,
          .num_people = 4,
          .expected{1, 2, 3, 1},
      },
      {
          .candies = 10,
          .num_people = 3,
          .expected{5, 2, 3},
      },
  };

  for (const auto &[candies, num_people, expected] : test_cases) {
    const auto actual = Solution::distributeCandies(candies, num_people);
    REQUIRE(expected == actual);
  }
}
