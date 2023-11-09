#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    uint32_t n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 11,
          .expected = 3,
      },
      {
          .n = 128,
          .expected = 1,
      },
      {
          .n = 4294967293,
          .expected = 31,
      },
  };

  SECTION("Naive") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = naive::Solution::hammingWeight(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Builtin") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = builtin::Solution::hammingWeight(n);
      REQUIRE(expected == actual);
    }
  }
}
