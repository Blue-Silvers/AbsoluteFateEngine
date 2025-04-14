#version 450

in vec2 fragTexCoord;
out vec4 outColor;

layout (binding = 0) uniform sampler2D uTexture;
layout (binding = 1) uniform sampler2D fontAtlas;

void main()
{
   outColor = texture(uTexture, fragTexCoord);

   if(outColor.a < 0.1) discard;
}
