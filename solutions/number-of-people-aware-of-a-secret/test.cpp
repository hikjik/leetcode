#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int delay;
    int forget;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .delay = 2,
          .forget = 4,
          .expected = 5,
      },
      {
          .n = 4,
          .delay = 1,
          .forget = 3,
          .expected = 6,
      },
  };

  for (const auto &[n, delay, forget, expected] : test_cases) {
    const auto actual = Solution::peopleAwareOfSecret(n, delay, forget);
    REQUIRE(expected == actual);
  }
}
