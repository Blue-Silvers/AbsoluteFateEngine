#version 450 core

layout(triangles, fractional_even_spacing , cw) in;

layout(binding = 1)uniform sampler2D uNoise;

uniform float uTime;
uniform float uDisplacement;
uniform float uAmplitude;
uniform float uFrequency;
uniform float uSpeed;
uniform bool uRightClamp; //set true if you woud like create a smootch clamp at the end of the wave

in TESC_OUT{
    vec2 texCoord;

} tese_in[];
out TESE_OUT{
    vec2 texCoord;
    float diplacement;

} tese_out;

vec2 interpolate2D(vec2 v0, vec2 v1, vec2 v2)
{
    return vec2(gl_TessCoord.x) * v0 + vec2(gl_TessCoord.y) * v1 + vec2(gl_TessCoord.z) * v2;
}

vec4 interpolate4D(vec4 v0, vec4 v1, vec4 v2) {
    return gl_TessCoord.x * v0 + gl_TessCoord.y * v1 + gl_TessCoord.z * v2;
}

float vertexAnimWave(vec2 uv, float noise)
{
    return sin((uv.x - uTime * uSpeed)* uFrequency) * (uAmplitude * noise);
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

    //Calcul for wave with noise
    float noise = texture(uNoise, uv * 10.0).r;
    float wave = vertexAnimWave(uv, noise);
    wave *= mix(0.5, 1.5, noise);
    if (uRightClamp == true)
    {
        wave *= CustomClamp(mix(1, 100, 1 - texPos.x/100), 1, 100);
    }
    else
    {
        wave *= 100;
    }

    //Update pos
    texPos.y += wave;
    gl_Position = texPos;

    //TESE_OUT
    tese_out.texCoord = uv;
    tese_out.diplacement = wave/100 * uDisplacement;
}