#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> data;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .data{197, 130, 1},
          .expected = true,
      },
      {
          .data{235, 140, 4},
          .expected = false,
      },
  };

  for (const auto &[data, expected] : test_cases) {
    const auto actual = Solution::validUtf8(data);
    REQUIRE(expected == actual);
  }
}
