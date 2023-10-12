#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 3, 4},
          .expected = "23:41",
      },
      {
          .arr{5, 5, 5, 5},
          .expected = "",
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::largestTimeFromDigits(arr);
    REQUIRE(expected == actual);
  }
}
