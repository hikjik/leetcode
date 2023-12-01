#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "egg",
          .s2 = "add",
          .expected = true,
      },
      {
          .s1 = "foo",
          .s2 = "bar",
          .expected = false,
      },
      {
          .s1 = "paper",
          .s2 = "title",
          .expected = true,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution::isIsomorphic(s1, s2);
    REQUIRE(expected == actual);
  }
}
