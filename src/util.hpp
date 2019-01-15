#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Util {
    public:
        static GLuint create_shader (const char* filename, GLenum type);
};


#endif /* util_hpp */
