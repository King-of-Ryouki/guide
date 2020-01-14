if // 基礎 | 座標
{
    // 座標
    glTexCoord2f(0.0f, 0.0f); // 材質座標
    glVertex2f(width, 0);     // 二維向量

    // * glTexCoord2f(x, y);

    //          x
    // 1, 0     |     1, 1
    //          |
    // ---------|--------- y
    //          |
    // 0, 0     |     0, 1

    // * glVertex2f(x, y);

    //          x
    // 0, 0     |     0, 1
    //          |
    // ---------|--------- y
    //          |
    // 1, 0     |     1, 1
}

if // glutInit 初始化
{
    // glutInit is used to initialize the GLUT library.
    void glutInit(int *argcp, char **argv);
    // argcp
    // A pointer to the program's unmodified argc variable from main. Upon return, the value pointed to by argcp will be updated,
    // because glutInit extracts any command line options intended for the GLUT library.

    // argv
    // The program's unmodified argv variable from main. Like argcp, the data for argv will be updated,
    // because glutInit extracts any command line options understood by the GLUT library.

    // Description
    // glutInit will initialize the GLUT library and negotiate a session with the window system. During this process,
    // glutInit may cause the termination of the GLUT program with an error message to the user if GLUT cannot be properly initialized.
    // Examples of this situation include the failure to connect to the window system, the lack of window system support for OpenGL, and invalid command line options.

    // glutInit also processes command line options, but the specific options parse are window system dependent.
}

if // glGetError
{
    // https: //www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetError.xhtml
    // glGetError - return error information
    // C Specification
    GLenum glGetError(void);
}

if // 清除窗口 glClearColor() 与glClear()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // 设置清除颜色
    glClear(GL_COLOR_BUFFER_BIT);     // 把窗口清除为当前颜色
    glClearDepth(1.0);                // 指定深度缓冲区中每个像素需要的值
    glClear(GL_DEPTH_BUFFER_BIT);     // 清除深度缓冲区
}

if // glBegin()和glEnd()之间可调用的函数
{
    glBegin();

    // glVertex () 设置顶点坐标
    // glColor () 设置当前颜色
    // glIndex () 设置当前颜色表
    // glNormal () 设置法向坐标
    // glEvalCoord () 产生坐标
    // glCallList ),glCallLists() 执行显示列表
    // glTexCoord () 设置纹理坐标
    // glEdgeFlag () 控制边界绘制
    // glMaterial () 设置材质

    // glVertex函数用在glBegin和glEnd之间，除此以外没有意义。用来指定点、线和多边形的顶点。
    // 当调用glVertex时，可以为该顶点指定颜色、法线量和纹理坐标。
    // 当只指定x，y时，z缺省为0 .0，w缺省为1.0；当只指定x、y和z时，w缺省为1 .0。
    // glVertex3f() 表示了该函数属于 gl库, 参数是三个float型参数指针, 我们用glVertex *() 来表示这一类函数

    // 基本库 // 2.几何图元类型和说明

    // GL_POINTS           单个顶点集
    // GL_LINES            多组双顶点线段
    // GL_POLYGON          单个简单填充凸多边形
    // GL_TRIANGLES        多组独立填充三角形
    // GL_QUADS            多组独立填充四边形
    // GL_LINE_STRIP       不闭合折线
    // GL_LINE_LOOP        闭合折线
    // GL_TRIANGLE_STRIP   线型连续填充三角形串
    // GL_TRIANGLE_FAN     扇形连续填充三角形串
    // GL_QUAD_STRIP       连续填充四边形串

    // GL_POINTS           把每一个顶点作为一个点进行处理, 顶点n即定义了点n, 共绘制N个点
    // GL_LINES            把每一个顶点作为一个独立的线段, 顶点2n－1和2n之间共定义了n条线段, 总共绘制N/2条线段
    // GL_LINE_STRIP       绘制从第一个顶点到最后一个顶点依次相连的一组线段, 第n和n+1个顶点定义了线段n, 总共绘制n－1条线段
    // GL_LINE_LOOP        绘制从第一个顶点到最后一个顶点依次相连的一组线段, 然后最后一个顶点和第一个顶点相连, 第n和n+1个顶点定义了线段n, 总共绘制n条线段
    // GL_TRIANGLES        把每个顶点作为一个独立的三角形, 顶点3n－2、3n－1和3n定义了第n个三角形, 总共绘制N/3个三角形
    // GL_TRIANGLE_STRIP   绘制一组相连的三角形, 对于奇数n, 顶点n、n+1和n+2定义了第n个三角形；对于偶数n, 顶点n+1、n和n+2定义了第n个三角形, 总共绘制N-2个三角形
    // GL_TRIANGLE_FAN     绘制一组相连的三角形, 三角形是由第一个顶点及其后给定的顶点确定, 顶点1、n+1和n+2定义了第n个三角形, 总共绘制N-2个三角形
    // GL_QUADS            绘制由四个顶点组成的一组单独的四边形, 顶点4n－3、4n－2、4n－1和4n定义了第n个四边形, 总共绘制N/4个四边形
    // GL_QUAD_STRIP       绘制一组相连的四边形, 每个四边形是由一对顶点及其后给定的一对顶点共同确定的, 顶点2n－1、2n、2n+2和2n+1定义了第n个四边形, 总共绘制N/2-1个四边形
    // GL_POLYGON          绘制一个凸多边形, 顶点1到n定义了这个多边形,

    glEnd();
}

if // 基本状态管理 glEnable(), glDisable(), glIsable()
{
    // glEnable :用于启用各种功能, 其功能由参数决定
    // http://www.voidcn.com/article/p-rbqgmozj-pm.html

    // glDisable() 禁用
    // glIsable() 查询是否禁用

    // glEnable不能写在glBegin和glEnd两个函数中间

    // GL_LINE_STIPPLE         直线的点画模式
    // GL_BLEND                控制RGBA颜色的混合
    // GL_ALPHA_TEST           Alpha测试
    // GL_DEPTH_TEST           深度比较
    // GL_FOG                  雾
    // GL_LIGHTING             光照
    // GL_LIGHT0 ~ GL_LIGHT7   启用0号灯到7号灯(光源), 光源要求由函数glLight函数来完成

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // OpenGL（十三） Alpha测试、剪裁测试
    // https: //blog.csdn.net/dcrmg/article/details/53207214

    glAlphaFunc(GLenum_func, GLclampf ref);
    void glDepthFunc(GLenum func);
    // GLenum_func:
    // GL_NEVER     永不绘制
    // GL_LESS      如果目标像素z值  < 当前像素z值，则绘制目标像素
    // GL_EQUAL     如果目标像素z值  = 当前像素z值，则绘制目标像素
    // GL_LEQUAL    如果目标像素z值 <= 当前像素z值，则绘制目标像素
    // GL_GREATER   如果目标像素z值  > 当前像素z值，则绘制目标像素
    // GL_NOTEQUAL  如果目标像素z值 != 当前像素z值，则绘制目标像素
    // GL_GEQUAL    如果目标像素z值 >= 当前像素z值，则绘制目标像素
    // GL_ALWAYS    总是绘制

    // ref:
    // 0 ~ 1

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // 当我们需要绘制透明图片时，就需要关闭它
    glDisable(GL_DEPTH_TEST);
    // 并且打开混合
    glEnable(GL_BLEND);
    // 而且还需要设置使用的透明度
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
}

if // glFinish(), glFlush()
{
    // glFinish()
    // 将缓冲区的指令立即送往硬件执行，但是要一直等到硬件执行完这些指令之后才返回。
    // 如果直接绘制到前缓冲，那么在你想保存屏幕截图之前，就需要调用这个函数，确保绘制完毕。
    // 如果使用双缓冲，则这个函数不会有太大作用。

    // glFlush()
    // 清空缓冲区，将指令送往缓硬件立即执行，但是它是将命令传送完毕之后立即返回，不会等待指令执行完毕。这些指令会在有限时间内执行完毕。
    // 如果直接绘制到前缓冲，那么OpenGL的绘制将不会有任何延迟。设想有一个复杂的场景，有很多物体需要绘制。
    // 当调用glFlush时，物体会一个一个地出现在屏幕上。但是，如果使用双缓冲，这个函数将不会有什么影响，因为直到交换缓冲区的时候变化才显现出来。
    // 如果你使用的是双缓冲，那么可能这两个函数都不需要用到。缓冲区交换操作会隐式将命令送去执行。
}

