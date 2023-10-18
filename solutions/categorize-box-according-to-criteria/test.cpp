#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int length;
    int width;
    int height;
    int mass;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .length = 1000,
          .width = 35,
          .height = 700,
          .mass = 300,
          .expected = "Heavy",
      },
      {
          .length = 200,
          .width = 50,
          .height = 800,
          .mass = 50,
          .expected = "Neither",
      },
  };

  for (const auto &[length, width, height, mass, expected] : test_cases) {
    const auto actual = Solution::categorizeBox(length, width, height, mass);
    REQUIRE(expected == actual);
  }
}
