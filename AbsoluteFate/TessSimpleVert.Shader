#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;
//layout(binding = 2) uniform sampler2D tex_displacement;

uniform mat4 uWorldTransform;
uniform mat4 uViewProj;
uniform vec2 uTiling;
uniform vec2 uOffset;

out VS_OUT{
    vec4 color;
    vec2 texCoord;
} vs_out;

void main()
{
    gl_Position = vec4(pos, 1.0) * uWorldTransform * uViewProj;
    vs_out.color = vec4(1.0, 1.0, 1.0, 1.0);
    vs_out.texCoord = texCoord * uTiling + uOffset;
}