if // glutGet
{
    // https: //www.opengl.org/resources/libraries/glut/spec3/node70.html

    int glutGet(GLenum state);

    // GLUT_WINDOW_X                   // X location in pixels (relative to the screen origin) of the current window.
    // GLUT_WINDOW_Y                   // Y location in pixels (relative to the screen origin) of the current window.
    // GLUT_WINDOW_WIDTH               // Width in pixels of the current window.
    // GLUT_WINDOW_HEIGHT              // Height in pixels of the current window.
    // GLUT_WINDOW_BUFFER_SIZE         // Total number of bits for current window's color buffer. For an RGBA window, this is the sum of GLUT_WINDOW_RED_SIZE, GLUT_WINDOW_GREEN_SIZE, GLUT_WINDOW_BLUE_SIZE, and GLUT_WINDOW_ALPHA_SIZE. For color index windows, this is the size of the color indexes.
    // GLUT_WINDOW_STENCIL_SIZE        // Number of bits in the current window's stencil buffer.
    // GLUT_WINDOW_DEPTH_SIZE          // Number of bits in the current window's depth buffer.
    // GLUT_WINDOW_RED_SIZE            // Number of bits of red stored the current window's color buffer. Zero if the window is color index.
    // GLUT_WINDOW_GREEN_SIZE          // Number of bits of green stored the current window's color buffer. Zero if the window is color index.
    // GLUT_WINDOW_BLUE_SIZE           // Number of bits of blue stored the current window's color buffer. Zero if the window is color index.
    // GLUT_WINDOW_ALPHA_SIZE          // Number of bits of alpha stored the current window's color buffer. Zero if the window is color index.
    // GLUT_WINDOW_ACCUM_RED_SIZE      // Number of bits of red stored in the current window's accumulation buffer. Zero if the window is color index.
    // GLUT_WINDOW_ACCUM_GREEN_SIZE    // Number of bits of green stored in the current window's accumulation buffer. Zero if the window is color index.
    // GLUT_WINDOW_ACCUM_BLUE_SIZE     // Number of bits of blue stored in the current window's accumulation buffer. Zero if the window is color index.
    // GLUT_WINDOW_ACCUM_ALPHA_SIZE    // Number of bits of alpha stored in the current window's accumulation buffer. Zero if the window is color index.
    // GLUT_WINDOW_DOUBLEBUFFER        // One if the current window is double buffered, zero otherwise.
    // GLUT_WINDOW_RGBA                // One if the current window is RGBA mode, zero otherwise (i.e., color index).
    // GLUT_WINDOW_PARENT              // The window number of the current window's parent; zero if the window is a top-level window.
    // GLUT_WINDOW_NUM_CHILDREN        // The number of subwindows the current window has (not counting children of children).
    // GLUT_WINDOW_COLORMAP_SIZE       // Size of current window's color index colormap; zero for RGBA color model windows.
    // GLUT_WINDOW_NUM_SAMPLES         // Number of samples for multisampling for the current window.
    // GLUT_WINDOW_STEREO              // One if the current window is stereo, zero otherwise.
    // GLUT_WINDOW_CURSOR              // Current cursor for the current window.
    // GLUT_SCREEN_WIDTH               // Width of the screen in pixels. Zero indicates the width is unknown or not available.
    // GLUT_SCREEN_HEIGHT              // Height of the screen in pixels. Zero indicates the height is unknown or not available.
    // GLUT_SCREEN_WIDTH_MM            // Width of the screen in millimeters. Zero indicates the width is unknown or not available.
    // GLUT_SCREEN_HEIGHT_MM           // Height of the screen in millimeters. Zero indicates the height is unknown or not available.
    // GLUT_MENU_NUM_ITEMS             // Number of menu items in the current menu.
    // GLUT_DISPLAY_MODE_POSSIBLE      // Whether the current display mode is supported or not.
    // GLUT_INIT_DISPLAY_MODE          // The initial display mode bit mask.
    // GLUT_INIT_WINDOW_X              // The X value of the initial window position.
    // GLUT_INIT_WINDOW_Y              // The Y value of the initial window position.
    // GLUT_INIT_WINDOW_WIDTH          // The width value of the initial window size.
    // GLUT_INIT_WINDOW_HEIGHT         // The height value of the initial window size.
    // GLUT_ELAPSED_TIME               // Number of milliseconds since glutInit called (or first call to glutGet(GLUT_ELAPSED_TIME)).
}

if // 回調函數 // callback functions
{
    glutReshapeFunc(AppReshape); // 遊戲的顯示範圍
    glutDisplayFunc(AppRender);

    glutKeyboardFunc(AppKeyboard);
    glutKeyboardUpFunc(AppKeyboardUp);

    glutSpecialFunc(AppSpecialKeys);
    glutSpecialUpFunc(AppSpecialKeysUp);

    glutIdleFunc(AppIdle); // gameover => exit(0)
}

if // glPointSize
{
    // glPointSize - specify the diameter of rasterized points
    void glPointSize(GLfloat size);

    // Parameters
    // size
    // Specifies the diameter of rasterized points.The initial value is 1.
}

////////////////////////////////////////////////////////////////////////////////////////////////////

if // 指定要激活的紋理單元 // glActiveTexture
{
    void glActiveTexture(GLenum texture);
    // texture
    // 0 ~ (GL_MAX_TEXTURE_COORDS - 1)
}

if // 創建 shader // glCreateShader()
{
    GLuint glCreateShader(GLenum shaderType);
    // shaderType
    // Specifies the type of shader to be created. Must be either
    // GL_VERTEX_SHADER   // 頂點
    // GL_FRAGMENT_SHADER // 碎片

    // GL_GEOMETRY_SHADER // 幾何
}

if // 加入 shader // glAttachShader(), glDetachShader()
{
    void glAttachShader(GLuint program, GLuint shader);
    // program
    // Specifies the program object to which a shader object will be attached.

    // shader
    // Specifies the shader object that is to be attached.

    void glDetachShader(GLuint program, GLuint shader);

    // program
    // Specifies the program object from which to detach the shader object.

    // shader
    // Specifies the shader object to be detached.
}

if // link a program object // glLinkProgram()
{
    void glLinkProgram(GLuint program);
    // program
    // Specifies the handle of the program object to be linked

    // 附加到程序的類型為 GL_VERTEX_SHADER 的著色器對像用於創建將在可編程頂點處理器上運行的可執行文件。
    // A shader object of type GL_VERTEX_SHADER attached to program is used
    // to create an executable that will run on the programmable vertex processor.

    // 附加到程序的類型為 GL_FRAGMENT_SHADER 的著色器對像用於創建將在可編程片段處理器上運行的可執行文件。
    // A shader object of type GL_FRAGMENT_SHADER attached to program is used to
    // create an executable that will run on the programmable fragment processor.
}

if // glGetUniformLocation()
{
    GLint glGetUniformLocation(GLuint program, const GLchar *name);
    // program
    // 指定要查詢的程序對象。
    // Specifies the program object to be queried.

    // name
    // 指向以null結尾的字符串，其中包含要查詢其位置的統一變量的名稱。
    // Points to a null terminated string containing the name of the uniform variable
    // whose location is to be queried.
}

if // 指定當前程序對象的統一變量的值 // glUniform(), glUniform1i(), glUniform1f()
{
    void glUniform1i(GLint location, GLint v0);
    void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

    void glUniform1f(GLint location, GLfloat v0);
    void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    // location
    // 指定要修改的統一變量的位置
    // Specifies the location of the uniform variable to be modified.

    // v0, v1, v2, v3
    // 指定要用於指定統一變量的新值
    // Specifies the new values to be used for the specified uniform variable.
}

if // 混合 源因子和目标因子 // glBlendFunc()
{
    glEnable(GL_BLEND); // 啟動混和
    void glBlendFunc(GLenum sfactor, GLenum dfactor);
    // 控制被处理片段（源片段）的颜色值如何与已经存储在帧缓冲区的像素（目标像素）的颜色值进行组合
    // 参数sfactor表示如何计算源混合因子，dfactor表示如何计算目标混合因子

    // 指定像素算術
    // specify pixel arithmetic

    // sfactor
    // Specifies how the red, green, blue, and alpha source blending factors are computed.
    // The following symbolic constants are accepted :

    // GL_ZERO, GL_ONE,
    // GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR,
    // GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR,
    // GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,
    // GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA,
    // GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR,
    // GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA
    // and GL_SRC_ALPHA_SATURATE // <== dfactor not have this one
    // The initial value is GL_ONE.

    // dfactor
    // Specifies how the red, green, blue, and alpha destination blending factors are computed.
    // The following symbolic constants are accepted:

    // The initial value is GL_ZERO.

    // 混合函數 (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) 實現透明度，其中基元從最遠到最近排序。
    // 請注意，此透明度計算不要求幀緩衝區中存在alpha位平面。

    // 混合函數 (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) 對於以任意順序渲染抗鋸齒點和線也很有用。

    // 混合函數 (GL_SRC_ALPHA_SATURATE, GL_ONE) 優化多邊形抗鋸齒，其中多邊形從最近到最遠排序。
}

////////////////////////////////////////////////////////////////////////////////////////////////////

if // glBlendFuncSeparate(), glBlendEquation(), glBlendEquationSeparate()
{
    glBlendFuncSeparate(GLenum srcRGB, GLenum destRGB, GLenum srcAlpha, GLenum destAlpha);
    //参数srcRGB表示颜色值的源混合因子，参数destRGB表示颜色在的目标混合因子，参数srcAlpha表示Alpha值的源混合因子，参数destAlpha表示Alpha值的目标混合因子

    // 指定常量颜色
    // 如果使用了其中一个GL*CONSTANT*混合函数就需要使用glBlendColor()指定一种常量颜色
    glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    //使当前颜色作为混合操作的常量颜色

    // 启用混合
    // glEnable(GL_BLEND)
    // 使用混合方程式组合像素
    glBlendEquation(GLenum mode);
    //指定帧缓存区与源颜色混合的方式
    glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
    //允许RGB和Alpha使用不同的混合方式
}

if // 点、直线和多边形 glPointSize(), glLineWidth(), glLineStipple(), glPolygonMode(), glPolygonStipple()
{
    // 默认情况下，点为一个像素，直线为一个像素的宽度，多边形则被画成实心填充的形式

    // 1.点
    glPointSize(GLfloat size); //设置被渲染点的宽度，以像素为单位，默认为1

    // 2.直线
    glLineWidth(GLfloat width);                    //设置直线的宽度，默认为1
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE);      //查询带锯齿直线宽度的范围
    glGetFloatv(GL_SMOOTH_LINE_WIDTH_RANGE);       //查询带平滑直线宽度的范围
    glGetFloatv(GL_SMOOTH_LINE_WIDTH_GRANULARITY); //查询平滑直线粒度的范围

    // 3.点画线
    glEnable(GL_LINE_STIPPLE); //打开直线的点画模式
    glLineStipple(1, 0x0101);  //设置直线的当前点画模式，1为倍数，0x0101为线型

    // 4.多边形
    glPolygonMode(GLenum face, GLenum mode);
    //控制多边形正面和反面的绘图形式，默认情况下face为GL_FRONT_AND_BACK，mode为GL_FILL，即正面和背面都采取填充形式绘制
    glFrontFace(GLenum mode);
    //控制多边形的正面是如何确定的，默认mode为GL_CCW(顶点为逆时针的表面为正面，GL_CW(顺时针为正面))
    glEnable(GL_CULL_FACE); //使剔除生效
    glCullFace();           //表示参数所设置的多边形在转换到屏幕坐标之前应该被丢弃

    // 5.点画多边形
    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(fly); //fly为一个指向32*32位图的指针
}

