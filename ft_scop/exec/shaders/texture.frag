// Version du GLSL

#version 410 core

// Entr�e

in vec2 coordTexture;
in vec4 color;

// Uniform

uniform sampler2D tex;
uniform float coltotext;

// Sortie

out vec4 out_Color;


// Fonction main

void main()
{
    // Couleur du pixel
    vec4 tmp = texture(tex, coordTexture);
    out_Color = mix(color, tmp, coltotext);
}