#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> plants;
    int capacity;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .plants{2, 2, 3, 3},
          .capacity = 5,
          .expected = 14,
      },
      {
          .plants{1, 1, 1, 4, 2, 3},
          .capacity = 4,
          .expected = 30,
      },
      {
          .plants{7, 7, 7, 7, 7, 7, 7},
          .capacity = 8,
          .expected = 49,
      },
  };

  for (const auto &[plants, capacity, expected] : test_cases) {
    const auto actual = Solution::wateringPlants(plants, capacity);
    REQUIRE(expected == actual);
  }
}
