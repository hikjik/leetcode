#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> forts;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .forts{1, 0, 0, -1, 0, 0, 0, 0, 1},
          .expected = 4,
      },
      {
          .forts{0, 0, 1, -1},
          .expected = 0,
      },
  };

  for (const auto &[forts, expected] : test_cases) {
    const auto actual = Solution::captureForts(forts);
    REQUIRE(expected == actual);
  }
}
