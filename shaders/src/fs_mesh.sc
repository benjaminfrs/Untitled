$input v_color

#include "common.sh"
#include "uniforms.sh"

void main() {
    gl_FragColor = vec4(v_color, 1.0);
}
