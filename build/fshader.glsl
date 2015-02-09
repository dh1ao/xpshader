#version 330 
uniform sampler2D texUnit;
in vec2 out_Texture;
out vec4 colorOut;

void main(){
    colorOut=texture2D(texUnit, out_Texture); //.rgba * pixelAlpha;
}
