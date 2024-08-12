#include <GL/glut.h>
#include <cmath> 

float angle = 0.0f;  // Ângulo de rotação
int direction = 1;   // 1 para horário, -1 para anti-horário
bool rotating = true; 

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
}

void draw(float cx, float cy, float x1, float y1, float x2, float y2, float angle)
{
    float cosA = cos(angle);
    float sinA = sin(angle);

    // Primeiro vértice
    float x1r = cosA * (x1 - cx) - sinA * (y1 - cy) + cx; //- cx translada para origem + cx retorna
    float y1r = sinA * (x1 - cx) + cosA * (y1 - cy) + cy;

    // Segundo vértice
    float x2r = cosA * (x2 - cx) - sinA * (y2 - cy) + cx;
    float y2r = sinA * (x2 - cx) + cosA * (y2 - cy) + cy;

    // Terceiro vértice (centro)
    float xcr = cx;
    float ycr = cy;

    // Desenhar o triângulo
    glBegin(GL_TRIANGLES);
        glVertex2f(xcr, ycr);
        glVertex2f(x1r, y1r);
        glVertex2f(x2r, y2r);
    glEnd();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Centro
    float cx = 250.0f;
    float cy = 250.0f;

    // novo ângulo de rotação
    if (rotating) {
        angle += 0.10f * direction;
    }

    // converte para radianos
    float rad = angle * 3.14159f / 180.0f;

    //base do catavento
    glColor3f(1.0, 1.0, .0);
    glBegin(GL_POLYGON);
        glVertex2f(249.0f, 250.0f);
        glVertex2f(251.0f, 250.0f);
        glVertex2f(249.0f, 100.0f);
        glVertex2f(251.0f, 100.0f);
    glEnd();

    // branco
    glColor3f(1.0, 1.0, 1.0);
    draw(cx, cy, 230.0f, 200.0f, 270.0f, 200.0f, rad);

    // vermelho
    glColor3f(1.0, 0.0, 0.0);
    draw(cx, cy, 300.0f, 230.0f, 300.0f, 270.0f, rad);

    // verde
    glColor3f(0.0, 1.0, 0.0);
    draw(cx, cy, 230.0f, 300.0f, 270.0f, 300.0f, rad);

    // azul
    glColor3f(0.0, 0.0, 1.0);
    draw(cx, cy, 200.0f, 270.0f, 200.0f, 230.0f, rad);

    glFlush();
    glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_RIGHT:
            direction = 1;
            rotating = true;
            break;
        case GLUT_KEY_LEFT:
            direction = -1;
            rotating = true;
            break;
        case GLUT_KEY_UP:
            rotating = true;
            break;
        case GLUT_KEY_DOWN:
            rotating = false;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flor de Abril");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);

    glutMainLoop();

    return 0;
}