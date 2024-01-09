#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::string compressedString = "L1e2t1C1o1d1e1";
  auto string_iterator = StringIterator(compressedString);

  REQUIRE('L' == string_iterator.next());
  REQUIRE('e' == string_iterator.next());
  REQUIRE('e' == string_iterator.next());
  REQUIRE('t' == string_iterator.next());
  REQUIRE('C' == string_iterator.next());
  REQUIRE('o' == string_iterator.next());
  REQUIRE(true == string_iterator.hasNext());
  REQUIRE('d' == string_iterator.next());
  REQUIRE(true == string_iterator.hasNext());
}
