#version 330 core

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uInputTex;  
uniform sampler2D uExtraTex;  
uniform float uAlpha; 
uniform float uBeta;  

void main()
{
    float left   = texture(uInputTex, fragTexCoord + vec2(-uBeta, 0)).x;
    float right  = texture(uInputTex, fragTexCoord + vec2(uBeta, 0)).x;
    float bottom = texture(uInputTex, fragTexCoord + vec2(0, -uBeta)).x;
    float top    = texture(uInputTex, fragTexCoord + vec2(0, uBeta)).x;
    float div    = texture(uExtraTex, fragTexCoord).x;

    float pressure = (left + right + bottom + top + uAlpha * div) / 4.0;
    outColor = vec4(pressure, 0.0, 0.0, 1.0);
}