#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 0,
          .expected = "Zero",
      },
      {
          .num = 123,
          .expected = "One Hundred Twenty Three",
      },
      {
          .num = 12345,
          .expected = "Twelve Thousand Three Hundred Forty Five",
      },
      {
          .num = 1234567,
          .expected = "One Million Two Hundred Thirty Four Thousand Five "
                      "Hundred Sixty Seven",
      },
      {
          .num = 1000010,
          .expected = "One Million Ten",
      },
      {
          .num = 1000000,
          .expected = "One Million",
      },
      {
          .num = 2147483647,
          .expected = "Two Billion One Hundred Forty Seven Million Four "
                      "Hundred Eighty Three Thousand Six Hundred Forty Seven",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::numberToWords(num);
    REQUIRE(expected == actual);
  }
}
