#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> categories;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .categories{1, 1, 2, 2, 3, 3},
          .expected = 3,
      },
      {
          .n = 5,
          .categories{1, 2, 3, 4, 5},
          .expected = 5,
      },
      {
          .n = 3,
          .categories{1, 1, 1},
          .expected = 1,
      },
  };

  for (const auto &[n, categories, expected] : test_cases) {
    CategoryHandler handler(categories);
    const auto actual = Solution::numberOfCategories(n, &handler);
    REQUIRE(expected == actual);
  }
}
