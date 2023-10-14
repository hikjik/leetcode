#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    char separator;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"one.two.three", "four.five", "six"},
          .separator = '.',
          .expected{"one", "two", "three", "four", "five", "six"},
      },
      {
          .words{"$easy$", "$problem$"},
          .separator = '$',
          .expected{"easy", "problem"},
      },
      {
          .words{"|||"},
          .separator = '|',
          .expected{},
      },
  };

  for (const auto &[words, separator, expected] : test_cases) {
    const auto actual = Solution::splitWordsBySeparator(words, separator);
    REQUIRE(expected == actual);
  }
}
