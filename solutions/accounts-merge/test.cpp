#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> accounts;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .accounts{{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                    {"John", "johnsmith@mail.com", "john00@mail.com"},
                    {"Mary", "mary@mail.com"},
                    {"John", "johnnybravo@mail.com"}},
          .expected{{"John", "john00@mail.com", "john_newyork@mail.com",
                     "johnsmith@mail.com"},
                    {"Mary", "mary@mail.com"},
                    {"John", "johnnybravo@mail.com"}},
      },
      {
          .accounts{{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                    {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                    {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                    {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                    {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}},
          .expected{{"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
                    {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
                    {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
                    {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
                    {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"}},
      },
  };

  for (const auto &[accounts, expected] : test_cases) {
    const auto actual = Solution::accountsMerge(accounts);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
