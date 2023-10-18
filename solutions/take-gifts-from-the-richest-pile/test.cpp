#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> gifts;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .gifts{25, 64, 9, 4, 100},
          .k = 4,
          .expected = 29,
      },
      {
          .gifts{1, 1, 1, 1},
          .k = 4,
          .expected = 4,
      },
  };

  for (const auto &[gifts, k, expected] : test_cases) {
    const auto actual = Solution::pickGifts(gifts, k);
    REQUIRE(expected == actual);
  }
}
