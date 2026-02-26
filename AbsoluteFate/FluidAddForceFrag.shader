#version 330 core

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uInputTex;
uniform float uDelta;

void main()
{
    vec2 velocity = texture(uInputTex, fragTexCoord).xy;

    // Exemple : force centrée
    vec2 center = vec2(0.5, 0.5);
    vec2 dir = center - fragTexCoord;
    float dist = length(dir);
    velocity += normalize(dir) * 0.01 / (dist*dist + 0.01);

    outColor = vec4(velocity, 0.0, 1.0);
}