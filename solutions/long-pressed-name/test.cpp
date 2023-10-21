#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string name;
    std::string typed;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .name = "alex",
          .typed = "aaleex",
          .expected = true,
      },
      {
          .name = "saeed",
          .typed = "ssaaedd",
          .expected = false,
      },
  };

  for (const auto &[name, typed, expected] : test_cases) {
    const auto actual = Solution::isLongPressedName(name, typed);
    REQUIRE(expected == actual);
  }
}
