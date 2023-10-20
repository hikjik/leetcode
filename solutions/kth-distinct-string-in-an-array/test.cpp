#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> arr;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{"d", "b", "c", "b", "c", "a"},
          .k = 2,
          .expected = "a",
      },
      {
          .arr{"aaa", "aa", "a"},
          .k = 1,
          .expected = "aaa",
      },
      {
          .arr{"a", "b", "a"},
          .k = 3,
          .expected = "",
      },
  };

  for (const auto &[arr, k, expected] : test_cases) {
    const auto actual = Solution::kthDistinct(arr, k);
    REQUIRE(expected == actual);
  }
}
