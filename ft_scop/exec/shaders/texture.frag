// Version du GLSL

#version 150 core


// Entr�e

in vec2 coordTexture;
in vec4 color;

// Uniform

uniform sampler2D tex;
uniform float colorToTextureFloat;

// Sortie

out vec4 out_Color;


// Fonction main

void main()
{
    // Couleur du pixel
	vec4 tmp = texture(tex, coordTexture);
    out_Color = mix(color, tmp, colorToTextureFloat);
}