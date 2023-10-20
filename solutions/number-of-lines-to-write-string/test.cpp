#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> widths;
    std::string s;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .widths{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
          .s = "abcdefghijklmnopqrstuvwxyz",
          .expected{3, 60},
      },
      {
          .widths{4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
          .s = "bbbcccdddaaa",
          .expected{2, 4},
      },
  };

  for (const auto &[widths, s, expected] : test_cases) {
    const auto actual = Solution::numberOfLines(widths, s);
    REQUIRE(expected == actual);
  }
}
