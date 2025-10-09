#version 460 core

layout(location = 0) in vec3 a_positon;
layout(location = 1) in vec3 a_color;
//layout(location = 2) in vec2 a_uv;

out vec3 v_ocolor;
uniform float u_time;

void main()
{
	v_ocolor = a_color;
	gl_Position = vec4(a_positon * tan(u_time), 1.0);
}