#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = 2,
      },
      {
          .n = 100,
          .expected = 14,
      },
  };

  SECTION("Binary Search") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = binary_search::Solution::twoEggDrop(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Math") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = math::Solution::twoEggDrop(n);
      REQUIRE(expected == actual);
    }
  }
}
