#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> operations;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .operations{"--X", "X++", "X++"},
          .expected = 1,
      },
      {
          .operations{"++X", "++X", "X++"},
          .expected = 3,
      },
      {
          .operations{"X++", "++X", "--X", "X--"},
          .expected = 0,
      },
  };

  for (const auto &[operations, expected] : test_cases) {
    const auto actual = Solution::finalValueAfterOperations(operations);
    REQUIRE(expected == actual);
  }
}
