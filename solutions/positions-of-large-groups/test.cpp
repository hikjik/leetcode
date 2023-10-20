#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abbxxxxzzy",
          .expected{{3, 6}},
      },
      {
          .s = "abc",
          .expected{},
      },
      {
          .s = "abcdddeeeeaabbbcd",
          .expected{{3, 5}, {6, 9}, {12, 14}},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::largeGroupPositions(s);
    REQUIRE(expected == actual);
  }
}
