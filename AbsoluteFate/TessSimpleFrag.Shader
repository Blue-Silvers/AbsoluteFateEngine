#version 450 core

in TESE_OUT{
    vec4 color;
    vec2 texCoord;

} frag_in;

out vec4 FragColor;

layout(binding = 0)uniform sampler2D uTexture;
//layout(binding = 1) uniform sampler2D uTest;

void main()
{
    FragColor = frag_in.color * texture(uTexture, frag_in.texCoord);
}