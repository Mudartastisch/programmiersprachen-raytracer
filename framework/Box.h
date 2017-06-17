#pragma once
#include "Shape.h"
#include "color.hpp"
class Box :
	public Shape
{
public:
	Box();
	Box(glm::vec3 min, glm::vec3 max, std::string name, Color color);
	~Box();
	float area() const override;
	float volume() const override;
	glm::vec3 getMin() const;
	glm::vec3 getMax() const;
	std::string getName() const;
	Color getColor() const;
	float getFrontSide() const;
	float getFoundationSide() const;
	float getAngleSide() const;

private:
	glm::vec3 min_;
	glm::vec3 max_;
	std::string name_;
	Color color_;
};

