#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"alice", "bob", "charlie"},
          .s = "abc",
          .expected = true,
      },
      {
          .words{"an", "apple"},
          .s = "a",
          .expected = false,
      },
      {
          .words{"never", "gonna", "give", "up", "on", "you"},
          .s = "ngguoy",
          .expected = true,
      },
  };

  for (const auto &[words, s, expected] : test_cases) {
    const auto actual = Solution::isAcronym(words, s);
    REQUIRE(expected == actual);
  }
}