if // 法线向量与顶点数组 glNormal3f(), glEnableClientState(), glVertexPointer(), glDrawArrays()
{
    glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz); // 指定参数设置当前的法线向量
    glEnableClientState(GL_VERTEX_ARRAY);           // 顶点数组 //启用数组

    // 2表示顶点的坐标数量，GL_INT表示每个坐标数据类型，0表示数组中的顶点是紧密相连的
    // vertices表示第一个顶点的第一个坐标的内存地址
    glVertexPointer(2, GL_INT, 0, vertices);
    glArrayElement(GLint i); // 获取当前所有已启用数组的第i个顶点
    glDrawElements(GLenum mode, GLsizei count,
                   GLenum type, const GLvoid *indices); // 使用count元素定义一个几何图元序列, mode指被创建哪种类型的图元

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // 解引用一个数组元素序列
    glDrawArrays(GLenum mode, GLint first, GLsizei count);
    //相当于
    glBegin(mode);
    for (int i = 0; i < count; i++) {
        glArrayElement(first + i);
    }
    glEnd();
}

if // 混合数组 glInterleavedArrays()
{
    glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);

    //stride:连续顶点之间的字节偏移量
    //pointer:数组第一个顶点的第一个坐标的内存地址

    // 此函数的效果相当于

    int str;
    str = stride;
    if (str == 0) {
        str = s; //s为一个顶点到另一个顶点的跨距值
    }

    glDisable(GL_EDGE_FLAG_ARRAY);
    glDisable(GL_INDEX_ARRAY);
    glDisable(GL_SECONDARY_COLOR_ARRAY);
    glDisable(GL_FOG_COORD_ARRAY);

    if (et) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(st, GL_FLOAT, str, pointer);
    } else {
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    if (ec) {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(sc, tc, str, pointer + pc);
    } else {
        glDisableClientState(GL_COLOR_ARRAY);
    }
    if (en) {
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, str, pointer + pn);
    } else {
        glDisableClientState(GL_NORMAL_ARRAY);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(sv, GL_FLOAT, str, pointer + pv);
}

if // 缓冲区对象 glGenBuffers(), glBindBuffer(), glBufferData(), glMapBuffer()
{
    void glGenBuffers(GLsizei n, GLuint * buffers); //创建缓冲区对象 //在buffers数组中返回当前n个未使用的名称，表示缓冲区对象
    GLboolean glIsBuffer(GLuint buffer);            //判断是否是缓冲区对象

    void glBindBuffer(GLenum target, GLuint buffer); // 激活缓冲区对象 //指定当前活动缓冲区的对象

    void glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage); // 用数据分配和初始化缓冲区对象
    //target:可以是GL_ARRAY_BUFFER()（顶点数据）或GL_ELEMENT_ARRAY_BUFFER(索引数据)
    //size:存储相关数据所需的内存容量
    //data:用于初始化缓冲区对象，可以是一个指向客户区内存的指针，也可以是NULL
    //usage:数据在分配之后如何进行读写,如GL_STREAM_READ，GL_STREAM_DRAW，GL_STREAM_COPY，如图

    GLvoid *glMapBuffer(GLenum target, GLenum access); // 更新缓冲区数据值
    //提供对缓冲区对象包含的整个数据集合的更新
    //access:GL_READ_ONLY,GL_WRITE_ONLY,GL_READ_WRITE
    GLboolean *glUnMapBuffer(GLenum target);
    //表示当前绑定缓冲区对象的更新已经完成，与glMapBuffer()结合使用

    void glCopyBufferSubData(GLenum readbuffer, GLenum writebuffer,
                             GLintptr readoffset, GLintptr writeoffset,
                             GLsizeiptr size); // 在缓冲区对象之间复制数据
    //把数据从readbuffer相关联的缓冲区对象复制到writebuffer的缓冲区对象
    //从readoffset开始移动size个数据的数量到wirteoffset中

    void glDeleteBuffers(GLsizei n, GLuint * buffers); // 清除缓冲区对象
}

if // 属性组 glPushAttrib(), glPopAttrib(), glPushClientAttrib(), glPopClientAttrib()
{
    // 属性组：OpenGL将相关的状态变量进行归组
    glPushAttrib(GLbitfield mask); //保存状态变量
    glPopAttrib();                 //恢复状态变量

    // mask:
    glPushClientAttrib(GLbitfield mask); //压到客户属性组堆栈上
    glPopClientAttrib();                 //恢复状态变量
}

if // 通用的变换函数 glMatrixMode(), glLoadIdentity(), glLoadMatrixf(), glMultMatrixf();
{
    glMatrixMode(GL_PROJECTION); //表示把当前矩阵指定为用于投影变换
    // 视图矩阵 GL_MODELVIEW
    // 投影矩阵 GL_PROJECTION
    // 纹理矩阵 GL_TEXTURE

    glLoadIdentity();
    // 其功能是用一个4×4的单位矩阵来替换当前矩阵，实际上就是对当前矩阵进行初始化。也就是说，
    // 无论以前进行了多少次矩阵变换，在该命令执行后，当前矩阵均恢复成一个单位矩阵，即相当于没有进行任何矩阵变换状态。

    glLoadMatrixf(const GLfloat *m); //把当前矩阵的16个值设置为m指定的值
    glMultMatrixf(const GLfloat *m); //把m指定的16个值作为一个矩阵，与当前矩阵相乘，并把结果存储在当前矩阵中

    glLoadTransposeMatrixf(const GLfloat *m); //把当前矩阵的16个值设置为m指定的值
    glMultTransposeMatrixf(const GLfloat *m); //把m指定的16个值作为一个矩阵，与当前矩阵相乘，并把结果存储在当前矩阵中,按行主序
}

if // 操作矩阵堆栈 glPushMatrix(), glPopMatrix()
{
    glPushMatrix(); //把当前堆栈中的所有矩阵都下压一级。当前矩阵堆栈是由glMatrixMode()指定的。
    glPopMatrix();  //把堆栈顶部的那个矩阵弹出堆栈，销毁被弹出的矩阵内容
}

if // 模型变换 glTranslatef(), glRotatef(), glScalef()
{
    glTranslatef(GLfloat x, GLfloat y, GLfloat z); // 移动
    // 把当前矩阵与一个表示移动物体的矩阵相乘。这个矩阵有x, y, z指定
    glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z); // 旋转
    // 把当前矩阵与一个表示移动物体的矩阵相乘。以逆时针方向绕着从原点到点(x, y, z)的直线进行旋转，angle指定了旋转的度数
    glScalef(GLfloat x, GLfloat y, GLfloat z); // 缩放
    // 把当前矩阵与一个表示延各个轴对物体进行拉伸、压缩、反射的矩阵相乘。这个物体的每个点的x,y,z坐标与对应的xyz参数相乘
}

if // 视图变换 gluLookAt()
{
    // 视图变换函数必须在调用任何模型变换函数之前调用，确保首先作用于物体的是模型变换
    void gluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez,
                   GLdouble centerx, GLdouble centery, GLdouble centerz,
                   GLdouble upx, GLdouble upy, GLdouble upz);
    //相机位置由eyex、eyey、eyez指定，centerx、centery、centerz参数指定了模型的位置，upx、upy、upz参数表示那个方向是朝上的

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    gluLookAt(0.0, 0.0, 5.0, 0, 0, 0.0, 0.0, 1.0, 0.0); //视图变换
    //相当于
    glTranslatef(0, 0, -5);
}

if // 投影变换 glFrustum(), gluPerspective(), glOrtho(), gluOrtho2D()
{
    // 投影变换的最终目的是定义一个视景体，视景体有两个用途，首先，视景体是决定一个物体是如何映射到屏幕的，
    // 其次，视景体定义了哪些物体（或物体的一部分）被裁剪到最终的图像之外

    // 透视投影
    void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);

    void APIENTRY gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
    //fovy:角度 aspect：纵横比 zNear：观测点与近侧裁剪截面的距离 zFar：与远侧裁剪截面的距离
    gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // 正射投影 glOrtho();
    // 將當前矩陣與正交矩陣相乘
    // multiply the current matrix with an orthographic matrix
    void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble nearVal, GLdouble farVal);

    // Parameters
    // left, right
    // Specify the coordinates for the left and right vertical clipping planes.

    // bottom, top
    // Specify the coordinates for the bottom and top horizontal clipping planes.

    // nearVal, farVal
    // Specify the distances to the nearer and farther depth clipping planes.These values are negative if the plane is to be behind the viewer.

    // 參數
    // 左右
    // 指定左右垂直剪裁平面的坐標。

    // 底部，頂部
    // 指定底部和頂部水平剪裁平面的坐標。

    // nearVal，farVal
    // 指定距離更近和更深的剪裁平面的距離。 如果平面要在觀察者後面，則這些值為負。

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void APIENTRY gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
}

if // 视口变换 glViewport(), glDepthRange()
{
    // 以照相机为比例，视口变换相当于冲洗相片大小的这个阶段

    // set the viewport

    // C Specification
    void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

    // Parameters
    // x, y
    // Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0).

    // width, height
    // Specify the width and height of the viewport. When a GL context is first attached to a window, width and height are set to the dimensions of that window.

    // 參數
    // x，y
    // 指定視口矩形的左下角（以像素為單位）。 初始值為（0,0）。

    // 寬度，高度
    // 指定視口的寬度和高度。 首次將GL上下文附加到窗口時，將寬度和高度設置為該窗口的尺寸。

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    //在窗口中定义一个像素矩形，最终的图像将映射到这个矩形中，注意，视口的纵横比一般与视景体的纵横比相同
    void APIENTRY glDepthRange(GLclampd zNear, GLclampd zFar); //变换深度坐标，如图
}

