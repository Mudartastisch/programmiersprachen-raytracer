#pragma once
#include "Shape.h"
#include "color.hpp"
class Sphere :
	public Shape
{
public:
	Sphere();
	Sphere(glm::vec3 const& ctr, float r, std::string name, Color const& clr);
	~Sphere();
	float area() const override;
	float volume() const override;
	glm::vec3 getCenter() const;
	float getRadius() const;
	std::string getName() const;
	Color getColor() const;

private:
	glm::vec3 center_;
	float radius_;
	std::string name_;
	Color color_;
};

