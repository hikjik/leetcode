#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> bills;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bills{5, 5, 5, 10, 20},
          .expected = true,
      },
      {
          .bills{5, 5, 10, 10, 20},
          .expected = false,
      },
  };

  for (const auto &[bills, expected] : test_cases) {
    const auto actual = Solution::lemonadeChange(bills);
    REQUIRE(expected == actual);
  }
}
