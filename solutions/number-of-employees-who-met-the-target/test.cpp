#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> hours;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .hours{0, 1, 2, 3, 4},
          .target = 2,
          .expected = 3,
      },
      {
          .hours{5, 1, 4, 2, 2},
          .target = 6,
          .expected = 0,
      },
  };

  for (const auto &[hours, target, expected] : test_cases) {
    const auto actual = Solution::numberOfEmployeesWhoMetTarget(hours, target);
    REQUIRE(expected == actual);
  }
}
