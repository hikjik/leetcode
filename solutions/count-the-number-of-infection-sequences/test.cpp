#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> sick;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .sick{0, 1},
          .expected = 1,
      },
      {
          .n = 5,
          .sick{0, 4},
          .expected = 4,
      },
      {
          .n = 4,
          .sick{1},
          .expected = 3,
      },
  };

  for (const auto &[n, sick, expected] : test_cases) {
    const auto actual = Solution::numberOfSequence(n, sick);
    REQUIRE(expected == actual);
  }
}