if // 其他裁剪平面 glClipPlane()
{
    void glClipPlane(GLenum plane, const GLdouble *equation);
    //定义一个裁剪平面，equation参数指向平面方程Ax+By+Cz+D=0的4个系数，所有不是位于这个半空间的点都将被删除掉，
    //plane参数是GL_CLIP_PLANEi，其中i是一个整数，表示需要定义那个有效裁剪截面，i的值位于0和5之间

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 实例
    void display(void) {
        GLdouble eqn[ 4 ]  = { 0.0, 1.0, 0.0, 0.0 };
        GLdouble eqn2[ 4 ] = { 1.0, 0.0, 0.0, 0.0 };

        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(0.0, 0.0, -5.0); //移动模型

        // clip lower half -- y < 0
        glClipPlane(GL_CLIP_PLANE0, eqn); //裁剪平面 y < 0
        glEnable(GL_CLIP_PLANE0);         //使截面有效
        // clip left half -- x < 0
        glClipPlane(GL_CLIP_PLANE1, eqn2); //裁剪平面 x < 0
        glEnable(GL_CLIP_PLANE1);

        glRotatef(90.0, 1.0, 0.0, 0.0); //旋转圆体
        glutWireSphere(1.0, 20, 16);    //画圆体
        glPopMatrix();

        glFlush();
    }
}

if // 创建太阳系模型
{
    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);

        glPushMatrix();
        glutWireSphere(1.0, 20, 16);              /* draw sun */
        glRotatef((GLfloat) year, 0.0, 1.0, 0.0); //局部坐标系为原点，经过下行代码后，此局部坐标系向x轴走2单位
        glTranslatef(2.0, 0.0, 0.0);
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0); //局部坐标系为原点
        glutWireSphere(0.2, 10, 8);              /* draw smaller planet */
        glPopMatrix();
        glutSwapBuffers();
    }
}

if // 逆变换和模拟变换 gluUnProject(), gluProject()
{
    // gluUnProject();
    int gluUnProject(
        GLdouble winx, GLdouble winy, GLdouble winz,
        const GLdouble modelMatrix[ 16 ],
        const GLdouble projMatrix[ 16 ],
        const GLint viewport[ 4 ],
        GLdouble *objx, GLdouble *objy, GLdouble *objz);
    //这个函数使用由模型视图矩阵（modelMatrix）、投影矩阵（projMatrix）、和视口（viewport）定义的变换，把指定的窗口二维坐标(winx, winy, winz)映射到物体三维坐标
    //它产生的物体坐标是在objx、objy、objz中返回的，这个函数返回GL_TRUE表示返回成功或GL_FALSE表示失败。窗口深度坐标是winz根据gldepthRange()指定的，范围[0,1]。

    // gluProject();
    int APIENTRY gluProject(
        GLdouble objx, GLdouble objy, GLdouble objz,
        const GLdouble modelMatrix[ 16 ],
        const GLdouble projMatrix[ 16 ],
        const GLint viewport[ 4 ],
        GLdouble *winx, GLdouble *winy, GLdouble *winz);
    //与gluUnProject()功能相反，其作用是将物体坐标变换为窗口坐标

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 实例
    void mouse(int button, int state, int x, int y) {
        GLint viewport[ 4 ];
        GLdouble mvmatrix[ 16 ], projmatrix[ 16 ];
        GLint realy;         /*  OpenGL y coordinate position  */
        GLdouble wx, wy, wz; /*  returned world x, y, z coords  */

        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN) {
                    glGetIntegerv(GL_VIEWPORT, viewport);           //获取视口
                    glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);    //获取模型视图矩阵
                    glGetDoublev(GL_PROJECTION_MATRIX, projmatrix); //获取投影矩阵
                                                                    /*  note viewport[3] is height of window in pixels  */
                    realy = viewport[ 3 ] - (GLint) y - 1;
                    printf("Coordinates at cursor are (%4d, %4d)\n", x, realy);
                    gluUnProject((GLdouble) x, (GLdouble) realy, 0.0, //所求得的物体三维坐标位于近侧裁剪平面上0.0
                                 mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
                    printf("World coords at z=0.0 are (%f, %f, %f)\n",
                           wx, wy, wz);
                    gluUnProject((GLdouble) x, (GLdouble) realy, 1.0, //所求得的物体三维坐标位于远侧裁剪平面上1.0
                                 mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
                    printf("World coords at z=1.0 are (%f, %f, %f)\n",
                           wx, wy, wz);
                }
                break;
            case GLUT_RIGHT_BUTTON:
                if (state == GLUT_DOWN) { exit(0); }
                break;
            default:
                break;
        }
    }
}

if // 指定颜色和着色模型 glClampColor(), glIndexf(), glClearIndex(), glShadeModel()
{
    glColor3f(1.0, 0.0, 0.0);                       //设置绘图颜色
    void glClampColor(GLenum target, GLenum clamp); // 颜色截取 //指定主颜色值和辅助颜色值是否截取

    // 在颜色索引模式下指定颜色
    glIndexf(GLfloat c);     //把当前颜色索引设置为c
    glClearIndex(GLfloat c); //设置清除颜色，相当于RGBA模式下的glClearColor()函数

    glShadeModel(GL_SMOOTH); // 指定着色模型
}

if // 隐藏表面消除
{
    // 隐藏表面消除就是消除实心物体被其他物体所遮挡的部分。

    // 深度缓冲区的原理就是把一个距离观察平面（通常是近侧裁剪平面）的深度值与窗口中的每个像素相关联，一开始，使用glClear() 函数（以GL_DEPTH_BUFFER_BIT）
    // 把所有像素的深度值设置为最大可能距离（通常是远侧裁剪平面），然后以任意顺序绘制场景中的物体
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);
}

if // 创建光源 glLightfv()
{
    // 创建光源
    void glLightfv(GLenum light, GLenum pname, const GLfloat *params);
    //创建指定的光源,light可以是GL_LIGHT0、GL_LIGHT1，pname定义的是光源的属性，它指定了一个命名参数。params表示表示pname属性将要被设置的值

    // pname和params的值
    // </ pre><img src = "https://img-blog.csdn.net/20140219143512984?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYmlnZ2Jhbmc=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast" alt = "" /><p></ p><p></ p><p> 实例</ p><p></ p><pre code_snippet_id = "194701" snippet_file_name = "blog_20140219_2_1262765" name = "code" class = "cpp"> GLfloat light_position[] = {0, 0, 10, 0.0};
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    GLfloat light_ambient[] = { 0, 1, 1, 1 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient); //设置光的环境强度

    GLfloat light_diffuse[] = { 0, 0, 0, 1 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse); //散色光，GL_LIGHT0默认为（1,1,1,1）GL_LIGHT1-7默认为（0, 0, 0, 1）

    GLfloat light_diffuse[] = { 1, 1, 1, 0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_diffuse); //镜面光GL_LIGHT0默认为（1,1,1,1）GL_LIGHT1-7默认为（0, 0, 0, 1

    // 位置和衰减
    // 方向性光源：平行的光，如太阳光，不考虑衰减
    // 位置性光源，如台灯，考虑衰减
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 1 }; //最后一个参数为0，说明是方向性光源，非0则为位置性光源

    // 衰减：注意：环境光， 散射光，镜面光的强度都会衰减；发射光，全局环境光没有衰减

    // 聚光灯
    GLfloat spot_position[] = { -1.0, -1.0, 0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45);                //设置聚光灯的角度
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_position); //指定聚光灯的方向
}

if // 控制光源的位置和方向
{
    // 光源和观测点一起移动
    void display(void) {
        GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        //glPushMatrix ();
        glRotated((GLdouble) spin, 1.0, 0.0, 0.0);
        glLightfv(GL_LIGHT0, GL_POSITION, position);

        glTranslated(0.0, 0.0, 1.5);
        glDisable(GL_LIGHTING);
        glColor3f(0.0, 1.0, 1.0);
        glutWireCube(0.1);
        glEnable(GL_LIGHTING);
        //glPopMatrix ();
        glTranslated(0.0, 0.0, 1.5); //增加的代码

        glutSolidTorus(0.275, 0.85, 8, 15);
        glPopMatrix();
        glFlush();
    }
}

if // 选择光照类型 glLightModel(), glEnable()
{
    // 全局环境光
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    // 把无限远的观察点改为局部观察点
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    // 设置双面光照
    // 使物体的背面接受的光照准确
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    // 镜面辅助颜色
    // 执行纹理贴图是才有用，可使效果逼真，其原理是：把镜面光从主颜色中抽离出来，在纹理贴图后，再把镜面光加进去
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
    // 恢复到默认值可以调用
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR);

    // 启用和禁用光照
    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHTING);
}

if // 定义材料属性 glMaterial()
{
    // 散射和环境反射
    // 环境颜色影响物体的状整体颜色，当物体被直接照亮时，散射颜色占据主导地位，只有当物体并没有收到直接光照时，环境颜色才占据主导地位。
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, amb_Diff);
    //表示材料正面和背面的散射和环境反射是amb_Diff颜色

    // 镜面反射
    // 镜面指数越大，亮点就更小更亮
    GLfloat amb_Diff[ 4 ] = { 0.1, 0.5, 0.8, 1.0 };
    GLfloat specular[ 4 ] = { 1, 1, 1, 1.0 };
    GLfloat shin[]        = { 10 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular); //颜色
    glMaterialfv(GL_FRONT, GL_SHININESS, shin);    //镜面指数

    // 发射光颜色
    // 使物体看上去好像发出这种颜色的光，如台灯
    GLfloat emission[ 4 ] = { 0.3, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, emission); //颜色
}

if // 和光照有关的数学知识
{
    // 使用光照后，顶点的颜色是按照下面的公式计算的：
    // 顶点的颜色 = 顶点处的材料发射颜色+全局环境光+经过适当衰减的来自所有光源的环境、散射和镜面光成分

    // 1.材料的发射光
    // 就是赋值给GL_EMISSION的RGB值

    // 2.经过缩放后的全局环境光
    // 即全局环境光 *材料环颜色属性
    // ambient(bright model) * ambient(martial)

    // 3.光源的贡献 = 衰减因子 * 聚光灯效果 * （环境光 + 散射光 + 镜面光）
}

