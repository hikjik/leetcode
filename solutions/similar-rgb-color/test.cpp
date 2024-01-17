#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string color;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .color = "#09f166",
          .expected = "#11ee66",
      },
      {
          .color = "#4e3fe1",
          .expected = "#5544dd",
      },
  };

  for (const auto &[color, expected] : test_cases) {
    const auto actual = Solution::similarRGB(color);
    REQUIRE(expected == actual);
  }
}
