#include "vector.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Vector equality", "[vector]") {
    lla::Vec2i v(1, 2);

    REQUIRE(v == lla::Vec2i(1, 2));
    REQUIRE(v != lla::Vec2i(10, 20));
}

TEST_CASE("Vector addition", "[vector]") {
    lla::Vec2i v(1, 2);
    lla::Vec2i u(10, 20);

    REQUIRE((v + u).x() == 11);
    REQUIRE((v + u).y() == 22);

    v += u;

    REQUIRE(v.x() == 11);
    REQUIRE(v.y() == 22);
}

TEST_CASE("Vector subtraction", "[vector]") {
    lla::Vec2i v(1, 2);
    lla::Vec2i u(10, 20);

    REQUIRE((v - u).x() == -9);
    REQUIRE((v - u).y() == -18);

    v -= u;

    REQUIRE(v.x() == -9);
    REQUIRE(v.y() == -18);
}

TEST_CASE("Vector dot product", "[vector]") {
    lla::Vec2i v(1, 2);
    lla::Vec2i u(10, 20);

    REQUIRE(v * u == 50);
}
