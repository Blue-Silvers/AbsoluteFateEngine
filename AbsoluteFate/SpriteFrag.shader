#version 450

layout (location = 0) in vec2 fragTexCoord;
layout (location = 1) in flat int renderOptions;
layout (location = 2) in flat int materialIdx;
out vec4 outColor;

layout (binding = 0) uniform sampler2D uTexture;
layout (binding = 1) uniform sampler2D fontAtlas;

// Input Buffers
// layout(std430, binding = 1) buffer Materials
// {
//   Material materials[];
// };

void main()
{
    outColor = texture(uTexture, fragTexCoord);

    if(outColor.a < 0.1) discard;

   /*Material material = materials[materialIdx];

  if(bool(renderOptions & RENDERING_OPTION_FONT))
  {
    vec4 textureColor = texelFetch(fontAtlas, ivec2(fragTexCoord), 0);

    if(outColor.a < 0.1) discard;

    outColor = textureColor.r * material.color;
  }
  else
  {
    vec4 textureColor = texelFetch(textureAtlas, ivec2(fragTexCoord), 0);

    if(outColor.a < 0.1) discard;

    outColor = textureColor * material.color;
  }*/
}
