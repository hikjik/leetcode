#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto trie = Trie();
  trie.insert("apple");
  REQUIRE(trie.search("apple"));
  REQUIRE_FALSE(trie.search("app"));
  REQUIRE(trie.startsWith("app"));
  trie.insert("app");
  REQUIRE(trie.search("app"));
}
