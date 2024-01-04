#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> doors;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .doors{0, 0, 0, 0},
          .k = 10,
          .expected = 4,
      },
      {
          .doors{1, 0, 1, 1, 0},
          .k = 5,
          .expected = 5,
      },
  };

  for (const auto &[doors, k, expected] : test_cases) {
    Street street(doors);
    const auto actual = Solution::houseCount(&street, k);
    REQUIRE(expected == actual);
  }
}
