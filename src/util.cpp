#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <streambuf>

#include "util.hpp"

using namespace std;

void print_log(GLuint object) {
    GLint log_length = 0;
    if (glIsShader(object)) {
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
    } else if (glIsProgram(object)) {
        glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
    } else {
        cerr << "printlog: Not a shader or a program" << endl;
        return;
    }

    char* log = (char*)malloc(log_length);
    
    if (glIsShader(object))
        glGetShaderInfoLog(object, log_length, NULL, log);
    else if (glIsProgram(object))
        glGetProgramInfoLog(object, log_length, NULL, log);
    
    cerr << log;
    free(log);
}


string read_file(const char* filepath) {
  ifstream file (filepath);
  stringstream ss;
  string line;
  while (getline (file,line)) {
    ss << line << "\n";
  }
  file.close();
  return ss.str();
}

GLuint Util::create_shader(const char* filename, GLenum type) {
	const GLchar * shader = read_file(filename).c_str();
    if (shader == NULL) {
        cerr << "Error opening " << filename << endl;
        return 0;
    }
    GLuint res = glCreateShader(type);
    glShaderSource(res, 1, &shader, NULL);
    glCompileShader(res);
    GLint compile_ok = GL_FALSE;
    glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
    if (compile_ok == GL_FALSE) {
        cerr << filename << ":";
        print_log(res);
        glDeleteShader(res);
        return 0;
    }
    return res;
}
