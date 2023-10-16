#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .expected = "1211",
      },
      {
          .n = 1,
          .expected = "1",
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countAndSay(n);
    REQUIRE(expected == actual);
  }
}
