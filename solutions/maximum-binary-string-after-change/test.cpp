#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string binary;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .binary = "000110",
          .expected = "111011",
      },
      {
          .binary = "01",
          .expected = "01",
      },
      {
          .binary = "01111001100000110010",
          .expected = "11111111110111111111",
      },
  };

  for (const auto &[binary, expected] : test_cases) {
    const auto actual = Solution::maximumBinaryString(binary);
    REQUIRE(expected == actual);
  }
}
