#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string boxes;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .boxes = "110",
          .expected{1, 1, 3},
      },
      {
          .boxes = "001011",
          .expected{11, 8, 5, 4, 3, 4},
      },
  };

  for (const auto &[boxes, expected] : test_cases) {
    const auto actual = Solution::minOperations(boxes);
    REQUIRE(expected == actual);
  }
}
