/*
 * Copyright (c) 2025 the ThorVG project. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

 #ifndef _TVG_GL_H_
 #define _TVG_GL_H_

 #include "glutils/gldefine.h"
    
#if defined (THORVG_GL_TARGET_GLES)
    #define TVG_REQUIRE_GL_MAJOR_VER 3
    #define TVG_REQUIRE_GL_MINOR_VER 0
#else
    #define TVG_REQUIRE_GL_MAJOR_VER 3
    #define TVG_REQUIRE_GL_MINOR_VER 3
#endif

#ifdef _DEBUG
    #define GL_CHECK(stmt) stmt; assert(glGetError() == GL_NO_ERROR);
#else
    #define GL_CHECK(stmt) stmt
#endif

bool glInit();
bool glTerm();

#endif // _TVG_GL_H_