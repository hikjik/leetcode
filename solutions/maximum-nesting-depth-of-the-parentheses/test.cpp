#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "(1+(2*3)+((8)/4))+1",
          .expected = 3,
      },
      {
          .s = "(1)+((2))+(((3)))",
          .expected = 3,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maxDepth(s);
    REQUIRE(expected == actual);
  }
}
