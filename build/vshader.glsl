#version 410 compatibility
 
in vec3 in_Object;
in vec4 in_Alpha;
in vec2 in_CloudId;

out vec4 alpha;
varying vec2 vTextureCoordOffset;
varying vec2 vZoom;


void main(void)
{
   	alpha = in_Alpha;
        gl_Position = gl_ModelViewProjectionMatrix * vec4(in_Object, 1.0);   

	vec2 texSize = vec2(512,512);   	
	gl_PointSize = texSize;
	vec2 subTextureSize = texSize/4;
	vec2 offset = vec2( in_CloudId.x * subTextureSize.x, in_CloudId.y * subTextureSize.y);

	vZoom = subTextureSize/texSize;
	float u=offset.x / texSize.x;
	float v=offset.y / texSize.y;

	vTextureCoordOffset = vec2(u,v);
}
