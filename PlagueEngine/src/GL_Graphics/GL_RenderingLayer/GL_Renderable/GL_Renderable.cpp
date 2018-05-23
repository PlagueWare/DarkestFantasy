#include "GL_Renderable.h"

GL_Renderable::GL_Renderable(glm::vec3 scale, glm::vec3 position, glm::vec4 color)
	: Scale(scale / 2), Position(position), Color(color)
{

}