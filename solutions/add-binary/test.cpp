#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string a;
    std::string b;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = "11",
          .b = "1",
          .expected = "100",
      },
      {
          .a = "1010",
          .b = "1011",
          .expected = "10101",
      },
  };

  for (const auto &[a, b, expected] : test_cases) {
    const auto actual = Solution::addBinary(a, b);
    REQUIRE(expected == actual);
  }
}
