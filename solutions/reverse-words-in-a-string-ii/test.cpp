#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<char> s;
    std::vector<char> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s{'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l',
             'u', 'e'},
          .expected = {'b', 'l', 'u', 'e', ' ', 'i', 's', ' ', 's', 'k', 'y',
                       ' ', 't', 'h', 'e'},
      },
      {
          .s{'a'},
          .expected = {'a'},
      },
  };

  for (auto &[s, expected] : test_cases) {
    Solution::reverseWords(s);
    REQUIRE(expected == s);
  }
}
