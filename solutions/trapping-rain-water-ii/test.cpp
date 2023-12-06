#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> heightMap;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heightMap{
              {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}},
          .expected = 4,
      },
      {
          .heightMap{{3, 3, 3, 3, 3},
                     {3, 2, 2, 2, 3},
                     {3, 2, 1, 2, 3},
                     {3, 2, 2, 2, 3},
                     {3, 3, 3, 3, 3}},
          .expected = 10,
      },
  };

  for (const auto &[heightMap, expected] : test_cases) {
    const auto actual = Solution::trapRainWater(heightMap);
    REQUIRE(expected == actual);
  }
}
