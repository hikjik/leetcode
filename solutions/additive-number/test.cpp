#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "198019823962",
          .expected = true,
      },
      {
          .num = "112358",
          .expected = true,
      },
      {
          .num = "199100199",
          .expected = true,
      },
      {
          .num = "10",
          .expected = false,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::isAdditiveNumber(num);
    REQUIRE(expected == actual);
  }
}
