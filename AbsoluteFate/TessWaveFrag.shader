#version 450 core

in TESE_OUT{
    vec2 texCoord;
    float diplacement;

} frag_in;

out vec4 FragColor;

layout(binding = 0)uniform sampler2D uTexture;
//Normal
layout(binding = 2)uniform sampler2D uNormalTexture;
uniform vec3 uViewDir;
uniform vec3 uLightDir;
uniform float uNormalStrength = 0.5;
uniform vec2 uNormalTiling;
uniform float uTime;

//Colors
uniform vec4 uBaseColor = vec4(0.2, 0.6, 0.9, 1.0);      /* vec4(0.2, 0.6, 0.9, 1.0) */
uniform vec4 uTopColor = vec4(0.82, 0.87, 0.9, 1.0);     /* vec4(0.92, 0.97,, 1, 1.0) */  
uniform vec4 uBottomColor = vec4(0.07, 0.2, 0.6, 1.0);   /* vec4(0, 0, 0, 1.0) */ 

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
    //foam color + base
    float foam = CustomClamp(frag_in.diplacement, 0.0, 1.0);
    vec4 foamWave = mix(uBaseColor* texture(uTexture, frag_in.texCoord), uTopColor* texture(uTexture, frag_in.texCoord), foam);
    //base color + depth
    float depth = 1 + CustomClamp(frag_in.diplacement, -1.0, 0.0);
    //final color
    //FragColor = mix(uBottomColor* texture(uTexture, frag_in.texCoord), foamWave, depth);


    //Read normal map
    vec3 normal = texture(uNormalTexture, frag_in.texCoord * uNormalTiling + vec2(-uTime*0.1,0)).rgb;

    //Remap value [0,1] to [-1,1]
    normal = normalize(normal * 2.0 - 1.0);

    //Calcul simple light
    vec3 lightDir = normalize(uLightDir);
    vec3 viewDir = normalize(uViewDir);
    vec3 halfwayDir = normalize(lightDir + viewDir);

    float diff = max(dot(normal, lightDir), 0.0);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 16.0);

    //Final color
    vec3 color = mix(uBottomColor* texture(uTexture, frag_in.texCoord), foamWave, depth).rgb;
    vec3 lighting = mix(color, ((1.5 + diff + spec)) * color - vec3(0.2, 0.2, 0.2) , uNormalStrength);
    FragColor = vec4(lighting, 1.0);
}