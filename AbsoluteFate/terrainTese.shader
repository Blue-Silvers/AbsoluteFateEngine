#version 450 core

layout(triangles, fractional_even_spacing , cw) in;

in TESC_OUT{
    vec2 texCoord;

} tese_in[];
out TESE_OUT{
    vec2 texCoord;
} tese_out;

vec2 interpolate2D(vec2 v0, vec2 v1, vec2 v2)
{
    return vec2(gl_TessCoord.x) * v0 + vec2(gl_TessCoord.y) * v1 + vec2(gl_TessCoord.z) * v2;
}

void main(void)
{
    vec2 tc1 = mix(tes_in[0].texCoord, tes_in[1].texCoord, gl_TessCoord.x);
    vec2 tc2 = mix(tes_in[2].texCoord, tes_in[3].texCoord, gl_TessCoord.x);
    vec2 tc = mix(tc2, tc1, gl_TessCoord.y);

    // gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +
    // gl_TessCoord.y * gl_in[1].gl_Position +
    // gl_TessCoord.z * gl_in[2].gl_Position);
    // tese_out.color = mix(tese_in[0].color, tese_in[1].color, gl_TessCoord.x);;
    // tese_out.texCoord = interpolate2D(tese_in[0].texCoord, tese_in[1].texCoord, tese_in[2].texCoord);

    vec4 p1 = mix(gl_in[0].gl_Position, gl_in[1].gl_Position, gl_TessCoord.x);
    vec4 p2 = mix(gl_in[2].gl_Position, gl_in[3].gl_Position, gl_TessCoord.x);
    vec4 p = mix(p2, p1, gl_TessCoord.y);
    p.y += texture(tex_displacement, tc).r * dmap_depth;

    gl_Position = uViewProj * p;
    tes_out.texCoord = tc;
}