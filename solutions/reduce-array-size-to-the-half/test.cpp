#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{3, 3, 3, 3, 5, 5, 5, 2, 2, 7},
          .expected = 2,
      },
      {
          .arr{7, 7, 7, 7, 7, 7},
          .expected = 1,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::minSetSize(arr);
    REQUIRE(expected == actual);
  }
}
