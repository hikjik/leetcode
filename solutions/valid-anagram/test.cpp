#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "anagram",
          .t = "nagaram",
          .expected = true,
      },
      {
          .s = "rat",
          .t = "car",
          .expected = false,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::isAnagram(s, t);
    REQUIRE(expected == actual);
  }
}
