#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"cba", "daf", "ghi"},
          .expected = 1,
      },
      {
          .strs{"a", "b"},
          .expected = 0,
      },
      {
          .strs{"zyx", "wvu", "tsr"},
          .expected = 3,
      },
  };

  for (const auto &[strs, expected] : test_cases) {
    const auto actual = Solution::minDeletionSize(strs);
    REQUIRE(expected == actual);
  }
}
