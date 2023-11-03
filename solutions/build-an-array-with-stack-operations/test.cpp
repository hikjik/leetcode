#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> target;
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target{1, 3},
          .n = 3,
          .expected{"Push", "Push", "Pop", "Push"},
      },
      {
          .target{1, 2, 3},
          .n = 3,
          .expected{"Push", "Push", "Push"},
      },
      {
          .target{1, 2},
          .n = 4,
          .expected{"Push", "Push"},
      },
  };

  for (const auto &[target, n, expected] : test_cases) {
    const auto actual = Solution::buildArray(target, n);
    REQUIRE(expected == actual);
  }
}
