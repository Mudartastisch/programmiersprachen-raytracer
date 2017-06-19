#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Shape.h"
#include "Sphere.h"
#include "Box.h"
#include "Color.hpp"
#include <glm/glm.hpp >
#include <glm/gtx/intersect.hpp >

glm::vec3 zeroVec{ 0.0,0.0,0.0 };
glm::vec3 oneVec{ 1.0,1.0,1.0 };
Color black{1.0,1.0,1.0};
/*
TEST_CASE(" create a shape") {
	Shape basic{};
	REQUIRE(1.0 == 1.0);
	//test creation of shape
}
*/
TEST_CASE("create sphere") {
	Sphere basic{};
	Sphere advanced{ zeroVec,{3.85f},{"advanced"},{black} };
	REQUIRE(advanced.getCenter().x == zeroVec.x);
	REQUIRE(advanced.getCenter().y == zeroVec.y);
	REQUIRE(advanced.getCenter().z == zeroVec.z);
	REQUIRE(advanced.getRadius() == 3.85f);
	REQUIRE(advanced.area() == Approx(4.0f));
	REQUIRE(advanced.volume() == Approx(4.0f));
}

TEST_CASE("create box") {
	Box basic{};
	Box advanced{ zeroVec, oneVec,{ "advanced" },{ black } };
	REQUIRE(advanced.area() == Approx(4.0f));
	REQUIRE(advanced.volume() == Approx(4.0f));
	REQUIRE(advanced.getMin().x == zeroVec.x);
	REQUIRE(advanced.getMin().y == zeroVec.y);
	REQUIRE(advanced.getMin().z == zeroVec.z);
	REQUIRE(advanced.getMax().x == oneVec.x);
	REQUIRE(advanced.getMax().y == oneVec.y);
	REQUIRE(advanced.getMax().z == oneVec.z);
}

TEST_CASE(" intersectRaySphere ", "[ intersect ]")
{
	// Ray
	glm::vec3 ray_origin{ 0.0 ,0.0 ,0.0 };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0 ,0.0 ,1.0 };
	// Sphere
	glm::vec3 sphere_center{ 0.0 ,0.0 ,5.0 };
	float sphere_radius{ 1.0 };
	float distance{ 0.0 };
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
