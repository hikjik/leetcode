#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> secret;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .secret{-1, 0, 3, 5, 9, 12},
          .target = 9,
          .expected = 4,
      },
      {
          .secret{-1, 0, 3, 5, 9, 12},
          .target = 2,
          .expected = -1,
      },
  };

  for (const auto &[secret, target, expected] : test_cases) {
    ArrayReader reader(secret);
    const auto actual = Solution::search(reader, target);
    REQUIRE(expected == actual);
  }
}
