#version 460 core

in vec3 v_color;
in vec2 v_texcoord;

out vec4 f_color;

uniform float u_time;
uniform sampler2D u_texture;

float frequency = 3.0;
float amplitude = 0.3;

void main()
{
	//f_color = vec4(1, 0, 0, 1);
	//float offset_x = cos(u_time + gl_FragCoord.x);
	//float offset_y = tan(u_time * frequency + gl_FragCoord.y) * amplitude;
	//f_color = vec4(v_color * offset_y * offset_x, 1);

	f_color = texture(u_texture, v_texcoord) * vec4(v_color, 1);
}