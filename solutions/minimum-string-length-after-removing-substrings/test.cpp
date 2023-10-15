#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ABFCACDB",
          .expected = 2,
      },
      {
          .s = "ACBBD",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minLength(s);
    REQUIRE(expected == actual);
  }
}
