#version 330 core

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uInputTex;
uniform float uDelta;

void main()
{
    float left  = texture(uInputTex, fragTexCoord + vec2(-uDelta.x, 0)).x;
    float right = texture(uInputTex, fragTexCoord + vec2(uDelta.x, 0)).x;
    float bottom = texture(uInputTex, fragTexCoord + vec2(0, -uDelta.y)).y;
    float top    = texture(uInputTex, fragTexCoord + vec2(0, uDelta.y)).y;

    outColor = vec4(0.5 * ((right - left) + (top - bottom)), 0.0, 0.0, 1.0);
}