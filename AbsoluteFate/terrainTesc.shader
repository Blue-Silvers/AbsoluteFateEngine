#version 450 core

layout(vertices = 3) out;

uniform int uTessLevel;
uniform mat4 uViewProj; ////////////////

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
        vec4 p0 = uViewProj * gl_in[0].gl_Position;
        vec4 p1 = uViewProj * gl_in[1].gl_Position;
        vec4 p2 = uViewProj * gl_in[2].gl_Position;
        vec4 p3 = uViewProj * gl_in[3].gl_Position;
        p0 /= p0.w;
        p1 /= p1.w;
        p2 /= p2.w;
        p3 /= p3.w;

        gl_TessLevelInner[0] = uTessLevel;
        gl_TessLevelInner[1] = uTessLevel;
        gl_TessLevelOuter[0] = uTessLevel;
        gl_TessLevelOuter[1] = uTessLevel;
        gl_TessLevelOuter[2] = uTessLevel;
        gl_TessLevelOuter[3] = uTessLevel;

        /*if (p0.z <= 0.0 || p1.z <= 0.0 || p2.z <= 0.0 || p3.z <= 0.0) 
        {
            gl_TessLevelOuter[0] = 0.0;
            gl_TessLevelOuter[1] = 0.0;
            gl_TessLevelOuter[2] = 0.0;
            gl_TessLevelOuter[3] = 0.0;
        } 
        else 
        {
            float l0 = length(p2.xy - p0.xy);
            float l1 = length(p3.xy - p2.xy);
            float l2 = length(p3.xy - p1.xy);
            float l3 = length(p1.xy - p0.xy);
            gl_TessLevelOuter[0] = l0 * 16.0 + 1.0;
            gl_TessLevelOuter[1] = l1 * 16.0 + 1.0;
            gl_TessLevelOuter[2] = l2 * 16.0 + 1.0;
            gl_TessLevelOuter[3] = l3 * 16.0 + 1.0;
            gl_TessLevelInner[0] = min(l1, l3);
            gl_TessLevelInner[1] = min(l0, l2);
        }*/

    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
    tesc_out[gl_InvocationID].texCoord = tesc_in[gl_InvocationID].texCoord;
}