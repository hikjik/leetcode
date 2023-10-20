#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sentence;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence = "I speak Goat Latin",
          .expected = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa",
      },
      {
          .sentence = "The quick brown fox jumped over the lazy dog",
          .expected = "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa "
                      "overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa",
      },
  };

  for (const auto &[sentence, expected] : test_cases) {
    const auto actual = Solution::toGoatLatin(sentence);
    REQUIRE(expected == actual);
  }
}
