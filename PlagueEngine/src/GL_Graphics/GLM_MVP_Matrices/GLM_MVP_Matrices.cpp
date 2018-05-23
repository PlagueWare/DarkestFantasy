#include "GLM_MVP_Matrices.h"

void GLM_ViewMatrix::set(glm::mat4 viewMatrix)
{
	m_ViewMatrix = viewMatrix;
}

void GLM_ProjectionMatrix::set(glm::mat4 projectionMatrix)
{
	m_ProjectionMatrix = projectionMatrix;
}

void GLM_MVP_Matrix::set(GLM_ModelMatrix modelMatrix, GLM_ViewMatrix viewMatrix, GLM_ProjectionMatrix projectionMatrix)
{
	m_MVP_Matrix = (projectionMatrix.get() * viewMatrix.get() * modelMatrix.get());
}