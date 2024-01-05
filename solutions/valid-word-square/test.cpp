#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abcd", "bnrt", "crmy", "dtye"},
          .expected = true,
      },
      {
          .words{"abcd", "bnrt", "crm", "dt"},
          .expected = true,
      },
      {
          .words{"ball", "area", "read", "lady"},
          .expected = false,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::validWordSquare(words);
    REQUIRE(expected == actual);
  }
}
