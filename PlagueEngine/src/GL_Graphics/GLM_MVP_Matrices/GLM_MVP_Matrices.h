#pragma once

#include "glm.hpp"
#include "ext.hpp"

class GLM_ModelMatrix
{

public:

	glm::mat4 Scale;
	glm::mat4 Rotation;
	glm::mat4 Translation;

public:

	inline glm::mat4 get() { return Translation * Rotation * Scale; }
};

class GLM_ViewMatrix
{

private:

	glm::mat4 m_ViewMatrix;

public:

	void set(glm::mat4 viewMatrix);
	inline glm::mat4 get() { return m_ViewMatrix; }

};

class GLM_ProjectionMatrix
{

private:

	glm::mat4 m_ProjectionMatrix;

public:

	void set(glm::mat4 projectionMatrix);
	inline glm::mat4 get() { return m_ProjectionMatrix; }

};

class GLM_MVP_Matrix
{

private:

	glm::mat4 m_MVP_Matrix;

public:

	void set(GLM_ModelMatrix modelMatrix, GLM_ViewMatrix viewMatrix, GLM_ProjectionMatrix projectionMatrix);
	inline glm::mat4 get() { return m_MVP_Matrix; }

};