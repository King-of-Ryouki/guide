if // 顯示圖形
{
    void init() {
        glClearColor(0, 0, 0, 0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    }

    void Display() {
        glPushMatrix();

        glBegin(GL_TRIANGLES);       // 開始劃三角形
        glColor3f(1.0f, 0.0f, 0.0f); // 設定輸出色為紅色
        glVertex2f(0.0f, 1.0f);      // (x1,y1)=(0, 1)

        glColor3f(0.0f, 1.0f, 0.0f); // 設定輸出色為綠色
        glVertex2f(0.87f, -0.5f);    // (x2,y2)=(0.87,-0.5)

        glColor3f(0.0f, 0.0f, 1.0f); // 設定輸出色為藍色
        glVertex2f(-0.87f, -0.5f);   // (x3,y3)=(-0.87,-0.5)

        glEnd(); // 結束劃三角形
        glPopMatrix();

        glutSwapBuffers();
    }

    void DDisplay() {
        glColor3f(1, 0, 1);

        glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0);
        glVertex3f(0.75, 0.25, 0);
        glVertex3f(0.75, 0.75, 0);
        glVertex3f(0.25, 0.75, 0);

        glEnd();
        glFlush();
    }

    int main() {
        glutInit();                       // 初始化
        glutInitWindowPosition(100, 100); // 設定視窗位置
        glutInitWindowSize(400, 400);     // 設定視窗大小
        glutCreateWindow("hello");        // 設定視窗標題 //创建一个支持OpenGL渲染环境的窗口
        init();                           // 设置背景颜色和坐标系统

        // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
        // glutDisplayFunc(Display);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutDisplayFunc(DDisplay); // prototype == GLUTAPI void APIENTRY glutDisplayFunc(void (GLUTCALLBACK *func)(void));

        glClearColor(255, 0, 0, 0);   // 设置清除颜色
        glClear(GL_COLOR_BUFFER_BIT); // 把窗口清除为当前颜色
        glutMainLoop();               // 顯示程式視窗

        system("pause");
        return 0;
    }
}

else if // 创建机器人手臂源码讲解
{
    // #include <GL/glut.h>
    // #include <stdlib.h>

    static int shoulder = 0, elbow = 0;

    void init(void) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_FLAT);
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);                 //转移局部坐标系中心-1
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0); //绕局部坐标系原点旋转
        glTranslatef(1.0, 0.0, 0.0);                  //把局部坐标系转回立方体中心
        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1.0, 0.0, 0.0);               //转移局部坐标系到第一个立方体的右侧
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0); //绕局部坐标系旋转
        glTranslatef(1.0, 0.0, 0.0);               //转移到第二个立方体中心
        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
        glPopMatrix();

        glPopMatrix();
        glutSwapBuffers();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -5.0);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 's':
                shoulder = (shoulder + 5) % 360;
                glutPostRedisplay();
                break;
            case 'S':
                shoulder = (shoulder - 5) % 360;
                glutPostRedisplay();
                break;
            case 'e':
                elbow = (elbow + 5) % 360;
                glutPostRedisplay();
                break;
            case 'E':
                elbow = (elbow - 5) % 360;
                glutPostRedisplay();
                break;
            case 27:
                exit(0);
                break;
            default:
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
}

else if // 控制光源的位置和方向
{
    // 使光源保持静止
    // 在使用完视图和模型变换之前设置光源的位置，init()的后面， display()之前

    // 独立的移动光源
    // 在模型变换之后设置光源位置

    // #include <GL/glut.h>
    // #include <stdlib.h>

    static int spin = 0;

    void init(void) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }

    void display(void) {
        GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix(); //用于隔离视图变换和模型变换
        gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        glPushMatrix();                            //用于隔离视图变换和模型变换
        glRotated((GLdouble) spin, 1.0, 0.0, 0.0); //旋转光源
        glLightfv(GL_LIGHT0, GL_POSITION, position);

        glTranslated(0.0, 0.0, 1.5);
        glDisable(GL_LIGHTING);
        glColor3f(0.0, 1.0, 1.0);
        glutWireCube(0.1);
        glEnable(GL_LIGHTING);
        glPopMatrix(); //局部坐标系归位
        glutSolidTorus(0.25, 0.85, 8, 15);
        glPopMatrix();
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void mouse(int button, int state, int x, int y) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN) {
                    spin = (spin + 30) % 360;
                    glutPostRedisplay();
                }
                break;
            default:
                break;
        }
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
}

