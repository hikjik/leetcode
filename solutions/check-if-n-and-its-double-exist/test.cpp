#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{10, 2, 5, 3},
          .expected = true,
      },
      {
          .arr{3, 1, 7, 11},
          .expected = false,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::checkIfExist(arr);
    REQUIRE(expected == actual);
  }
}
