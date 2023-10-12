#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> stoneValue;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .stoneValue{1, 2, 3, 7},
          .expected = "Bob",
      },
      {
          .stoneValue{1, 2, 3, -9},
          .expected = "Alice",
      },
      {
          .stoneValue{1, 2, 3, 6},
          .expected = "Tie",
      },
  };

  for (const auto &[stoneValue, expected] : test_cases) {
    const auto actual = Solution().stoneGameIII(stoneValue);
    REQUIRE(expected == actual);
  }
}