if // 抗锯齿 glHint(), glutInitDisplayMode(), glSampleCoverage()
{
    void glHint(GLenum target, GLenum mode);
    //控制OpenGL的一些行为，target参数表示需要控制什么行为，其取值见表，
    //mode参数可以是GL_FASTEST,表示效率最高，可以是GL_NICEST表示质量最好，或者GL_DONT_CARE,表示没什么偏向

    // 对点和直线进行抗锯齿处理
    // 方法一：
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    // 方法二：RGBA模式下的抗锯齿
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //混合
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);         //抗锯齿

    // 使用多重采样对几何图元进行抗锯齿处理
    // 多重采样不是使用alpha值来表示一个图元覆盖某个像素的程度，而是根据一个多重采样缓冲区所保存的样本来计算抗锯齿覆盖信息

    // 增加多重采样功能的三个步骤
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);

    static GLint buf[ 1 ], sbuf[ 1 ];
    glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, buf);
    glGetIntegerv(GL_SAMPLES_ARB, sbuf);

    // alpha和多重采样覆盖 // glEnable (GL_MULTISAMPLE_ARB);
    void glSampleCoverage(GLclampf value, GLboolean invert);
    //设置参数，用于在计算多重采样覆盖值时解释alpha值
    //value值如图，invert表示是否进行逐位的反转
}

if // 雾 glFog(), glFogCoordf()
{
    // 雾是根据雾混合因子把雾颜色与源片段的颜色进行混合
    // 雾混合因子f的计算表达式：https://blog.csdn.net/biggbang/article/details/19629529
    // OpenGL学习笔记:雾（fog) https://blog.csdn.net/lcphoenix/article/details/6646721

    void glFogf(GLenum pname, GLfloat param);
    //设置用于雾计算的参数和函数，如果pname是GL_FOG_MODE，那么param就是GL_EXP(默认)、GL_EXP或GL_LINEAR，它们分别用于选择三种不同的雾因子
    //如果pname是GL_FOG_DENSITY,GL_FOG_START或GL_FOG_END，那么param就是density,start,end的值，如果是向量版本，那么pname就是指向这些值的指针
    //在RGBA模式下，pname是GL_FOG_COLOR,此时，param指向包含了雾的RGBA颜色的4个值

    // 雾坐标z的设置
    void glFogCoordf(TYPE z);
    //把当前的雾坐标设置为z
}

if // 点参数 glPointParameter()
{
    void glPointParameterfvEXT(GLenum pname, const TYPE *param);
    //设置点图元的渲染相关的值

    glPointParameterfvEXT(GL_DISTANCE_ATTENUATION_EXT, linear);
    //如果pname参数是GL_DISTANCE_ATTENUATION_EXT，那么param就是一个包含三个浮点值(a,b,c)的数组，分别包含了常数，线性或二次衰减系数用于根据点与观察点的距离d来计算点的大小和亮度

    glPointParameterfEXT(GL_POINT_SIZE_MIN, value);
    //如果pname设置为GL_POINT_SIZE_MIN或GL_POINT_SIZE_MAX,那么param便是一个绝对限制（分别表示最低值和最高值）

    glPointParameterfEXT(GL_POINT_FADE_THRESHOLD_SIZE_EXT, 2.0);
    //如果启用了多重采样，并且pname是GL_POINT_FADE_THRESHOLD_SIZE_EXT，那么param就指定了点大小的一个不同的低限。

    glPointParameterfEXT(GL_POINT_SPRITE_COORD_ORIGIN, GL_LOWER_LEFT);
    //如果pname是GL_POINT_SPRITE_COORD_ORIGIN，param指定为GL_LOWER_LEFT， 那么点块纹理上被迭代的纹理坐标的原点就是左下角的片段，t纹理坐标沿片段自底向上垂直增加。如果param是GL_UPPER_LEFT时，t纹理坐标沿片段自顶向下垂直减少
}

if // 多边形偏移 glPolygonOffset(), glPolygonMode()
{
    void display(void) {
        GLfloat gray[]  = { 0.8, 0.8, 0.8, 1.0 };
        GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glTranslatef(0.0, 0.0, tdist);
        glRotatef((GLfloat) spinx, 1.0, 0.0, 0.0);
        glRotatef((GLfloat) spiny, 0.0, 1.0, 0.0);

        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
        glMaterialfv(GL_FRONT, GL_SPECULAR, black);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_POLYGON_OFFSET_FILL); //启用多边形偏移
        glPolygonOffset(polyfactor, polyunits);
        //计算偏移值
        glCallList(list);
        glDisable(GL_POLYGON_OFFSET_FILL);

        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glColor3f(1.0, 1.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //设置当前的多边形光栅化方法
        glCallList(list);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glPopMatrix();
        glFlush();
    }
}

if // 无法再显示列表中存储的函数
{
    // 1.具有返回值的函数
    // 2.用于修改客户状态的函数, glPixelStore(), glSelectBuffer()
    // 3.定义顶点数组的函数 glVertexPointer()
    // 4.所有使用了像素存储模式的函数
    // 5.依赖于客户状态的函数glFlush(), glFinish()
}

if // 管理显示列表索引 glIsList(), glDeleteLists(), glGetIntegerv()
{
    GLboolean glIsList(GLuint list);
    //如果list已经用于表示显示列表，这个函数返回GL_TRUE,否则返回GL_FALSE

    void glDeleteLists(GLuint list, GLsizei range);
    //删除range个显示列表，从list指定的索引开始

    glGetIntegerv(GL_MAX_LIST_NESTING, GLint * data);
    //获取显示列表的嵌套层次限制
}

if // word FFF.cc // 位图与字体 glRasterPos(), glWindowPos(), glBitmap()
{
    void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z = 0, GLdouble w = 1);
    void glRasterPos4dv(const GLdouble *v);
    //确定当前光栅位置，x,y,z,w指定了当前光栅位置的坐标

    glWindowPos(Type x, Type y, Type z);
    //用窗口坐标指定当前光栅位置，不必进行矩阵变换、裁剪、或纹理坐标生成。z值被变换为由glDepthRange()设置的当前近侧平面值和远侧平面值

    void glBitmap(GLsizei, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat, GLfloat, const GLubyte *bitmap);
    //绘制由bitmap指定的位图，bitmap是一个指向位图图像的指针，位图的原点是当前光栅位置，如果当前光栅位置无效，则这个函数不会绘制任何东西。
    //width和height表示位图的宽度和高度，xorig和yorig定义了位图的原点，他是根据当期光栅位置确定的，右上为正。
    //xmove和ymove表示位图光栅化之后光栅坐标的x增加值和y增加值
}

if // 图像 glDrawPixels(), glCopyPixels(), glReadPixels()
{
    // https://blog.csdn.net/biggbang/article/details/19806577

    void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
    //从帧缓冲区中的一个矩形区域读取像素数据，这个矩形区域的左下角窗口坐标(x,y)，他的宽度和高度分别为width，height
    //读取的像素保存在pixels所指向的数组中，format表示此函数所读取的像素数据元素的类型见表
    //type表示每个元素的数据类型

    // 把像素数据从内存中写入到帧缓存区
    void glDrawPixels(GLsizei width, GLsizei, GLenum format, GLenum type, const GLvoid *pixels);
    //绘制一个宽度和高度分别为width和height的像素数据这个像素矩形的左下角就是当前光栅位置，format与type和上图相同
    //pixels所指向的数组包含了被绘制的像素数据

    // 从帧缓存区的一个矩形区域(x,y,width,height)复制数据：
    void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum);
    //从帧缓存区的一个矩形区域(x,y,width,height)复制数据，数据被复制到帧缓存区的一个新位置，它的左下角是当前光栅坐标
    //type是GL_COLOR, GL_STENCIL,GL_DEPTH,指定了这个函数所使用的帧缓存区
}

if // 图像管线 glPixelStore(), glPixelTransfer(), glPixelMapf(), glPixelZoom()
{
    // https://blog.csdn.net/biggbang/article/details/19911181

    // 1.像素的包装和解包
    // 包装和解包是指像素数据写入到内存以及从处理器内存读取的方式

    // 2.控制像素的存储模式
    void glPixelStorei(GLenum pname, GLint param);
    //设置像素的存储模式。pname参数可见下表，GL_UNPACK*参数控制数据在内存中是如何由函数解包的
    //GL_PACK*参数控制数据如何包装到内存的

    // 3.像素传输操作
    void glPixelTransferi(GLenum pname, GLint param);
    //设置像素传输模式。pname、param见下表

    // 4.像素映射
    void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
    //加载由map所确定的像素映射表，它有mapsize个项，values表示它们的值。见表

    // 5.放大、缩小和翻转图像
    void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
    //设置图像的写入操作。默认情况下，xfactor、yfactor都是1.0，如果它们都是2.0，
    //那么图像的每个像素被绘制成4个屏幕像素,负的缩放因子执行翻转操作
}

if // 读取和绘制像素矩形
{
    // https: //blog.csdn.net/biggbang/article/details/19915627
}

if // 颜色表 glColorTable(), glColorTableParameter(), glCopyColorTable()
{
    // 1.颜色表的种类
    // 可以调用glEnable()单独启用各个颜色表

    // 2.指定颜色表
    glColorTable(GLenum target, GLenum InternelFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *data);
    //target设置为上表的三个参数时，说明此函数用于定义指定的颜色表，如果为其他，就用于验证指定的颜色表在可用的资源中是否适用；
    //InternelFormat用于确定data的内部表现形式，它的一般参数见下表；
    //width表示颜色表中像素数量，必须是2的幂；

    glColorTableParameterfv(GLenum target, GLenum pname, Type * param);
    //指定需要设置和缩放偏移的颜色表

    glCopyColorTable();
    //创建一个颜色表看，使用帧缓存区的数据来定义颜色表的颜色；
    glColorSubTable();
    //替换颜色表的一部分
}

