#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {

    auto file_system = FileSystem();

    REQUIRE(std::vector<std::string>{} == file_system.ls("/"));
    file_system.mkdir("/a/b/c");
    file_system.addContentToFile("/a/b/c/d", "hello");
    REQUIRE(std::vector<std::string>{"a"} == file_system.ls("/"));
    REQUIRE("hello" == file_system.readContentFromFile("/a/b/c/d"));
  }
}
