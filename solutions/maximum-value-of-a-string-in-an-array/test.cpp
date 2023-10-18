#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"alic3", "bob", "3", "4", "00000"},
          .expected = 5,
      },
      {
          .strs{"1", "01", "001", "0001"},
          .expected = 1,
      },
  };

  for (const auto &[strs, expected] : test_cases) {
    const auto actual = Solution::maximumValue(strs);
    REQUIRE(expected == actual);
  }
}