else if // ring.cc 显示列表实例 glCallList(), glGenLists(), glNewList(), glEndList()
{
    // #include <GL/glut.h>
    // #include <stdio.h>
    // #include <math.h>
    // #include <stdlib.h>

    // #define PI_ 3.14159265358979323846

    GLuint theTorus;

    /* Draw a torus */
    static void torus(int numc, int numt) //显示列表只能包含OpenGL函数
    {
        int i, j, k;
        double s, t, x, y, z, twopi;

        twopi = 2 * PI_;
        for (i = 0; i < numc; i++) {
            glBegin(GL_QUAD_STRIP);
            for (j = 0; j <= numt; j++) {
                for (k = 1; k >= 0; k--) {
                    s = (i + k) % numc + 0.5;
                    t = j % numt;

                    x = (1 + .1 * cos(s * twopi / numc)) * cos(t * twopi / numt);
                    y = (1 + .1 * cos(s * twopi / numc)) * sin(t * twopi / numt);
                    z = .1 * sin(s * twopi / numc);
                    glVertex3f(x, y, z);
                }
            }
            glEnd();
        }
    }

    /* Create display list with Torus and initialize state */
    static void init(void) //创建了一个绘制圆环面的显示列表
    {
        theTorus = glGenLists(1);        //glGenLists()唯一的标识一个显示列表
        glNewList(theTorus, GL_COMPILE); //用于对显示列表进行定界。第一个参数是一个整形索引值，由glGenLists()指定
        torus(8, 25);
        glEndList();

        glShadeModel(GL_FLAT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
    }

    /* Clear window and draw torus */
    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glCallList(theTorus); //执行显示列表所存储的函数
        glFlush();
    }

    /* Handle window resize */
    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(30, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    }

    /* Rotate about x-axis when "x" typed; rotate about y-axis
   when "y" typed; "i" returns torus to original view */
    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 'x':
            case 'X':
                glRotatef(30., 1.0, 0.0, 0.0);
                glutPostRedisplay(); //使glutMainLoop()函数调用display()函数
                break;
            case 'y':
            case 'Y':
                glRotatef(30., 0.0, 1.0, 0.0);
                glutPostRedisplay();
                break;
            case 'i':
            case 'I':
                glLoadIdentity(); //恢复初始模型矩阵
                gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
                glutPostRedisplay();
                break;
            case 27:
                exit(0);
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInitWindowSize(200, 200);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
    }
}

else if // word.cc // 执行多个显示列表 glListBase(), glCallLists()
{
    // #include <GL/glut.h>
    // #include <stdlib.h>
    // #include <string.h>

    // #define PT 1
    // #define STROKE 2
    // #define END 3

    typedef struct charpoint
    {
        GLfloat x, y;
        int type;
    } CP;

    CP Adata[] = {
        { 0, 0, PT }, { 0, 9, PT }, { 1, 10, PT }, { 4, 10, PT }, { 5, 9, PT }, { 5, 0, STROKE }, { 0, 5, PT }, { 5, 5, END }
    };

    CP Edata[] = {
        { 5, 0, PT }, { 0, 0, PT }, { 0, 10, PT }, { 5, 10, STROKE }, { 0, 5, PT }, { 4, 5, END }
    };

    CP Pdata[] = {
        { 0, 0, PT }, { 0, 10, PT }, { 4, 10, PT }, { 5, 9, PT }, { 5, 6, PT }, { 4, 5, PT }, { 0, 5, END }
    };

    CP Rdata[] = {
        { 0, 0, PT }, { 0, 10, PT }, { 4, 10, PT }, { 5, 9, PT }, { 5, 6, PT }, { 4, 5, PT }, { 0, 5, STROKE }, { 3, 5, PT }, { 5, 0, END }
    };

    CP Sdata[] = {
        { 0, 1, PT }, { 1, 0, PT }, { 4, 0, PT }, { 5, 1, PT }, { 5, 4, PT }, { 4, 5, PT }, { 1, 5, PT }, { 0, 6, PT }, { 0, 9, PT }, { 1, 10, PT }, { 4, 10, PT }, { 5, 9, END }
    };

    /*  drawLetter() interprets the instructions from the array
 *  for that letter and renders the letter with line segments.
 */
    static void drawLetter(CP * l) {
        glBegin(GL_LINE_STRIP);
        while (1) {
            switch (l->type) {
                case PT:
                    glVertex2fv(&l->x);
                    break;
                case STROKE:
                    glVertex2fv(&l->x);
                    glEnd();
                    glBegin(GL_LINE_STRIP);
                    break;
                case END:
                    glVertex2fv(&l->x);
                    glEnd();
                    glTranslatef(8.0, 0.0, 0.0);
                    return;
            }
            l++;
        }
    }

    /*  Create a display list for each of 6 characters	*/
    static void init(void) {
        GLuint base;

        glShadeModel(GL_FLAT);

        base = glGenLists(128);
        glListBase(base); //指定一个偏移量，它将与glCallListserv()函数中的
        //显示列表索引相加，以获取最终的显示列表索引
        glNewList(base + 'A', GL_COMPILE);
        drawLetter(Adata);
        glEndList();
        glNewList(base + 'E', GL_COMPILE);
        drawLetter(Edata);
        glEndList();
        glNewList(base + 'P', GL_COMPILE);
        drawLetter(Pdata);
        glEndList();
        glNewList(base + 'R', GL_COMPILE);
        drawLetter(Rdata);
        glEndList();
        glNewList(base + 'S', GL_COMPILE);
        drawLetter(Sdata);
        glEndList();
        glNewList(base + ' ', GL_COMPILE);
        glTranslatef(8.0, 0.0, 0.0);
        glEndList();
    }

    char *test1 = "A SPARE SERAPE APPEARS AS";
    char *test2 = "APES PREPARE RARE PEPPERS";

    static void printStrokedString(char *s) {
        GLsizei len = strlen(s);
        glCallLists(len, GL_BYTE, (GLbyte *) s);
        //执行len个显示列表，被执行的显示列表的索引是通过把当前显示列表基址表示的偏移值（由glListBase()指定）
        //与s指向的数组中的有符号整型值相加得到的
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glScalef(2.0, 2.0, 2.0);
        glTranslatef(10.0, 30.0, 0.0);
        printStrokedString(test1);
        glPopMatrix();
        glPushMatrix();
        glScalef(2.0, 2.0, 2.0);
        glTranslatef(10.0, 13.0, 0.0);
        printStrokedString(test2);
        glPopMatrix();
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case ' ':
                glutPostRedisplay();
                break;
            case 27:
                exit(0);
        }
    }

    /*  Main Loop
     *  Open window with initial window size, title bar,
     *  RGBA display mode, and handle input events.
     */
    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(440, 120);
        glutCreateWindow("stroke");
        init();
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
    }
}

