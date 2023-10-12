#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "cba",
          .k = 1,
          .expected = "acb",
      },
      {
          .s = "baaca",
          .k = 3,
          .expected = "aaabc",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::orderlyQueue(s, k);
    REQUIRE(expected == actual);
  }
}
