#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    int m;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"10", "0001", "111001", "1", "0"},
          .m = 5,
          .n = 3,
          .expected = 4,
      },
      {
          .strs{"10", "0", "1"},
          .m = 1,
          .n = 1,
          .expected = 2,
      },
  };

  for (const auto &[strs, m, n, expected] : test_cases) {
    const auto actual = Solution::findMaxForm(strs, m, n);
    REQUIRE(expected == actual);
  }
}