else if // word FFF.cc // 位图与字体 glRasterPos(), glWindowPos(), glBitmap()
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

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // #include <GL/glut.h>
    // #include <stdlib.h>

    GLubyte rasters[ 24 ] = {
        0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
        0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
        0xff, 0xc0, 0xff, 0xc0
    };

    void init(void) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glClearColor(0.0, 0.0, 0.0, 0.0);
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(20, 20); //确定当前光栅位置，x,y,z,w指定了当前光栅位置的坐标
        glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
        glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
        glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
        //绘制由bitmap指定的位图，bitmap是一个指向位图图像的指针，位图的原点是当前光栅位置，如果当前光栅位置无效，则这个函数不会绘制任何东西。
        //width和height表示位图的宽度和高度，xorig和yorig定义了位图的原点，他是根据当期光栅位置确定的，右上为正。
        //xmove和ymove表示位图光栅化之后光栅坐标的x增加值和y增加值
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, w, 0, h, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
        }
    }

    /*  Main Loop
 *  Open window with initial window size, title bar,
 *  RGBA display mode, and handle input events.
 */
    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(100, 100);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
    }
}

else if // word2.cc// 定义和使用一种完整的字体
{
    // #include <GL/glut.h>
    // #include <stdlib.h>
    // #include <string.h>

    GLubyte space[] =
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    GLubyte letters[][ 13 ] = {
        { 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18 },
        { 0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe },
        { 0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e },
        { 0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc },
        { 0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff },
        { 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff },
        { 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e },
        { 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3 },
        { 0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e },
        { 0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06 },
        { 0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3 },
        { 0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0 },
        { 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3 },
        { 0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3 },
        { 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e },
        { 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe },
        { 0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c },
        { 0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe },
        { 0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e },
        { 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff },
        { 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3 },
        { 0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3 },
        { 0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3 },
        { 0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3 },
        { 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3 },
        { 0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff }
    };

    GLuint fontOffset;

    void makeRasterFont(void) //定义一个完整的字体的显示列表
    {
        GLuint i, j;
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        fontOffset = glGenLists(128);
        for (i = 0, j = 'A'; i < 26; i++, j++) {
            glNewList(fontOffset + j, GL_COMPILE);
            glBitmap(8, 13, 0.0, 2.0, 10, 0.0, letters[ i ]);
            glEndList();
        }
        glNewList(fontOffset + ' ', GL_COMPILE);
        glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
        glEndList();
    }

    void init(void) {
        glShadeModel(GL_FLAT);
        makeRasterFont();
    }

    void printString(char *s) //使用完整的字体
    {
        glPushAttrib(GL_LIST_BIT);
        glListBase(fontOffset);
        glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
        glPopAttrib();
    }

    // Everything above this line could be in a library
    // that defines a font.  To make it work, you've got
    // to call makeRasterFont() before you start making
    // calls to printString().

    void display(void) {
        GLfloat white[ 3 ] = { 1.0, 1.0, 1.0 };

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3fv(white);

        glRasterPos2i(20, 60);
        printString("THE QUICK BROWN FOX JUMPS"); //使用字体显示列表
        glRasterPos2i(20, 40);
        printString("OVER A LAZY DOG");
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
        }
    }

    // Main Loop
    // Open window with initial window size, title bar,
    // RGBA display mode, and handle input events.

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(300, 100);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
    }
}

