#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> event1;
    std::vector<std::string> event2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .event1{"01:15", "02:00"},
          .event2{"02:00", "03:00"},
          .expected = true,
      },
      {
          .event1{"01:00", "02:00"},
          .event2{"01:20", "03:00"},
          .expected = true,
      },
      {
          .event1{"10:00", "11:00"},
          .event2{"14:00", "15:00"},
          .expected = false,
      },
  };

  for (const auto &[event1, event2, expected] : test_cases) {
    const auto actual = Solution::haveConflict(event1, event2);
    REQUIRE(expected == actual);
  }
}
