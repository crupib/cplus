#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Note: sampler name must match the name you set from the app
uniform sampler2D ourTexture;

void main()
{
    // Sample texture and mix with vertex color if desired
    vec4 tex = texture(ourTexture, TexCoord);
    // If texture has alpha, tex.a will be used when blending is enabled
    color = tex * vec4(ourColor, 1.0);
}
