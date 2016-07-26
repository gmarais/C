// Version du GLSL

#version 150 core


// Entr�es

in vec3 in_Vertex;
in vec4 in_Color;
in vec2 in_TexCoord0;


// Uniform

uniform mat4 projection;
uniform mat4 modelview;


// Sortie

out vec2 coordTexture;
out vec4 color;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

    // Envoi de la couleur au Fragment Shader

    color = in_Color;

    // Envoi des coordonn�es de texture au Fragment Shader

    coordTexture = in_TexCoord0;
}
