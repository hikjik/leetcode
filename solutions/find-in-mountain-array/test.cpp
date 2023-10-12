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
          .secret{1, 2, 3, 4, 5, 3, 1},
          .target = 3,
          .expected = 2,
      },
      {
          .secret{0, 1, 2, 4, 2, 1},
          .target = 3,
          .expected = -1,
      },
  };

  for (const auto &[secret, target, expected] : test_cases) {
    auto array = MountainArray(secret);
    const auto actual = Solution::findInMountainArray(target, array);
    REQUIRE(expected == actual);
    REQUIRE(array.count() <= 100);
  }
}
