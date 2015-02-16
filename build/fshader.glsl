#version 330
uniform sampler2D texUnit;

in vec4 alpha;
in vec2 out_CloudId;
in mat4 mvp;
varying vec2 vTextureCoordOffset;
varying vec2 vZoom;
out vec4 colorOut;


void main(){
	vec3 up = vec3(mvp[1][0], mvp[1][1], mvp[1][2]);
    if (up.y <= 0.0001) up.y=0.0001;
	float angle_rad = 0-atan(up.x/up.y);
	//float angle_deg =40;
	//float pi = 3.1415926;
	//float angle_rad = angle_deg * pi / 180;
	float sinTheta = sin(angle_rad);
	float cosTheta = cos(angle_rad);
	mat2 rotMatrix = mat2 (cosTheta,sinTheta,-sinTheta,cosTheta);

	
	vec2 pt = gl_PointCoord-vec2(.5);
	pt = rotMatrix * pt;
	pt = pt+vec2(.5);
	pt = fract( pt) * vZoom+ vTextureCoordOffset;

    colorOut=texture2D(texUnit, pt) ;
	//colorOut=texture2D(texUnit, gl_PointCoord);
 	//colorOut=texture2D(texUnit, fract(gl_PointCoord) * vZoom + vTextureCoordOffset) * vec4(1.0,1.0,1.0,1.0);   
}