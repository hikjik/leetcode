#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> flowerbed;
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .flowerbed{1, 0, 0, 0, 1},
          .n = 1,
          .expected = true,
      },
      {
          .flowerbed{1, 0, 0, 0, 1},
          .n = 2,
          .expected = false,
      },
  };

  for (const auto &[flowerbed, n, expected] : test_cases) {
    const auto actual = Solution::canPlaceFlowers(flowerbed, n);
    REQUIRE(expected == actual);
  }
}
