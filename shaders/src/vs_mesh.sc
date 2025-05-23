$input a_position
$output v_color

#include "common.sh"
#include "uniforms.sh"

void main() {
    gl_Position = mul(u_modelViewProj, vec4(a_position, 1.0));
    v_color = vec3(0.8, 0.2, 0.3);
}
