#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> bits;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bits{1, 0, 0},
          .expected = true,
      },
      {
          .bits{1, 1, 1, 0},
          .expected = false,
      },
  };

  for (const auto &[bits, expected] : test_cases) {
    const auto actual = Solution::isOneBitCharacter(bits);
    REQUIRE(expected == actual);
  }
}
