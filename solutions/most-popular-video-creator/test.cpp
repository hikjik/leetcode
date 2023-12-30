#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> creators;
    std::vector<std::string> ids;
    std::vector<int> views;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .creators{"alice", "bob", "alice", "chris"},
          .ids{"one", "two", "three", "four"},
          .views{5, 10, 5, 4},
          .expected{{"alice", "one"}, {"bob", "two"}},
      },
      {
          .creators{"alice", "alice", "alice"},
          .ids{"a", "b", "c"},
          .views{1, 2, 2},
          .expected{{"alice", "b"}},
      },
  };

  for (const auto &[creators, ids, views, expected] : test_cases) {
    const auto actual = Solution::mostPopularCreator(creators, ids, views);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
