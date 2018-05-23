#version 460 core

layout (location = 0) in vec4 Position;
layout (location = 1) in vec4 Color;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

out DATA
{
	vec4 f_Pos;
	vec4 f_Color;
} vs_out;

void main()
{ 
	gl_Position  = projMatrix * viewMatrix * Position;
											 
	vs_out.f_Pos = projMatrix * viewMatrix * Position;

	vs_out.f_Color = Color;
}