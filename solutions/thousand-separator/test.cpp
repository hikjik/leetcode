#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 987,
          .expected = "987",
      },
      {
          .n = 1234,
          .expected = "1.234",
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::thousandSeparator(n);
    REQUIRE(expected == actual);
  }
}