else if // chessboard.cc // 纹理贴图的步骤
{
    // 纹理贴图的步骤
    // 1.创建纹理对象，并为它指定一个纹理
    // 2.确定纹理如何应用到每个像素上
    // 3.启用纹理贴图功能
    // 4.绘制场景，提供纹理坐标和几何图形坐标

// #include <GL/glut.h>
// #include <stdlib.h>
// #include <stdio.h>

/*	Create checkerboard texture	*/
#define checkImageWidth 64
#define checkImageHeight 64
    static GLubyte checkImage[ checkImageHeight ][ checkImageWidth ][ 4 ];
#ifdef GL_VERSION_1_1
    static GLuint texName;
#endif
    void makeCheckImage(void) //生成棋盘纹理
    {
        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c                         = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
                checkImage[ i ][ j ][ 0 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 1 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 2 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 3 ] = (GLubyte) 255;
            }
        }
    }

    void init(void) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_FLAT);
        glEnable(GL_DEPTH_TEST);

        makeCheckImage();
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
        glGenTextures(1, &texName);            //命名纹理图像(第一步)
        glBindTexture(GL_TEXTURE_2D, texName); //创建纹理对象(第一步)
#endif
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //指定这个纹理对象的包装形式，并指定纹理的颜色应该如何进行过滤(第一步)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#ifdef GL_VERSION_1_1
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, //指定一个纹理 (第一步)
                     0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#else
        glTexImage2D(GL_TEXTURE_2D, 0, 4, checkImageWidth, checkImageHeight,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#endif
    }
    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);                                  //启用纹理功能(第三步)
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //设置绘图模式(第二步)
#ifdef GL_VERSION_1_1
        glBindTexture(GL_TEXTURE_2D, texName);
#endif
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); //设置当前纹理坐标(第四步)
        glVertex3f(-2.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-2.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(2.41421, 1.0, -1.41421);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(2.41421, -1.0, -1.41421);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 30.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -3.6);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
                break;
            default:
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(250, 250);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
}

else if // red_chessboard.cc // 纹理对象 glGenTextures(), glIsTexture(), glBindTexture(), glDeleteTextures()
{
    // #include <GL/glut.h>
    // #include <stdlib.h>
    // #include <stdio.h>

#ifdef GL_VERSION_1_1
/*	Create checkerboard texture	*/
#    define checkImageWidth 64
#    define checkImageHeight 64
    static GLubyte checkImage[ checkImageHeight ][ checkImageWidth ][ 4 ];
    static GLubyte otherImage[ checkImageHeight ][ checkImageWidth ][ 4 ];

    static GLuint texName[ 2 ];

    void makeCheckImages(void) {
        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c                         = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
                checkImage[ i ][ j ][ 0 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 1 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 2 ] = (GLubyte) c;
                checkImage[ i ][ j ][ 3 ] = (GLubyte) 255;
                c                         = ((((i & 0x10) == 0) ^ ((j & 0x10)) == 0)) * 255;
                otherImage[ i ][ j ][ 0 ] = (GLubyte) c;
                otherImage[ i ][ j ][ 1 ] = (GLubyte) 0;
                otherImage[ i ][ j ][ 2 ] = (GLubyte) 0;
                otherImage[ i ][ j ][ 3 ] = (GLubyte) 255;
            }
        }
    }

    void init(void) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_FLAT);
        glEnable(GL_DEPTH_TEST);

        makeCheckImages();
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glGenTextures(2, texName);
        glBindTexture(GL_TEXTURE_2D, texName[ 0 ]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                     checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                     checkImage);

        glBindTexture(GL_TEXTURE_2D, texName[ 1 ]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                     checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                     otherImage);

        glEnable(GL_TEXTURE_2D);
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, texName[ 0 ]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-2.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-2.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, texName[ 1 ]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(2.41421, 1.0, -1.41421);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(2.41421, -1.0, -1.41421);
        glEnd();
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 30.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -3.6);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(250, 250);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
#else
    int main(int argc, char **argv) {
        fprintf(stderr, "This program demonstrates a feature which is not in OpenGL Version 1.0.\n");
        fprintf(stderr, "If your implementation of OpenGL Version 1.0 has the right extensions,\n");
        fprintf(stderr, "you may be able to modify this program to make it run.\n");
        return 0;
    }
