#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{1, 3}, {-2, 2}},
          .k = 1,
          .expected{{-2, 2}},
      },
      {
          .points{{3, 3}, {5, -1}, {-2, 4}},
          .k = 2,
          .expected{{-2, 4}, {3, 3}},
      },
  };

  for (const auto &[points, k, expected] : test_cases) {
    const auto actual = Solution::kClosest(points, k);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
