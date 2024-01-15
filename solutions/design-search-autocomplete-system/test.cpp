#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<std::string> sentences{"i love you", "island", "iroman",
                                     "i love leetcode"};
  std::vector<int> times{5, 3, 2, 2};
  auto autocomplete_system = AutocompleteSystem(sentences, times);

  REQUIRE(std::vector<std::string>{"i love you", "island", "i love leetcode"} ==
          autocomplete_system.input('i'));
  REQUIRE(std::vector<std::string>{"i love you", "i love leetcode"} ==
          autocomplete_system.input(' '));
  REQUIRE(std::vector<std::string>{} == autocomplete_system.input('a'));
  REQUIRE(std::vector<std::string>{} == autocomplete_system.input('#'));
}
