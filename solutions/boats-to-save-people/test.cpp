#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> people;
    int limit;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .people{1, 2},
          .limit = 3,
          .expected = 1,
      },
      {
          .people{3, 2, 2, 1},
          .limit = 3,
          .expected = 3,
      },
      {
          .people{3, 5, 3, 4},
          .limit = 5,
          .expected = 4,
      },
  };

  for (const auto &[people, limit, expected] : test_cases) {
    const auto actual = Solution::numRescueBoats(people, limit);
    REQUIRE(expected == actual);
  }
}
