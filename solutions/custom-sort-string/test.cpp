#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string order;
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .order = "cba",
          .s = "abcd",
          .expected = "cbad",
      },
      {
          .order = "cbafg",
          .s = "abcd",
          .expected = "cbad",
      },
  };

  SECTION("Sorting") {
    for (const auto &[order, s, expected] : test_cases) {
      const auto actual = sorting::Solution::customSortString(order, s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[order, s, expected] : test_cases) {
      const auto actual = counting::Solution::customSortString(order, s);
      REQUIRE(expected == actual);
    }
  }
}
