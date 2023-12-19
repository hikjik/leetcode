#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> favoriteCompanies;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .favoriteCompanies{{"leetcode", "google", "facebook"},
                             {"google", "microsoft"},
                             {"google", "facebook"},
                             {"google"},
                             {"amazon"}},
          .expected{0, 1, 4},
      },
      {
          .favoriteCompanies{{"leetcode", "google", "facebook"},
                             {"leetcode", "amazon"},
                             {"facebook", "google"}},
          .expected{0, 1},
      },
      {
          .favoriteCompanies{
              {"leetcode"}, {"google"}, {"facebook"}, {"amazon"}},
          .expected{0, 1, 2, 3},
      },
  };

  for (const auto &[favoriteCompanies, expected] : test_cases) {
    const auto actual = Solution::peopleIndexes(favoriteCompanies);
    REQUIRE(expected == actual);
  }
}
