#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> plantTime;
    std::vector<int> growTime;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .plantTime{1, 4, 3},
          .growTime{2, 3, 1},
          .expected = 9,
      },
      {
          .plantTime{1, 2, 3, 2},
          .growTime{2, 1, 2, 1},
          .expected = 9,
      },
      {
          .plantTime{1},
          .growTime{1},
          .expected = 2,
      },
  };

  for (const auto &[plantTime, growTime, expected] : test_cases) {
    const auto actual = Solution::earliestFullBloom(plantTime, growTime);
    REQUIRE(expected == actual);
  }
}
