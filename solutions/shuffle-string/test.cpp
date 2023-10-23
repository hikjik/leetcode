#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<int> indices;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "codeleet",
          .indices{4, 5, 6, 7, 0, 2, 1, 3},
          .expected = "leetcode",
      },
      {
          .s = "abc",
          .indices{0, 1, 2},
          .expected = "abc",
      },
  };

  for (const auto &[s, indices, expected] : test_cases) {
    const auto actual = Solution::restoreString(s, indices);
    REQUIRE(expected == actual);
  }
}
