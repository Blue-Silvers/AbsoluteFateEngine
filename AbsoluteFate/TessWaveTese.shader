#version 450 core

layout(triangles, fractional_even_spacing , cw) in;

layout(binding = 1)uniform sampler2D uNoise;

in TESC_OUT{
    vec4 color;
    vec2 texCoord;

} tese_in[];
out TESE_OUT{
    vec4 color;
    vec2 texCoord;

} tese_out;

vec2 interpolate2D(vec2 v0, vec2 v1, vec2 v2)
{
    return vec2(gl_TessCoord.x) * v0 + vec2(gl_TessCoord.y) * v1 + vec2(gl_TessCoord.z) * v2;
}

void main(void)
{

    vec4 noise1 = mix(gl_in[0].gl_Position, gl_in[1].gl_Position, gl_TessCoord.x);
    vec4 noise2 = mix(gl_in[2].gl_Position, gl_in[3].gl_Position, gl_TessCoord.x);
    vec4 noise = mix(noise2, noise1, gl_TessCoord.y);
    vec2 tc = interpolate2D(tese_in[0].texCoord, tese_in[1].texCoord, tese_in[2].texCoord);
    noise.y += texture(uNoise, tc).r * 5;

    gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +
    gl_TessCoord.y * gl_in[1].gl_Position +
    gl_TessCoord.z * gl_in[2].gl_Position) /* * noise */;

    tese_out.color = mix(tese_in[0].color, tese_in[1].color, gl_TessCoord.x);;
    tese_out.texCoord = interpolate2D(tese_in[0].texCoord, tese_in[1].texCoord, tese_in[2].texCoord);
}