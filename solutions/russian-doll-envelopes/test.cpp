#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> envelopes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}},
          .expected = 3,
      },
      {
          .envelopes{{1, 1}, {1, 1}, {1, 1}},
          .expected = 1,
      },
  };

  for (const auto &[envelopes, expected] : test_cases) {
    const auto actual = Solution::maxEnvelopes(envelopes);
    REQUIRE(expected == actual);
  }
}
