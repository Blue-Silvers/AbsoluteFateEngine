#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;


uniform mat4 uWorldTransform;
uniform mat4 uViewProj;
uniform vec2 uTiling;
uniform vec2 uOffset;

out VS_OUT
{
    vec2 texCoord;
} vs_out;

void main(void)
{
    const vec4 vertices[] = vec4[](vec4(-0.5, 0.0, -0.5, 1.0),
                                   vec4( 0.5, 0.0, -0.5, 1.0),
                                   vec4(-0.5, 0.0,  0.5, 1.0),
                                   vec4( 0.5, 0.0,  0.5, 1.0));

    int x = gl_InstanceID & 63;
    int y = gl_InstanceID >> 6;
    vec2 offs = vec2(x, y);

    // vs_out.texCoord = (vertices[gl_VertexID].xz + offs + vec2(0.5)) / 64.0;
    // gl_Position = vertices[gl_VertexID] + vec4(float(x - 32), 0.0, float(y - 32), 0.0);

    gl_Position = vec4(pos, 1.0) * uWorldTransform * uViewProj;
    vs_out.texCoord = texCoord * uTiling + uOffset;
}
