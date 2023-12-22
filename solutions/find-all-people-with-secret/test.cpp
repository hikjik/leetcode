#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> meetings;
    int firstPerson;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .meetings{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}},
          .firstPerson = 1,
          .expected{0, 1, 2, 3, 5},
      },
      {
          .n = 4,
          .meetings{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}},
          .firstPerson = 3,
          .expected{0, 1, 3},
      },
      {
          .n = 5,
          .meetings{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}},
          .firstPerson = 1,
          .expected{0, 1, 2, 3, 4},
      },
  };

  for (const auto &[n, meetings, firstPerson, expected] : test_cases) {
    const auto actual = Solution::findAllPeople(n, meetings, firstPerson);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
