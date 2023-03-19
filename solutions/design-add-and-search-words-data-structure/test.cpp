#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto obj = WordDictionary();
  obj.addWord("bad");
  obj.addWord("dad");
  obj.addWord("mad");

  REQUIRE_FALSE(obj.search("pad"));
  REQUIRE(obj.search("bad"));
  REQUIRE(obj.search(".ad"));
  REQUIRE(obj.search("b.."));
}
