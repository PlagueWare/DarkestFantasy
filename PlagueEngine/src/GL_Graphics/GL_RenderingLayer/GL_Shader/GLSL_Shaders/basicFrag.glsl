#version 460 core

layout (location = 0) out vec4 color;

uniform vec4 lightPos;

in DATA
{
	vec4 f_Pos;
	vec4 f_Color;
} fs_in;

void main()
{ 
	float Intensity = (lightPos.w / 2) / length(fs_in.f_Pos.xyzw - lightPos);
	color = fs_in.f_Color * Intensity;
}