if // 卷积 glConvolutionFilter2D(), glCopyConvolutionFilter2D(), glSeparableFilter2D()
{
    glConvolutionFilter2D(
        GLenum target, GLenum,
        GLsizei width, GLsizei height,
        GLenum format, GLenum type,
        const GLvoid *image);
    //定义一个二维卷积过滤器，其中target参数必须是GL_CONVOLUTION_2D。internalFormat与gglColorTable()的参数相同
    //width和height参数指定了卷积过滤器的大小。和glDrawPixel()一样，这个函数的format和type参数指定了image存储的像素格式

    // 可以使用glEnable(GL_CONVOLUTION_2D);

    // 启用2D卷积处理功能。 定义一个帧缓存区，用颜色帧缓存区的像素对它进行初始化：
    glCopyConvolutionFilter2D(
        GLenum target, GLenum internalFormat,
        GLint x, GLint y, GLsizei width, GLsizei height);
    //target参数必须是GL_CONVOLUTION_2D。internalFormat必须设置为glConvolutionFilter2D()所使用的内部格式
    //这个像素矩阵的左下角像素是(x, y),像素数量是 width * height;

    // 指定可分离的二维卷积过滤器：
    glSeparableFilter2D(
        GLenum target, GLenum,
        GLsizei width, GLsizei height,
        GLenum format, GLenum type,
        const GLvoid *row, const GLvoid *column);
    //定义了一个二维的一个可分离的卷积过滤器，target参数必须设置为GL_SEPARABLE_2D。internalFormat与gglColorTable()的参数相同
    width指定了row数组中的像素数量，height指定了column数组中像素的数量。format和type参数指定了row和column存储的像素格式
    //可以用glEnable(GL_SEPARABLE_2D)启用2D卷积处理功能
}

if // 柱状图 glHistogram(), glGetHistogram()
{
    glHistogram(GLenum target, GLsizei width, GLenum internalFormat, GLboolean sink);
    glHistogram(GL_HISTOGRAM, HISTOGRAM_SIZE, GL_RGB, GL_FALSE);
    //定义了应该如何存储一幅图像的柱状图数据。target必须设置为GL_HISTOGRAM或GL_PROXY_HISTOGRAM.
    //width参数指定了柱状图表中项的数量，它的值必须是2的整数次方。
    //internalFormat参数定义了柱状图数据应该如何存储
    //sink参数表示这些像素应该继续进入到图像处理关系的最小最大阶段还是应该放弃

    glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
    glGetHistogram(GL_HISTOGRAM, GL_TRUE, GL_RGB, GL_UNSIGNED_SHORT, values);
    //返回已收集的柱状图统计信息，target参数必须是GL_HISTOGRAM，reset指定内部柱状图表是否应该被删除
}

if // 最大最小像素值 glGetMinmax(), glMinmax()
{
    glMinmax(GLenum target, GLenum internalFormat, GLboolean sink);
    glMinmax(GL_MINMAX, GL_RGB, GL_FALSE);
    glEnable(GL_MINMAX);
    //计算一副图像的最小像素值和最大像素值，target参数必须为GL_MINMAX,
    //internalFormat参数指定了应该计算哪些颜色成分的最大最小值
    //如果sink为GL_TRUE，则抛弃，否则图像就会进行渲染

    glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * sink);
    glGetMinmax(GL_MINMAX, GL_TRUE, GL_RGB, GL_UNSIGNED_BYTE, values);
    //返回最大最小操作结果，target参数必须是GL_MINMAX，如果reset参数设置为GL_TRUE最小值和最大值就重置为它们的初始值
}

if // 指定纹理 glTexImage2D(), gluScaleImage(), glCopyTexImage2D(), glTexSubImage2D()
{
    // 定义一个二维纹理：

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA,
        checkImageWidth, checkImageHeight,
        0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
    void glTexImage2D(
        GLenum target, GLint level,
        GLint internalformat, GLsizei width,
        GLsizei height, GLint border, GLenum format,
        GLenum type, const GLvoid *pixels);
    //target参数用于定义二维纹理；
    //如果提供了多种分辨率的纹理图像，可以使用level参数，否则level设置为0；
    //internalformat确定了哪些成分(RGBA, 深度, 亮度和强度)被选定为图像纹理单元
    //width和height表示纹理图像的宽度和高度；
    //border参数表示边框的宽度
    //format和type参数描述了纹理图像数据的格式和数据类型
    //pixels参数包含了纹理图像的数据，这个数据描述了纹理图像本身和它的边框

    // 改变纹理图像的大小：
    int gluScaleImage(
        GLenum format, GLint widthin,
        GLint heightin, GLenum typein,
        const void *datain, //存储的纹理图像数据
        GLint widthout, GLint heightout,
        GLenum typeout,
        void *dataout); //最终的纹理图像数据

    // 从帧缓存区读取一块矩形像素，并且把它定义为纹理单元：
    void glCopyTexImage2D(
        GLenum target, GLint level, GLenum internalFormat,
        GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    //纹理数组是从屏幕对齐的像素矩形读取的，它的左下角是(x, y)表示的坐标

    // 查询纹理状态变量的值：
    void glGetTexLevelParameterfv(
        GLenum target, GLint level,
        GLenum pname, GLfloat * params);
    //params参数中，返回一个特定细节层的纹理参数值，这个细节层由level参数指定；
    //target参数定义了目标纹理

    // 定义一个二维纹理图像，替换当前一副现有的二维图像的全部或一块连续的区域：
    glTexSubImage2D(
        GL_TEXTURE_2D, 0, 12, 44, subImageWidth,
        subImageHeight, GL_RGBA,
        GL_UNSIGNED_BYTE, subImage);
    void glTexSubImage2D(
        GLenum target, GLint level,
        GLint xoffset, GLint yoffset,
        GLsizei width, GLsizei height,
        GLenum format, GLenum type,
        const GLvoid *pixels);
    //pixels包含了表示子图像的纹理数据
    //width和height表示表示子区域的宽度和高度
    //xoffset和yoffset表示x和y方向上的纹理单元偏移量
}

if // 压缩纹理图像 glGetTexLevelParameter(), glCompressedTexImage2D()
{
    // 1.在加载时压缩纹理图像
    // 在加载纹理图像时，只需把internalFormat参数设置为其中一种GL_COMPRESSED_*枚举值即可
    // 可以使用glGetTexLevelParameterfv()判断是否被压缩及压缩的格式。

    // 2.加载经过压缩的纹理图像
    glCompressedTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *texels);
    //internalformat指定了经过压缩的纹理对象的格式
}

if // 之 mipmap glGenerateMipmap(), gluBuild2DMipmaps(), gluBuild2DMipmapLevels()
{
    // 3.1后的版本：
    int glGenerateMipmap(GLenum target);
    //为与target相关联的纹理图像生成一组完整的mipmap，

    // 前的版本：
    gluBuild2DMipmaps() int gluBuild2DMipmaps(
        GLenum target, GLint components,
        GLint width, GLint height,
        GLenum format, GLenum type, const void *data);
    //创建一系列的mipmap，并调用glTexImages*D()加载这些纹理图像
    //参数与glTexImage2D()完全相同，如果所有的mipmap创建成功，这个函数就返回0

    int gluBuild2DMipmapLevels(
        GLenum target, GLint internalFormat, GLint width, GLint height, GLint depth,
        GLenum format, GLenum type, GLint level, GLint base, GLint max, void *texels);
    //创建一系列的mipmap, 并调用函数glTexImage*D()来加载它们.（是上面函数的子集）
    //level: 图像texels的mipmap等级.
    //base, max: 确定要从texels中提取哪些mipmap层

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 5);
    //设置mipmap的最大最小层
}

if // 过滤
{
    // https://blog.csdn.net/biggbang/article/details/20060385

    // 指定放大和做小的过滤方法
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //第二个和第三个参数可以是下图值
}

if // red_chessboard.cc // 纹理对象 glGenTextures(), glIsTexture(), glBindTexture(), glDeleteTextures()
{
    // 命名纹理对象：
    void glGenTextures(GLsizei n, GLuint * textures);
    //在数组textures中返回n个当期未使用的值，表示纹理对象的名称
    //零作为一个保留的纹理对象名，它不会被此函数当做纹理对象名称而返回

    // 判断一个纹理名称是否处于实际使用中：
    GLboolean glIsTexture(GLuint texture);
    //如果texture是一个已绑定的纹理对象名称，并且没有删除，就返回GL_TRUE；

    // 创建和使用纹理对象：

    glBindTexture(GL_TEXTURE_2D, texName[ 0 ]);
    void glBindTexture(GLenum target, GLuint texture);
    //应用程序第一次在这个函数使用texture值时，这个函数将会创建一个新的纹理对象
    //当texture是一个以前已经创建的纹理对象时，这个纹理对象就成为活动对象
    //如果texture为0，就停止使用这个纹理对象，并返回无名称的默认纹理

    // 清除纹理对象：
    glDeleteTextures(2, texName);
    void glDeleteTextures(GLsizei n, const GLuint *textures);
    //删除n个纹理对象，它们的名称由textures数组提供
}

if // 常驻纹理工作集 glAreTexturesResident(), glPrioritizeTextures()
{
    GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences);
    //查询n个纹理对象的纹理常驻状态，这些纹理对象的名称由textures指定，函数返回的常驻状态保存在residences数组中

    void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);
    //向n个纹理对象分配纹理常驻优先级，这些纹理对象的名称由textures指定，相应的优先级在priorities数组中设置
}

if // 纹理函数（设置绘图模式） glTexEnv()
{
    // https: //blog.csdn.net/biggbang/article/details/20132785
    // 设置当前的纹理函数：

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
    //target必须是GL_TEXTURE_FILTER_CONTROL或GL_TEXTURE_ENV
    //如果target是GL_TEXTURE_FILTER_CONTROL，那么pname必须是GL_TEXTURE_LOD_BIAS,param必须是一个浮点值，作为mipmap细节层参数的偏移值使用；
    //如果target是GL_TEXTURE_ENV，并且pname是GL_TEXTURE_ENV_MODE，param必须是GL_DECAL,,GL_MODULATE,GL_BLEND,GL_ADD或GL_COMBINE之一,它们表示纹理值应该如何与被处理的片段颜色值进行组合,如果pname是GL_TEXTURE_ENV_COLOR，那么param就是包含了4个浮点值（RGBA）的数组
    //如果target是GL_POINT_SPRITE，并且pname是GL_COORD_REPLACE,那么param设置为GL_TRUE可以启用围绕一个点块纹理的坐标进行迭代
}

