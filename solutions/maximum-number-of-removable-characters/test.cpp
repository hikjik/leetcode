#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string p;
    std::vector<int> removable;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcacb",
          .p = "ab",
          .removable{3, 1, 0},
          .expected = 2,
      },
      {
          .s = "abcbddddd",
          .p = "abcd",
          .removable{3, 2, 1, 4, 5, 6},
          .expected = 1,
      },
      {
          .s = "abcab",
          .p = "abc",
          .removable{0, 1, 2, 3, 4},
          .expected = 0,
      },
  };

  for (const auto &[s, p, removable, expected] : test_cases) {
    const auto actual = Solution::maximumRemovals(s, p, removable);
    REQUIRE(expected == actual);
  }
}
