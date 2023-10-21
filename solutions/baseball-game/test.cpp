#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> operations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .operations{"5", "2", "C", "D", "+"},
          .expected = 30,
      },
      {
          .operations{"5", "-2", "4", "C", "D", "9", "+", "+"},
          .expected = 27,
      },
      {
          .operations{"1", "C"},
          .expected = 0,
      },
  };

  for (const auto &[operations, expected] : test_cases) {
    const auto actual = Solution::calPoints(operations);
    REQUIRE(expected == actual);
  }
}
