#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"flower", "flow", "flight"},
          .expected = "fl",
      },
      {
          .strs{"dog", "racecar", "car"},
          .expected = "",
      },
  };

  for (const auto &[strs, expected] : test_cases) {
    const auto actual = Solution::longestCommonPrefix(strs);
    REQUIRE(expected == actual);
  }
}
