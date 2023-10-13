#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 26,
          .expected = "1a",
      },
      {
          .num = -1,
          .expected = "ffffffff",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::toHex(num);
    REQUIRE(expected == actual);
  }
}
