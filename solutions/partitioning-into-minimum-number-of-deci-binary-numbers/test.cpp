#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = "32",
          .expected = 3,
      },
      {
          .n = "82734",
          .expected = 8,
      },
      {
          .n = "27346209830709182346",
          .expected = 9,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::minPartitions(n);
    REQUIRE(expected == actual);
  }
}
