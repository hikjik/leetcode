#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ab-cd",
          .expected = "dc-ba",
      },
      {
          .s = "a-bC-dEf-ghIj",
          .expected = "j-Ih-gfE-dCba",
      },
      {
          .s = "Test1ng-Leet=code-Q!",
          .expected = "Qedo1ct-eeLg=ntse-T!",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::reverseOnlyLetters(s);
    REQUIRE(expected == actual);
  }
}
