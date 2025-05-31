#version 450 core

layout(vertices = 3) out;

uniform int uTessLevel;

in VS_OUT{
    vec2 texCoord;
} tesc_in[];
out TESC_OUT{
    vec2 texCoord;
} tesc_out[];

void main(void)
{
    if (gl_InvocationID == 0)
    {
        gl_TessLevelInner[0] = uTessLevel;
        gl_TessLevelOuter[0] = uTessLevel;
        gl_TessLevelOuter[1] = uTessLevel;
        gl_TessLevelOuter[2] = uTessLevel;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
    tesc_out[gl_InvocationID].texCoord = tesc_in[gl_InvocationID].texCoord;
}