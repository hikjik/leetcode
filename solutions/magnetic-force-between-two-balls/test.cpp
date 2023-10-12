#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> position;
    int m;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .position{1, 2, 3, 4, 7},
          .m = 3,
          .expected = 3,
      },
      {
          .position{5, 4, 3, 2, 1, 1000000000},
          .m = 2,
          .expected = 999999999,
      },
  };

  for (const auto &[position, m, expected] : test_cases) {
    const auto actual = Solution::maxDistance(position, m);
    REQUIRE(expected == actual);
  }
}
