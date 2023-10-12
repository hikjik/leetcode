#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> flowers;
    std::vector<int> people;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}},
          .people{2, 3, 7, 11},
          .expected{1, 2, 2, 2},
      },
      {
          .flowers{{1, 10}, {3, 3}},
          .people{3, 3, 2},
          .expected{2, 2, 1},
      },
  };

  for (const auto &[flowers, people, expected] : test_cases) {
    const auto actual = Solution::fullBloomFlowers(flowers, people);
    REQUIRE(expected == actual);
  }
}
