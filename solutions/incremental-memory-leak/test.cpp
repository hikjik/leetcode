#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int memory1;
    int memory2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .memory1 = 2,
          .memory2 = 2,
          .expected{3, 1, 0},
      },
      {
          .memory1 = 8,
          .memory2 = 11,
          .expected{6, 0, 4},
      },
  };

  for (const auto &[memory1, memory2, expected] : test_cases) {
    const auto actual = Solution::memLeak(memory1, memory2);
    REQUIRE(expected == actual);
  }
}
