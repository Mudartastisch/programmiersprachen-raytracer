#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h>

Sphere::Sphere() :
	center_{ 0.0f,0.0f,0.0f },
	radius_{ 1.0f },
	name_{ "default_sphere" },
	color_{ 0.0f,0.0f,0.0f } {}

Sphere::Sphere(glm::vec3 const & ctr, float r, std::string name, Color const & clr) :
	center_{ ctr },
	radius_{ r },
	name_{ name },
	color_{ clr } {}


Sphere::~Sphere()
{
}

float Sphere::area() const
{
	return (4*M_PI*radius_*radius_);
}

float Sphere::volume() const
{
	return ((4 / 3)*(M_PI)*(radius_*radius_*radius_));
}

glm::vec3 Sphere::getCenter() const
{
	return center_;
}

float Sphere::getRadius() const
{
	return radius_;
}

std::string Sphere::getName() const
{
	return name_;
}

Color Sphere::getColor() const
{
	return color_;
}

bool Sphere::intersect(Ray ray_) const
{
	float distance{ 0.0 };
	bool test = glm::intersectRaySphere(ray_.origin, glm::normalize(ray_.direction), getCenter(), getRadius()*getRadius(), distance);
	return test;
}

