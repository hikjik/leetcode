#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string a;
    std::string b;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "isawsquirrelnearmysquirrelhouseohmy",
          .a = "my",
          .b = "squirrel",
          .k = 15,
          .expected{16, 33},
      },
      {
          .s = "abcd",
          .a = "a",
          .b = "a",
          .k = 4,
          .expected{0},
      },
  };

  for (const auto &[s, a, b, k, expected] : test_cases) {
    const auto actual = Solution::beautifulIndices(s, a, b, k);
    REQUIRE(expected == actual);
  }
}
