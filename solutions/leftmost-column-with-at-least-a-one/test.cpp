#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> data;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .data{{0, 0}, {1, 1}},
          .expected = 0,
      },
      {
          .data{{0, 0}, {0, 1}},
          .expected = 1,
      },
      {
          .data{{0, 0}, {0, 0}},
          .expected = -1,
      },
  };

  for (const auto &[data, expected] : test_cases) {
    BinaryMatrix mat(data);
    const auto actual = Solution::leftMostColumnWithOne(mat);
    REQUIRE(expected == actual);
    REQUIRE(mat.getNumberOfCalls() <= 1000);
  }
}
