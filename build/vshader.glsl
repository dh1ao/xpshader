#version 410 compatibility

in vec3 in_Position;
in vec3 in_Origin;

out vec2 out_Texture;

void main(void)
{
   out_Texture = vec2(in_Position.xy);
 
   vec3 pos = in_Origin + vec3(in_Position.xy*4000, 0.0);
   gl_Position = gl_ModelViewProjectionMatrix * vec4(pos,  1.0);

}
