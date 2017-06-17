#include "Box.h"



Box::Box():
	min_{ 0.0f,0.0f,0.0f },
	max_{ 1.0f,1.0f,1.0f },
	name_{ "default_box" },
	color_{ 0.0f,0.0f,0.0f }
{}

Box::Box(glm::vec3 min, glm::vec3 max, std::string name, Color color):
	min_{ min },
	max_{ max },
	name_{ name },
	color_{ color } {}


Box::~Box()
{
}

float Box::area() const
{
	return ((2*getFrontSide())*(2*getFoundationSide())*(2*getAngleSide()));
}

float Box::volume() const
{
	return ((max_.z - min_.z)*(max_.y - min_.y)*(max_.x - min_.x));
}

glm::vec3 Box::getMin() const
{
	return min_;
}

glm::vec3 Box::getMax() const
{
	return max_;
}

std::string Box::getName() const
{
	return name_;
}

Color Box::getColor() const
{
	return color_;
}

float Box::getFrontSide() const
{
	return ((max_.z-min_.z)*(max_.y-min_.y));
}

float Box::getFoundationSide() const
{
	return ((max_.z - min_.z)*(max_.x - min_.x));
}

float Box::getAngleSide() const
{
	return ((max_.x - min_.x)*(max_.y - min_.y));;
}
