#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string source;
    std::string target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .source = "abc",
          .target = "abcbc",
          .expected = 2,
      },
      {
          .source = "abc",
          .target = "acdbc",
          .expected = -1,
      },
      {
          .source = "xyz",
          .target = "xzyxz",
          .expected = 3,
      },
  };

  SECTION("Two Pointers") {
    for (const auto &[source, target, expected] : test_cases) {
      const auto actual = two_pointers::Solution::shortestWay(source, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Preprocessing") {
    for (const auto &[source, target, expected] : test_cases) {
      const auto actual = preprocessing::Solution::shortestWay(source, target);
      REQUIRE(expected == actual);
    }
  }
}
