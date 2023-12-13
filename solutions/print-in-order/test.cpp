#include <catch.hpp>

#include <sstream>
#include <thread>

#include <solution.hpp>

TEST_CASE("Simple") {
  for (int i = 0; i < 100; ++i) {
    std::stringstream stream;

    auto printFirst = [&]() { stream << "first"; };
    auto printSecond = [&]() { stream << "second"; };
    auto printThird = [&]() { stream << "third"; };

    Foo foo;
    std::thread th1(&Foo::first, &foo, printFirst);
    std::thread th2(&Foo::second, &foo, printSecond);
    std::thread th3(&Foo::third, &foo, printThird);

    th1.join();
    th2.join();
    th3.join();

    REQUIRE(stream.str() == "firstsecondthird");
  }
}
