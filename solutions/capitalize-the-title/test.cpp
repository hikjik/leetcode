#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string title;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .title = "capiTalIze tHe titLe",
          .expected = "Capitalize The Title",
      },
      {
          .title = "First leTTeR of EACH Word",
          .expected = "First Letter of Each Word",
      },
      {
          .title = "i lOve leetcode",
          .expected = "i Love Leetcode",
      },
  };

  for (const auto &[title, expected] : test_cases) {
    const auto actual = Solution::capitalizeTitle(title);
    REQUIRE(expected == actual);
  }
}
