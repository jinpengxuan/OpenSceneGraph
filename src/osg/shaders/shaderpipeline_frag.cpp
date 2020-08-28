char shaderpipeline_frag[] = "#ifdef GL_ES\n"
                             "    precision highp float;\n"
                             "#endif\n"
                             "\n"
                             "#pragma import_modes ( GL_LIGHTING )\n"
                             "#pragma import_defines ( GL_MAX_TEXTURE_UNITS, GL_ALPHA )\n"
                             "\n"
                             "#pragma import_defines ( TEXTURE_FRAG_DECLARE0, TEXTURE_FUNCTION0, TEXTURE_ENV_FUNCTION0 )\n"
                             "#pragma import_defines ( TEXTURE_FRAG_DECLARE1, TEXTURE_FUNCTION1, TEXTURE_ENV_FUNCTION1 )\n"
                             "#pragma import_defines ( TEXTURE_FRAG_DECLARE2, TEXTURE_FUNCTION2, TEXTURE_ENV_FUNCTION2 )\n"
                             "#pragma import_defines ( TEXTURE_FRAG_DECLARE3, TEXTURE_FUNCTION3, TEXTURE_ENV_FUNCTION3 )\n"
                             "\n"
                             "#if GL_MAX_TEXTURE_UNITS>0\n"
                             "\n"
                             "uniform int osg_TextureFormat[GL_MAX_TEXTURE_UNITS];\n"
                             "uniform vec4 osg_TextureEnvColor[GL_MAX_TEXTURE_UNITS];\n"
                             "\n"
                             "vec4 texenv_MODULATE(vec4 color, vec4 texture_color, int unit) { return (osg_TextureFormat[unit]==GL_ALPHA) ? vec4(color.r, color.g, color.b, color.a*texture_color.a) :  color*texture_color; }\n"
                             "vec4 texenv_REPLACE(vec4 color, vec4 texture_color, int unit) { return (osg_TextureFormat[unit]==GL_ALPHA) ? vec4(color.r, color.g, color.b, texture_color.a) : texture_color; }\n"
                             "vec4 texenv_DECAL(vec4 color, vec4 texture_color, int unit) { color.rgb = color.rgb * (1.0-texture_color.a) + texture_color.rgb*texture_color.a; return color; }\n"
                             "vec4 texenv_ADD(vec4 color, vec4 texture_color, int unit) { color.rgb = color.rgb + texture_color.rgb; color.a = color.a*texture_color.a; return color; }\n"
                             "vec4 texenv_BLEND(vec4 color, vec4 texture_color, int unit) { color.rgb = color.rgb * (vec3(1.0,1.0,1.0)-texture_color.rgb) + texture_color.rgb * osg_TextureEnvColor[unit].rgb; return color; }\n"
                             "\n"
                             "#ifdef TEXTURE_FRAG_DECLARE0\n"
                             "    TEXTURE_FRAG_DECLARE0\n"
                             "#endif\n"
                             "\n"
                             "#ifdef TEXTURE_FRAG_DECLARE1\n"
                             "    TEXTURE_FRAG_DECLARE1\n"
                             "#endif\n"
                             "\n"
                             "#ifdef TEXTURE_FRAG_DECLARE2\n"
                             "    TEXTURE_FRAG_DECLARE2\n"
                             "#endif\n"
                             "\n"
                             "#ifdef TEXTURE_FRAG_DECLARE3\n"
                             "    TEXTURE_FRAG_DECLARE3\n"
                             "#endif\n"
                             "\n"
                             "#endif\n"
                             "\n"
                             "\n"
                             "varying vec4 vertex_color;\n"
                             "\n"
                             "void main()\n"
                             "{\n"
                             "    vec4 frag_color = vertex_color;\n"
                             "\n"
                             "#if GL_MAX_TEXTURE_UNITS>0\n"
                             "    #ifdef TEXTURE_FUNCTION0\n"
                             "        #ifdef TEXTURE_ENV_FUNCTION0\n"
                             "            frag_color = TEXTURE_ENV_FUNCTION0(frag_color, TEXTURE_FUNCTION0(), 0);\n"
                             "        #else\n"
                             "            frag_color = TEXTURE_FUNCTION0();\n"
                             "        #endif\n"
                             "    #endif\n"
                             "\n"
                             "    #ifdef TEXTURE_FUNCTION1\n"
                             "        #ifdef TEXTURE_ENV_FUNCTION1\n"
                             "            frag_color = TEXTURE_ENV_FUNCTION1(frag_color, TEXTURE_FUNCTION1(), 1);\n"
                             "        #else\n"
                             "            frag_color = TEXTURE_FUNCTION1();\n"
                             "        #endif\n"
                             "    #endif\n"
                             "\n"
                             "    #ifdef TEXTURE_FUNCTION2\n"
                             "        #ifdef TEXTURE_ENV_FUNCTION2\n"
                             "            frag_color = TEXTURE_ENV_FUNCTION2(frag_color, TEXTURE_FUNCTION2(), 2);\n"
                             "        #else\n"
                             "            frag_color = TEXTURE_FUNCTION2();\n"
                             "        #endif\n"
                             "    #endif\n"
                             "\n"
                             "    #ifdef TEXTURE_FUNCTION3\n"
                             "        #ifdef TEXTURE_ENV_FUNCTION3\n"
                             "            frag_color = TEXTURE_ENV_FUNCTION3(frag_color, TEXTURE_FUNCTION3(), 3);\n"
                             "        #else\n"
                             "            frag_color = TEXTURE_FUNCTION3();\n"
                             "        #endif\n"
                             "    #endif\n"
                             "\n"
                             "#endif\n"
                             "\n"
                             "    gl_FragColor = frag_color;\n"
                             "}\n"
                             "\n"
                             "\n";