#endif
}

else if // 紅條茶壺.cc // 纹理坐标的自动生成 glTexGen()
{
    // #include <GL/glut.h>
    // #include <stdlib.h>
    // #include <stdio.h>

#define stripeImageWidth 32
    GLubyte stripeImage[ 4 * stripeImageWidth ];

#ifdef GL_VERSION_1_1
    static GLuint texName;
#endif

    void makeStripeImage(void) {
        int j;

        for (j = 0; j < stripeImageWidth; j++) {
            stripeImage[ 4 * j ]     = (GLubyte)((j <= 4) ? 255 : 0);
            stripeImage[ 4 * j + 1 ] = (GLubyte)((j > 4) ? 255 : 0);
            stripeImage[ 4 * j + 2 ] = (GLubyte) 0;
            stripeImage[ 4 * j + 3 ] = (GLubyte) 255;
        }
    }

    /*  planes for texture coordinate generation  */
    static GLfloat xequalzero[] = { 1.0, 0.0, 0.0, 0.0 };
    static GLfloat slanted[]    = { 1.0, 1.0, 1.0, 0.0 };
    static GLfloat *currentCoeff;
    static GLenum currentPlane;
    static GLint currentGenMode;

    void init(void) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);

        makeStripeImage();
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
        glGenTextures(1, &texName);
        glBindTexture(GL_TEXTURE_1D, texName);
#endif
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
#ifdef GL_VERSION_1_1
        glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
#else
        glTexImage1D(GL_TEXTURE_1D, 0, 4, stripeImageWidth, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
#endif

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        currentCoeff   = xequalzero; //轮廓线与x=0平面的距离
        currentGenMode = GL_OBJECT_LINEAR;
        currentPlane   = GL_OBJECT_PLANE;
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
        glTexGenfv(GL_S, currentPlane, currentCoeff);

        glEnable(GL_TEXTURE_GEN_S); //启用s坐标的纹理生成
        glEnable(GL_TEXTURE_1D);
        glEnable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_AUTO_NORMAL);
        glEnable(GL_NORMALIZE);
        glFrontFace(GL_CW);
        glCullFace(GL_BACK);
        glMaterialf(GL_FRONT, GL_SHININESS, 64.0);
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        glRotatef(45.0, 0.0, 0.0, 1.0);
#ifdef GL_VERSION_1_1
        glBindTexture(GL_TEXTURE_1D, texName);
#endif
        glutSolidTeapot(2.0);
        glPopMatrix();
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if (w <= h)
            glOrtho(-3.5, 3.5, -3.5 * (GLfloat) h / (GLfloat) w,
                    3.5 * (GLfloat) h / (GLfloat) w, -3.5, 3.5);
        else
            glOrtho(-3.5 * (GLfloat) w / (GLfloat) h,
                    3.5 * (GLfloat) w / (GLfloat) h, -3.5, 3.5, -3.5, 3.5);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 'e':
            case 'E':
                currentGenMode = GL_EYE_LINEAR; //产生移动物体的动态轮廓线
                currentPlane   = GL_EYE_PLANE;
                glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
                glTexGenfv(GL_S, currentPlane, currentCoeff);
                glutPostRedisplay();
                break;
            case 'o':
            case 'O':
                currentGenMode = GL_OBJECT_LINEAR; //把木纹图像映射到桌子的表面
                currentPlane   = GL_OBJECT_PLANE;
                glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
                glTexGenfv(GL_S, currentPlane, currentCoeff);
                glutPostRedisplay();
                break;
            case 's':
            case 'S':
                currentCoeff = slanted; //使轮廓线与x+y+z=0平面平行
                glTexGenfv(GL_S, currentPlane, currentCoeff);
                glutPostRedisplay();
                break;
            case 'x':
            case 'X':
                currentCoeff = xequalzero;
                glTexGenfv(GL_S, currentPlane, currentCoeff);
                glutPostRedisplay();
                break;
            case 27:
                exit(0);
                break;
            default:
                break;
        }
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(256, 256);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[ 0 ]);
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
}