if // 分配纹理坐标 glTexCoord2f(), glTexParameter()
{
    // https://blog.csdn.net/biggbang/article/details/20136219

    glTexCoord2f();
    // 原型为
    glTexCoord2f(GLfloat s, GLfloat t);

    // 第一个参数是X坐标，0 .0是纹理的左侧，0.5是纹理的中点，1.0是纹理的右侧。
    // 第二个参数是Y坐标，0 .0是纹理的底部，0.5是纹理的中点，1.0是纹理的顶部。

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(2.41421, 1.0, -1.41421);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(2.41421, -1.0, -1.41421);
    void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    //设置当前的纹理坐标，接下来对glVertex*f()的调用将导致当前纹理坐标被分配给这个函数所指定的顶点
    //t、r默认为0，q默认为1；

    void glTexParameteri(GLenum target, GLenum pname, GLint param);
    //设置不同的参数，当纹理应用于片段或存储于纹理对象时控制它的处理方式；
    //target参数可以是GL_TEXTURE_*D或GL_TEXTURE_CUBE_MAP。
    //pname和param可以取的值见图
}

if // 紅條茶壺.cc // 纹理坐标的自动生成 glTexGen()
{
    // 用于自动生成纹理坐标的函数：
    void glTexGeni(GLenum coord, GLenum pname, GLint param);
    //参数coord必须是GL_S、GL_T、GL_R或GL_Q
    //pname参数为GL_TEXTURE_GEN_MODE、GL_OBJECT_PLANE或GL_EYE_PLANE,
    //如果是GL_TEXTURE_GEN_MODE,param就是个整数，即GL_OBJECT_PLANE,GL_EYE_PLANE,GL_SPHERE_MAP,GL_REFLECTION,GL_NORMAL_MAP之一；
    //如果pname取其他可能的值，param就是指向数组的指针
}

if // 多重纹理 glActiveTexture(), glMultiTexCoord2f(), glClientActiveTexture()
{
    // 1.建设纹理单位
    // 纹理单位的纹理状态：纹理图像，过滤参数，纹理环境应用，纹理坐标的自动生成，顶点数组的指定。
    void glActiveTexture(GLenum texUnit);
    //选择可以由纹理函数进行修改的当前纹理单位，
    //texUnit是一个符号常量，其形式为GL_TEXTUREi，其中i的范围是从0到k-1，k是纹理单位的最大数量

    // 2.指定顶点以及他们的纹理坐标
    void glMultiTexCoord2f(GLenum texUnit, const TYPE *coords);
    //将参数coords中的纹理坐标数据（s,t,r,q）用于纹理单位texUnit。texUnit参数所使用的枚举值与glActiveTexture()函数相同

    // 3.指定纹理坐标的其他办法
    glClientActiveTexture(GLenum texUnit);
    //选择当前的纹理单位，以便用顶点数组指定纹理坐标数据，texUnit与glActiveTexture()参数相同
}

if // 在纹理之后应用辅助颜色 glSecondaryColor()
{
    // 如果没有启用光照，并且启用了颜色求和模式（glEnable(GL_COLOR_SUM) ），那么当前的辅助颜色便添加到经过纹理的片段颜色上
    glSecondaryColor3b(Type r, Type g, Type b);
    //设置当前辅助颜色的红绿蓝成分
}

if // 点块纹理 纹理矩阵堆栈 q坐标
{
    // https://blog.csdn.net/biggbang/article/details/20281409
    // 1.点块纹理和抗锯齿点的区别：

    // 2.启用点块纹理：
    glEnable(GL_POINT_SPRITE);

    // 對角反轉 // 3.设置点块纹理的原点（决定t纹理坐标的值）：
    glPointparameter(GL_POINT_SPRITE_COORD_ORIGIN, GL_LOWER_LEFT或GL_UPPER_LEFT);

    // 4.纹理矩阵堆栈
    // 为了更改当前的纹理矩阵，需要把矩阵模式设为GL_TEXTURE，即glMatrixMode(GL_TEXTURE);

    // 5.q坐标：
    // 如果需要多个投影和透视变换，可能就要用到q坐标
}

if // 深度纹理
{
    // 1.从光源的角度对场景进行渲染。场景看上去是什么样子无关紧要，只需要深度值，然后创建阴影图，也就是捕捉深度缓冲区的值，
    // 并把他们存储在一个纹理图像（即阴影图）中
    // 2.生成纹理坐标，其中（s, t）坐标引用阴影图中的位置，第三个纹理坐标r则表示与光源的距离，
    // 然后再次绘制场景，把每个片段的r值与深度纹理值进行比较，以确定这个片段是被光所照射还是被阴影笼罩
}

if // 缓冲区及其用途 glDrawBuffer(), glReadBuffer(), glColorMask(), glClearBuffer()
{
    // https://blog.csdn.net/biggbang/article/details/20357137
    // 查询特定的画面可以使用的基于像素的缓冲区存储信息：调用glGetIntegerv()函数

    // 1.颜色缓冲区
    // 可以在glGetBooleanv()函数中使用GL_STEREO或GL_DOUBLEBUFFER参数来判断自己的系统是否支持立体画面（即提供左右缓冲区）或双缓冲（即提供了前后缓冲区）。
    // 为了判断系统支持多少辅助缓冲区，可以用GL_AUX_BUFFERS为参数调用glGetIntegerv()函数。

    // 2.清除缓冲区
    // 选择清除值：
    // 分别是颜色缓冲区，颜色索引模式下的颜色缓冲区，深度缓冲区，模板缓冲区和累积缓冲区的当前清除值

    // 清除指定的缓冲区：
    void glClear(GLbitfield mask);

    glClearBufferfi(GLenum buffer, GLint drawbuffer, const TYPE *value);
    //将由drawbuffer索引的与buffer相关的缓冲区清除为value。buffer必须是GL_COLOR,GL_DEPTH或GL_STENCIL之一。

    // 3.选择用于读取和写入的颜色缓冲区
    // 写入颜色缓冲区：
    void glDrawBuffer(GLenum mode);
    //mode参数见下表

    void glDrawBuffers(GLsizei n, const GLenum *buffers);
    //指定用于接收颜色值的多个缓冲区，buffers是缓冲区枚举型的数组

    // 选择颜色缓冲区：
    void glReadBuffer(GLenum mode);
    //mode参数与glDrawBuffer相同

    // 4.缓冲区的屏蔽
    // 在OpenGL把数据写入到已启用的缓冲区之前，它首先会对数据执行屏蔽操作。
    // 设置掩码，为1就写入，为0就不写入
}

if // 裁剪测试 alpha测试 glScissor(), glAlphaFunc()
{
    // https://blog.csdn.net/biggbang/article/details/20359931
    // 裁剪测试：

    void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
    //设置裁剪矩形的位置和大小

    // alpha测试：
    // 判断alpha测试是否可用 :

    glIsEnabled(GL_ALPHA_TEST);
    // 设置用于alpha测试的参考值和比较函数：
    void glAlphaFunc(GLenum func, GLclampf ref);
    //参考值ref的范围被限定在0-1之间,func可能使用的值见表
}

if // 模板测试 glStencilFunc(), glStencilOp()
{
    // https://blog.csdn.net/biggbang/article/details/20361465
    // 启用模板测试：

    // glEnable(GL_STENCIL_TEST);

    // 设置模板测试所使用的比较函数(func)，参考值(ref)和掩码(mask):

    glStencilFunc(GL_EQUAL, 0x1, 0x1);
    void glStencilFunc(GLenum func, GLint ref, GLuint mask);
    //默认情况下，func是GL_ALWAYS，ref是0，mask是全1，模板测试被禁用

    // 指定了当一个片段通过或未通过模板测试是，模板缓冲区中的数据如何进行修改:
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    //如果片段无法通过测试，fail函数就会被调用；如果通过测试，在深度测试失败的情况下应用zfail函数；
    //在所有都通过或者未执行深度测试的情况下调用zpass函数

    // 可以使用查询函数glGetInteger(), 获取全部6个模板相关的参数值：
}

if // 深度测试 遮挡查询 glDepthFunc(), glGenQueries(), glBeginQuery(), glGetQueryObjectiv()
{
    // 1.为深度测试设置比较函数：
    glDepthFunc(GLenum func);
    //func默认为GL_LESS

    // 2.遮挡查询
    // 生成一组未使用的查询ID:
    glGenQueries(GLsizei n, GLuint * ids);
    //返回n个当前未使用的ID，可用于表示遮挡对象的名称。这些名称是在ids数组中返回的。

    // 判断一个标识符当前是否被一个遮挡查询对象所使用：
    GLboolean glIsQuery(GLuint id);

    // 指定一次遮挡查询操作的开始：
    glBeginQuery(GLenum target, GLuint id);
    //target必须是GL_SAMPLES_PASSED,id是一个查询对象名称

    // 结束一次查询操作：
    glEndQuery(GLenum target);
    //target必须是GL_SAMPLES_PASSED

    // 判断指定查询的结果：
    glGetQueryObjectiv(GLenum id, GLenum pname, GLenum * params);
    //id是一个查询对象名称,如果pname是GL_QUERY_RESULT,params将包含通过深度测试的片段的数量
    //如果数量为0，表示此对象完全被遮挡

    // 清除遮挡查询对象：
    glDeleteQueries(GLsizei n, GLuint * ids);
    //参数同glGenQueries()
}

if // 累积缓冲区 glAccum()
{
    // 控制累计缓冲区：
    void glAccum(GLenum op, GLfloat value);
    //控制累积缓冲区，op参数选择操作，value是该操作的使用数量。
    //可以使用的操作有：GL_ACCUM、GL_LOAD、GL_RETURN、GL_ADD和GL_MULT。

    // 运动模糊：
    glAccum(GL_MULT, 0 ~1);
    //第二个参数越小，运动速度越快，越模糊
    glAccum(GL_RETURN, 1.0);
    //将完成后的图像从累积缓冲区转移到标准的颜色缓冲区
}

