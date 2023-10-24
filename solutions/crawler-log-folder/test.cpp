#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> logs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .logs{"d1/", "d2/", "../", "d21/", "./"},
          .expected = 2,
      },
      {
          .logs{"d1/", "d2/", "./", "d3/", "../", "d31/"},
          .expected = 3,
      },
      {
          .logs{"d1/", "../", "../", "../"},
          .expected = 0,
      },
  };

  for (const auto &[logs, expected] : test_cases) {
    const auto actual = Solution::minOperations(logs);
    REQUIRE(expected == actual);
  }
}
