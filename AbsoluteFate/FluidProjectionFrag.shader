#version 330 core

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uInputTex;
uniform sampler2D uExtraTex;
uniform float uDelta;

void main()
{
    float left   = texture(uExtraTex, fragTexCoord + vec2(-uDelta.x, 0)).r;
    float right  = texture(uExtraTex, fragTexCoord + vec2(uDelta.x, 0)).r;
    float bottom = texture(uExtraTex, fragTexCoord + vec2(0, -uDelta.y)).r;
    float top    = texture(uExtraTex, fragTexCoord + vec2(0, uDelta.y)).r;

    vec2 vel = texture(uInputTex, fragTexCoord).xy;
    vel -= vec2(right - left, top - bottom) * 0.5;
    outColor = vec4(vel, 0.0, 1.0);
}