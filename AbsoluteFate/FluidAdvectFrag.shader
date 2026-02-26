#version 330 core

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uInputTex;
uniform sampler2D uExtraTex;
uniform float uTimeStep;
uniform float uDelta;

void main()
{
    vec2 velocity  = texture(uExtraTex, fragTexCoord).xy;
    vec2 pos = fragTexCoord - uTimeStep * velocity * uDelta;
    outColor = texture(uInputTex, pos);
}