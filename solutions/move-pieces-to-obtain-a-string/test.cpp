#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string start;
    std::string target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .start = "_L__R__R_",
          .target = "L______RR",
          .expected = true,
      },
      {
          .start = "R_L_",
          .target = "__LR",
          .expected = false,
      },
      {
          .start = "_R",
          .target = "R_",
          .expected = false,
      },
      {
          .start = "___________LLLLLLLLLLL",
          .target = "LLLLLLLLLLL___________",
          .expected = true,
      },
  };

  for (const auto &[start, target, expected] : test_cases) {
    const auto actual = Solution::canChange(start, target);
    REQUIRE(expected == actual);
  }
}
