#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> sticks;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sticks{2, 4, 3},
          .expected = 14,
      },
      {
          .sticks{1, 8, 3, 5},
          .expected = 30,
      },
      {
          .sticks{5},
          .expected = 0,
      },
  };

  for (const auto &[sticks, expected] : test_cases) {
    const auto actual = Solution::connectSticks(sticks);
    REQUIRE(expected == actual);
  }
}
