#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 121,
          .expected = true,
      },
      {
          .n = -121,
          .expected = false,
      },
      {
          .n = 10,
          .expected = false,
      },
  };

  SECTION("STL") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = stl::Solution::isPalindrome(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Reverse Int") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = reverse::Solution::isPalindrome(n);
      REQUIRE(expected == actual);
    }
  }
}
