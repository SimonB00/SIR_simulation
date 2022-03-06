#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "approx.hpp"
#include "tables.hpp"

TEST_CASE("Test Approx") {
    CHECK(approx(7.1) == 7);
    CHECK(approx(7.5) == 8);
    CHECK(approx(7.6) == 8);
    CHECK(approx(7.9) == 8);
    CHECK(approx(7) == 7);
    CHECK(approx(0) == 0);
    CHECK(approx(1.49) == 1);
    CHECK(approx(-7.1) == -7);
}
TEST_CASE("Test Fill"){
    CHECK(fill(10, 0.005, 0.1, 100)[0].S == 90);
    CHECK(fill(10, 0.005, 0.1, 100)[0].I == 10);
    CHECK(fill(10, 0.005, 0.1, 100)[0].R == 0);
    CHECK(fill(10, 0.005, 0.1, 100)[1].S == 85.5);
    CHECK(fill(10, 0.005, 0.1, 100)[1].I == 13.5);
    CHECK(fill(10, 0.005, 0.1, 100)[1].R == 1);
    CHECK(fill(10, 0.005, 0.1, 100)[2].S == 79.72875);
    CHECK(fill(10, 0.005, 0.1, 100)[2].I == 17.92125);
    CHECK(fill(10, 0.005, 0.1, 100)[2].R == 2.35);

    // Pandemia "Bologna"
    CHECK(fill(30, 0.000003, 0.5, 400000)[0].S == 399970);
    CHECK(fill(30, 0.000003, 0.5, 400000)[0].I == 30);
    CHECK(fill(30, 0.000003, 0.5, 400000)[0].R == 0);
    CHECK(fill(30, 0.000003, 0.5, 400000)[1].S == 399934.0027);
    CHECK(fill(30, 0.000003, 0.5, 400000)[1].I == doctest::Approx(50.9973).epsilon(0.0001));
    CHECK(fill(30, 0.000003, 0.5, 400000)[1].R == 15);
    CHECK(fill(30, 0.000003, 0.5, 400000)[2].S == doctest::Approx(399872.816837053).epsilon(0.00000001));
    CHECK(fill(30, 0.000003, 0.5, 400000)[2].I == doctest::Approx(86.68531294).epsilon(0.001));
    CHECK(fill(30, 0.000003, 0.5, 400000)[2].R == 40.49865);

    // Pandemia "Riccione"
    CHECK(fill(60, 0.00005, 0.7, 35000)[0].S == 34940);
    CHECK(fill(60, 0.00005, 0.7, 35000)[0].I == 60);
    CHECK(fill(60, 0.00005, 0.7, 35000)[0].R == 0);
    CHECK(fill(60, 0.00005, 0.7, 35000)[1].S == 34835.18);
    CHECK(fill(60, 0.00005, 0.7, 35000)[1].I == 122.82);
    CHECK(fill(60, 0.00005, 0.7, 35000)[1].R == 42);
    CHECK(fill(60, 0.00005, 0.7, 35000)[2].S == 34621.25715962);
    CHECK(fill(60, 0.00005, 0.7, 35000)[2].I == doctest::Approx(250.76884038).epsilon(0.0000001));
    CHECK(fill(60, 0.00005, 0.7, 35000)[2].R == doctest::Approx(127.974).epsilon(0.001));

    // Pandemia "Vaticano"
    CHECK(fill(10, 0.0005, 0.3, 618)[0].S == 608);
    CHECK(fill(10, 0.0005, 0.3, 618)[0].I == 10);
    CHECK(fill(10, 0.0005, 0.3, 618)[0].R == 0);
    CHECK(fill(10, 0.0005, 0.3, 618)[1].S == 604.96);
    CHECK(fill(10, 0.0005, 0.3, 618)[1].I == 10.04);
    CHECK(fill(10, 0.0005, 0.3, 618)[1].R == 3);
    CHECK(fill(10, 0.0005, 0.3, 618)[2].S == 601.9231008);
    CHECK(fill(10, 0.0005, 0.3, 618)[2].I == 10.0648992);
    CHECK(fill(10, 0.0005, 0.3, 618)[2].R == 6.012);
}
TEST_CASE("Test FillTable"){
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[0].S == 90);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[0].I == 10);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[0].R == 0);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[1].S == 86);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[1].I == 14);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[1].R == 1);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[2].S == 80);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[2].I == 18);
    CHECK(fillTable( fill(10, 0.005, 0.1, 100) )[2].R == 2);

    // Pandemia "Bologna"
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[0].S == 399970);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[0].I == 30);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[0].R == 0);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[1].S == 399934);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[1].I == 51);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[1].R == 15);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[2].S == 399873);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[2].I == 87);
    CHECK(fillTable(fill(30, 0.000003, 0.5, 400000))[2].R == 40);

    // Pandemia "Riccione"
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[0].S == 34940);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[0].I == 60);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[0].R == 0);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[1].S == 34835);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[1].I == 123);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[1].R == 42);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[2].S == 34621);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[2].I == 251);
    CHECK(fillTable(fill(60, 0.00005, 0.7, 35000))[2].R == 127);

    // Pandemia "Vaticano"
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[0].S == 608);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[0].I == 10);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[0].R == 0);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[1].S == 605);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[1].I == 10);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[1].R == 3);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[2].S == 602);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[2].I == 10);
    CHECK(fillTable(fill(10, 0.0005, 0.3, 618))[2].R == 6);
}