#include "Core.h"

void Core::onRender()
{	
	SceneLayer.Renderer->clear(0, 0, 0, 1);
	
	SceneLayer.Shader->setUniformMat4("projMatrix", glm::perspective(glm::radians(90.0f), 16.0f / 9.0f, 0.1f, 100.0f));
	SceneLayer.Shader->setUniformMat4("viewMatrix", glm::lookAt(glm::vec3(20, 20, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));	
	SceneLayer.Shader->setUniform4f("lightPos", glm::vec4(0, 0, 0, 16));
	
	SceneLayer.Renderer->pushMatrix(glm::scale(glm::vec3(1, 1, 1)));
	SceneLayer.Renderer->pushMatrix(glm::rotate(glm::radians(0.0f), glm::vec3(0, 1, 0)));
	SceneLayer.Renderer->pushMatrix(glm::translate(glm::vec3(0, 0, 0)));
	
	SceneLayer.Renderer->begin();

	for (GLuint x = 0; x < 16; x++){
	for (GLuint y = 0; y < 16; y++){
	for (GLuint z = 0; z < 16; z++){

		SceneLayer.Renderer->submit(GL_Renderable(glm::vec3(0.05f, 0.05f, 0.05f), glm::vec3(x, y, z), glm::vec4(1, 0, 1, 1)));
	
	}}}

	SceneLayer.Renderer->end();

	SceneLayer.Renderer->popMatrix();
	SceneLayer.Renderer->draw(GL_TRIANGLES);

	Window.update();
}