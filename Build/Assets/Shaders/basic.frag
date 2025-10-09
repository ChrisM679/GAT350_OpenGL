#version 460 core

in vec3 v_ocolor;
out vec4 f_color;

uniform float u_time;

float frequency = 3.0;
float amplitude = 0.3;

void main()
{
	//f_color = vec4(1, 0, 0, 1);
	float offset_x = cos(u_time + gl_FragCoord.x);
	float offset_y = tan(u_time * frequency + gl_FragCoord.y) * amplitude;
	f_color = vec4(v_ocolor * offset_y * offset_x, 1);
}