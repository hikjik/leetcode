#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto trie = Trie();

  trie.insert("apple");
  REQUIRE(true == trie.search("apple"));
  REQUIRE(false == trie.search("app"));
  REQUIRE(true == trie.startsWith("app"));
  trie.insert("app");
  REQUIRE(true == trie.search("app"));
}
