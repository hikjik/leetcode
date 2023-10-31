#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> pref;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pref{5, 2, 0, 3, 1},
          .expected{5, 7, 2, 3, 2},
      },
      {
          .pref{13},
          .expected{13},
      },
  };

  for (const auto &[pref, expected] : test_cases) {
    const auto actual = Solution::findArray(pref);
    REQUIRE(expected == actual);
  }
}
