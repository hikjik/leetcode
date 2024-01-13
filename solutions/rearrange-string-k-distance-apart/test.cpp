#include <catch.hpp>

#include <solution.hpp>

#include <unordered_set>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      // {
      //     .s = "aabbcc",
      //     .k = 3,
      //     .expected = "abcabc",
      // },
      // {
      //     .s = "aaabc",
      //     .k = 3,
      //     .expected = "",
      // },
      {
          .s = "aaadbbcc",
          .k = 2,
          .expected = "abacabcd",
      },
  };

  for (auto &[s, k, expected] : test_cases) {
    auto actual = Solution::rearrangeString(s, k);

    std::unordered_set<char> set;
    for (int i = 0; i < std::ssize(actual); ++i) {
      REQUIRE(!set.contains(actual[i]));
      set.insert(actual[i]);
      if (i >= k - 1) {
        set.erase(actual[i - k + 1]);
      }
    }

    std::ranges::sort(actual);
    std::ranges::sort(expected);
    REQUIRE(expected == actual);
  }
}
