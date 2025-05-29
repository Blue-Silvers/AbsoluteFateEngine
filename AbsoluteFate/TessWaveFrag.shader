#version 450 core

in TESE_OUT{
    vec4 color;
    vec2 texCoord;
    float diplacement;

} frag_in;

out vec4 FragColor;

layout(binding = 0)uniform sampler2D uTexture;

//Colors
uniform vec4 uBaseColor = vec4(0.2, 0.6, 0.9, 1.0);      /* vec4(0.2, 0.6, 0.9, 1.0) */
uniform vec4 uTopColor = vec4(0.92, 0.97, 1, 1.0);       /* vec4(1, 1, 1.0, 1.0) */  
uniform vec4 uBottomColor = vec4(0.07, 0.2, 0.60, 1.0);  /* vec4(0, 0, 0.75, 1.0) */ 

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

void main()
{
    vec2 newTexCoord = frag_in.texCoord;
    //newTexCoord.y += 1000;

    //foam color + base
    float foam = CustomClamp(frag_in.diplacement, 0.0, 1.0);
    vec4 foamWave = mix(uBaseColor* texture(uTexture, newTexCoord), uTopColor* texture(uTexture, newTexCoord), foam);
    //base color + depth
    float depth = 1 + CustomClamp(frag_in.diplacement, -1.0, 0.0);
    //final color
    FragColor = mix(uBottomColor* texture(uTexture, newTexCoord), foamWave, depth);
}