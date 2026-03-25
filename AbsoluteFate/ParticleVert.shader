#version 430 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec4 aColor;

out vec4 vColor;

void main() {
    vColor = aColor;
    
    gl_Position = vec4(aPos, 0.0, 1.0);
    
    gl_PointSize = 4.0; 
}