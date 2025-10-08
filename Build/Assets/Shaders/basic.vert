#version 460 core

layout(location = 0) in vec3 positon;
//layout(location = 1) in vec3 color;
//layout(location = 2) in vec2 uv;

//out vec3 ocolor;

void main()
{
	//ocolor = color;
	gl_Position = vec4(positon, 1.0);
}