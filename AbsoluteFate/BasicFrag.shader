#version 450

in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D uTexture;

void main()
{
   outColor = texture(uTexture, fragTexCoord);

   if(outColor.a < 0.1) discard;
}
