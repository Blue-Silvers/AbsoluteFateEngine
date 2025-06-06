#version 450 core

layout(triangles, fractional_even_spacing , cw) in;

layout(binding = 1)uniform sampler2D uNoise;

uniform float uTime;
uniform float uHeightFactor;

in TESC_OUT{
    vec2 texCoord;

} tese_in[];
out TESE_OUT{
    vec2 texCoord;
    float displacement;

} tese_out;

vec2 interpolate2D(vec2 v0, vec2 v1, vec2 v2)
{
    return vec2(gl_TessCoord.x) * v0 + vec2(gl_TessCoord.y) * v1 + vec2(gl_TessCoord.z) * v2;
}

vec4 interpolate4D(vec4 v0, vec4 v1, vec4 v2) {
    return gl_TessCoord.x * v0 + gl_TessCoord.y * v1 + gl_TessCoord.z * v2;
}

float CustomClamp (float value, float min, float max)
{
    if(value >= max)
    {
        return max;
    }
    else if(value <= min)
    {
        return min;
    }
    return value;
}

void main(void)
{
    //Interpolate
    vec2 uv = interpolate2D(tese_in[0].texCoord, tese_in[1].texCoord, tese_in[2].texCoord);
    vec4 texPos = interpolate4D(gl_in[0].gl_Position, gl_in[1].gl_Position, gl_in[2].gl_Position);

    //Calcul for displacement with noise and height factor
    float noise = texture(uNoise, uv * 10.0).r;
    float displacement = uHeightFactor * noise * mix(50, 150, noise);

    //Update pos
    texPos.y += displacement;
    gl_Position = texPos;

    //TESE_OUT
    tese_out.texCoord = uv;
    tese_out.displacement = mix(0, 1, noise);
}