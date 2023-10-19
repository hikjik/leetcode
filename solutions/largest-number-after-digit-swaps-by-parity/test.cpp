#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 1234,
          .expected = 3412,
      },
      {
          .num = 65875,
          .expected = 87655,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::largestInteger(num);
    REQUIRE(expected == actual);
  }
}
