#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<Tree> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .expected{{0, 0, 0, std::nullopt, std::nullopt, 0, 0, std::nullopt,
                     std::nullopt, 0, 0},
                    {0, 0, 0, std::nullopt, std::nullopt, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, std::nullopt, std::nullopt, std::nullopt,
                     std::nullopt, 0, 0},
                    {0, 0, 0, 0, 0, std::nullopt, std::nullopt, 0, 0}},
      },
      {
          .n = 3,
          .expected{{0, 0, 0}},
      },
      {
          .n = 2,
          .expected{},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::allPossibleFBT(n);

    REQUIRE(actual.size() == expected.size());
    for (size_t i = 0; i < actual.size(); ++i) {
      REQUIRE(IsEqual(expected[i], actual[i]));
    }
  }
}
