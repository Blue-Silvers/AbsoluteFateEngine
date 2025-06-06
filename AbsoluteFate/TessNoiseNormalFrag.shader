#version 450 core

in TESE_OUT{
    vec2 texCoord;
    float displacement;

} frag_in;

out vec4 FragColor;

layout(binding = 0)uniform sampler2D uTexture;
uniform float uShadowFactor = 1;             //[0-1]
//Normal
layout(binding = 2)uniform sampler2D uNormalTexture;
uniform vec3 uViewDir;
uniform vec3 uLightDir;
uniform float uNormalStrength = 0.5;         //[0-1]
uniform vec2 uNormalTiling;

//Colors
uniform vec4 uBaseColor = vec4(1, 1, 1, 1); //White by default

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
    //Read normal map
    vec3 normal = texture(uNormalTexture, frag_in.texCoord * uNormalTiling).rgb;

    //Remap value [0,1] to [-1,1]
    normal = normalize(normal * 2.0 - 1.0);

    //Calcul simple light
    vec3 lightDir = normalize(uLightDir);
    vec3 viewDir = normalize(uViewDir);
    vec3 halfwayDir = normalize(lightDir + viewDir);

    float diff = max(dot(normal, lightDir), 0.0);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 16.0);

    //Final color
    float depth = 1 - CustomClamp(frag_in.displacement, 0, 1);
    vec3 color = vec4(mix(uBaseColor, uBaseColor * (1-uShadowFactor), depth) * texture(uTexture, frag_in.texCoord)).rgb;
    vec3 lighting = mix(color, ((1.5 + diff + spec)) * color - vec3(0.2, 0.2, 0.2) , uNormalStrength);
    FragColor = vec4(lighting, 1.0);
}