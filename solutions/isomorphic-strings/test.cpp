#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "egg",
          .t = "add",
          .expected = true,
      },
      {
          .s = "foo",
          .t = "bar",
          .expected = false,
      },
      {
          .s = "paper",
          .t = "title",
          .expected = true,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::isIsomorphic(s, t);
    REQUIRE(expected == actual);
  }
}
