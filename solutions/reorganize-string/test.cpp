#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aab",
          .expected = "aba",
      },
      {
          .s = "aaab",
          .expected = "",
      },
  };

  for (auto &[s, expected] : test_cases) {
    auto actual = Solution::reorganizeString(s);
    if (expected.empty()) {
      REQUIRE("" == actual);
    } else {
      for (size_t i = 0; i + 1 < actual.size(); ++i) {
        REQUIRE(actual[i] != actual[i + 1]);
      }

      std::sort(actual.begin(), actual.end());
      std::sort(expected.begin(), expected.end());
      REQUIRE(expected == actual);
    }
  }
}