if // 多边形分格化 gluNewTess(), gluTessCallback(), gluTessProperty(), gluTessBeginPolygon()
{
    // https://blog.csdn.net/biggbang/article/details/20544945

    GLUtesselator *gluNewTess(void);
    //创建一个新的分割化对象，并返回一个指向他的指针，如果创建失败，返回NULL

    void gluTessCallback(GLUtesselator * tess, GLenum which, void(CALLBACK * fn)());
    //把回调函数fn与分格化对象tess相关联。回调函数的类型是由which决定的，which的原型见下图

    gluTessProperty(tobj, GLU_TESS_WINDING_RULE, GLU_TESS_WINDING_POSITIVE);
    void gluTessProperty(GLUtesselator * tess, GLenum which, GLdouble value);
    //对于分格化对象tess，which的当前值被设置为value。
    //如果which是GLU_TESS_WINDING_RULE，他决定了多边形哪部分位于外部，哪部分位于内部，value可以是GLU_TESS_WINDING_ADD(默认)、GLU_TESS_WINDING_POSITIVE等

    void gluTessNormal(GLUtesselator * tess, GLdouble x, GLdouble y, GLdouble z);
    //对于分格化对象tess，此函数定义了一条法线向量，用于控制生成多边形的环绕方向。

    gluTessBeginPolygon(tobj, NULL);
    void gluTessBeginPolygon(GLUtesselator * tess, void *polygon_data);
    void gluTessEndPolygon(GLUtesselator * tess);
    //开始和结束对需要进行分格化的多边形的指定，并把分格化对象tess与它相关联。polygon_data指向一个用户定义的数据结构，传递给所有在GLU_YESS_*_DATA回调函数中注册的函数。

    gluTessBeginContour(GLUtesselator * tess);
    gluTessEndContour(GLUtesselator * tess);
    //开始和结束一条轮廓线的指定，这条轮廓线是一个多边形的一部分，闭合的轮廓线是通过零次或多次调用gluTessVertex()形成的，每条轮廓线的最后一个顶点会连接到第一个顶点

    gluTessVertex(tobj, star[ 4 ], star[ 4 ]);
    void gluTessVertex(GLUtesselator * tess, GLdouble coords[ 3 ], void *data);
    //在实际使用中，指定分格化对象的当前轮廓线的一个顶点。coords包含了三维顶点坐标，data是个指针，它发送到与GLU_TESS_VERTEX或GLU_TESS_VERTEX_DATA相关联的回调函数。

    gluDeleteTess(GLUtesselator * tess);
    //删除分格化对象
}

if // 管理二次方程对象 gluNewQuadric(), gluDeleteQuadric(), gluQuadricCallback()
{
    GLUquadric *gluNewQuadric(void);
    //创建一个新的二次方程对象，并返回一个指向他的指针
    void gluDeleteQuadric(GLUquadric * state);
    //销毁二次方程对象，释放内存
    void APIENTRY gluQuadricCallback(GLUquadric * qobj, GLenum which, void(CALLBACK * fn)());
    //定义一个函数fn，以便在特定情况下调用。
}

if // 控制二次方程对象的属性 gluQuadricDrawStyle(), gluQuadricOrientation(), gluQuadricNormals(), gluQu()
{
    // 控制绘图风格：
    gluQuadricDrawStyle(qobj, GLU_FILL);

    // 控制法线向量的方向：
    gluQuadricOrientation(GLUquadric * quadObject, GLenum orientation);

    // 指定合适生成法线向量：
    gluQuadricNormals(qobj, GLU_NONE);

    // 为二次方程表面生成纹理坐标：
    gluQuadricTexture(GLUquadric * quadObject, GLboolean textureCoords)
}

if // 二次方程图元 gluSphere(), gluCylinder(), gluDisk(), gluPartialDisk()
{
    gluSphere(qobj, 0.75, 15, 10);
    void gluSphere(GLUquadric * qobj, GLdouble radius, GLint slices, GLint stacks);
    //绘制一个半径为radius的球体，圆心（0,0,0），经线slices，纬线stacks。
    gluCylinder(qobj, 0.5, 0.3, 1.0, 15, 5);
    void gluCylinder(GLUquadric * qobj, GLdouble, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
    //绘制一个沿z轴的圆柱体，底面位于z=0平面，顶面位于z=height的平面。baseRadius是z=0半径，topRadius是z=height半径

    gluDisk(qobj, 0.25, 1.0, 20, 4);
    void gluDisk(GLUquadric * qobj, GLdouble innerRadius, GLdouble, GLint slices, GLint loops);
    //绘制一个位于z=0处的圆盘，innerRadius是内半径，outerRadius是外半径，loops是几个同心圆

    gluPartialDisk(qobj, 0.0, 1.0, 20, 4, 0.0, 225.0);
    void gluPartialDisk(GLUquadric * qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops, GLdouble startAngle, GLdouble sweepAngle);
    //绘制一个位于z=0处的不完整的圆盘，从startAngle开始，共绘制startAngle+sweepAngle度的圆盘
}

if // glMap1f(), glEvalCoord1f(), glMapGrid1d(), glEvalMesh1()
{
    // 定义一维求值器：
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[ 0 ][ 0 ]);
    void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
    //target参数指定了控制点表示什么。如表所示，并因此确定了points应该提供多少值
    //u1和u2参数表示变量u的变化范围，变量stride是每个存储块之间单精度或双精度浮点数的数量
    //order参数的值就是stride+1,它应该与控制点的数量一致
    //points参数指向第一个控制点的第一个坐标

    glEnable(GL_MAP1_VERTEX_3);
    //启用求值器

    // 使已启用的一维求职器执行计算：
    glEvalCoord1f((GLfloat) i / 30.0);
    void glEvalCoord1f(GLfloat u);
    //参数u是定义域坐标的值

    // 定义均匀分布的一维坐标值：
    void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
    //定义一个均匀分布的u1到u2的网格，中间有un个阶段

    void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
    //对所有已启用的求职器应用当前定义的一维网格。
    //mode参数可以是GL_POINT、GL_LINE。
    //这个函数相当于为从i1到i2的每一步调用glMapGrid1d函数，其中0<i1,i2<n;
}

if // GLU的NURBS的接口 gluNewNurbsRenderer(), gluNurbsProperty(), gluNurbsSurface(), gluNurbsCal()
{
    // 创建一个NURBS对象:
    GLUnurbs *gluNewNurbsRenderer(void);
    //创建一个NURBS对象nobj,并返回一个指向这个新对象的指针

    // 销毁NURBS对象：
    void gluDeleteNurbsRenderer(GLUnurbs * nobj);
    // 控制NURBS对象的属性：

    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0); //控制分格化的顶点简单的进行渲染
    gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);   //把表面渲染为多边形
    void gluNurbsProperty(GLUnurbs * nobj, GLenum property, GLfloat value);
    //控制NURBS对象的属性，property指定了属性，他可以是GLU_DISPLAY_MODE或GLU_SAMPLING_TOLERANCE，value表示这个属性应该是什么值

    // 返回NURBS对象nobj的property属性的当前值：
    gluGetNurbsProperty(GLUnurbs * nobj, GLenum property, GLfloat * value);
    //返回NURBS对象nobj的property属性的当前值，返回值放在value数组中

    // 创建NURBS的曲面或表面：
    gluBeginSurface(theNurb);
    gluNurbsSurface(theNurb, 8, knots, 8, knots, 4 * 3, 3,
                    &ctlpoints[ 0 ][ 0 ][ 0 ], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(theNurb);

    void gluNurbsSurface(
        GLUnurbs * nobj,
        GLint sknot_count, //节点数量
        float *sknot,      //节点序列
        GLint tknot_count, //节点数量
        GLfloat *tknot,    //节点序列
        GLint s_stride,    //每个参数化方向上控制点之间的浮点值的数量
        GLint t_stride,
        GLfloat *ctlarray, //指向包含了控制点的数组
        GLint sorder,      //表面多项式的阶数
        GLint torder,      //表面多项式的阶数
        GLenum type);      //表示二维求值器类型
}

if // 选择 glSelectBuffer(), glRenderMode(), glInitNames(), glPushName()
{
    // 指定用于返回点击选择数据的数组：
    const int BUFSIZE = 512;
    GLuint selectBuf[ BUFSIZE ];
    glSelectBuffer(BUFSIZE, selectBuf);
    void glSelectBuffer(GLsizei size, GLuint * buffer);
    //buffer参数是一个无符号整数类型的数组指针。它所指向的数组用于存放选择数据
    //size表示这个数组可以存储的值的最大数量

    GLint glRenderMode(GLenum mode);
    //控制应用程序是处于渲染模式、选择模式还是反馈模式

    // 创建名字栈：
    (void) glRenderMode(GL_SELECT);
    GLint glRenderMode(GLenum mode);
    //控制应用程序是处于渲染模式、选择模式还是反馈模式

    glInitNames();
    void glInitNames();
    //清除名字堆栈，使他成为空栈。

    glPushName(0);
    void glPushName(GLuint name);
    //把name压缩到堆栈中

    glPopName();
    //从名字堆栈中弹出一个名称

    glLoadName(1);
    void glLoadName(GLuint name);
    //用name替换名字堆栈顶部的那个值
}

if // 反馈 glFeedbackBuffer(), glPassThrough()
{
    // 建立一个用于保存反馈数据的缓冲区：
    glFeedbackBuffer(1024, GL_3D_COLOR, feedBuffer);
    void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer);
    //buffer是一个数组指针，指向包含反馈数据的数组。size是这个数组可以存储的值的最大数量
    //type描述了反馈数组中每个顶点的反馈信息，见表

    // 在反馈模式下使用标记：
    glPassThrough(1.0);
    void glPassThrough(GLfloat token);
    //如果在反馈模式下调用这个函数，他会在反馈数组的数据流中插入一个过渡标记
    //标记由GL_PASS_THROUGH_TOKEN和浮点值token组成
}

if // glCreateShader();
{
    glCreateShader(GL_VERTEX_SHADER);
    // GL_VERTEX_SHADER is a shader that is intended to run on the programmable vertex processor
    // GL_VERTEX_SHADER類型的著色器是一個用於在可編程頂點處理器上運行的著色器

    glCreateShader(GL_FRAGMENT_SHADER);
    // GL_FRAGMENT_SHADER is a shader that is intended to run on the programmable fragment processor.
    // GL_FRAGMENT_SHADER 類型的著色器是一個著色器，旨在在可編程片段處理器上運行
}