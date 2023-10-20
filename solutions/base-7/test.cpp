#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 100,
          .expected = "202",
      },
      {
          .num = -7,
          .expected = "-10",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::convertToBase7(num);
    REQUIRE(expected == actual);
  }
}
