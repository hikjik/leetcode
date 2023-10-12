#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string ransomNote;
    std::string magazine;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .ransomNote = "a",
          .magazine = "b",
          .expected = false,
      },
      {
          .ransomNote = "aa",
          .magazine = "ab",
          .expected = false,
      },
      {
          .ransomNote = "aa",
          .magazine = "aab",
          .expected = true,
      },
  };

  for (const auto &[ransomNote, magazine, expected] : test_cases) {
    const auto actual = Solution::canConstruct(ransomNote, magazine);
    REQUIRE(expected == actual);
  }
}
