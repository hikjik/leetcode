#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> access_times;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .access_times{{"a", "0549"},
                        {"b", "0457"},
                        {"a", "0532"},
                        {"a", "0621"},
                        {"b", "0540"}},
          .expected{"a"},
      },
      {
          .access_times{{"d", "0002"},
                        {"c", "0808"},
                        {"c", "0829"},
                        {"e", "0215"},
                        {"d", "1508"},
                        {"d", "1444"},
                        {"d", "1410"},
                        {"c", "0809"}},
          .expected{"c", "d"},
      },
      {
          .access_times{{"cd", "1025"},
                        {"ab", "1025"},
                        {"cd", "1046"},
                        {"cd", "1055"},
                        {"ab", "1124"},
                        {"ab", "1120"}},
          .expected{"ab", "cd"},
      },
  };

  for (const auto &[access_times, expected] : test_cases) {
    const auto actual = Solution::findHighAccessEmployees(access_times);
    REQUIRE(expected == actual);
  }
}
