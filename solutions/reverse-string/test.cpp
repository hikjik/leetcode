#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<char> s;
    std::vector<char> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s{'h', 'e', 'l', 'l', 'o'},
          .expected{'o', 'l', 'l', 'e', 'h'},
      },
      {
          .s{'H', 'a', 'n', 'n', 'a', 'h'},
          .expected{'h', 'a', 'n', 'n', 'a', 'H'},
      },
  };

  for (auto &[s, expected] : test_cases) {
    Solution::reverseString(s);
    REQUIRE(expected == s);
  }
}
