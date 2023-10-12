#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "tree",
          .expected = "eert",
      },
      {
          .s = "cccaaa",
          .expected = "aaaccc",
      },
      {
          .s = "Aabb",
          .expected = "bbAa",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::frequencySort(s);
    REQUIRE(expected == actual);
  }
}
