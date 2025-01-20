#include <stdio.h>
#include <GL/glut.h>

float angle = 0.0;
float scale = 1.0;
bool hidden = false;

GLfloat lightPos[] = {-0.8, 0.9, 0.4, 1.0};
bool lightingEnabled = true;

void dindingkiri();
void dindingkanan();
void ubin();
void drawKasur();
void meja();
void lampu();
void stand();
void drawcartecius();

//andi
void dindingkiri()
{
    // Dinding Kiri
    glPushMatrix();
    glColor3ub(60, 61, 55);
    glTranslatef(-1.1, 0.98, 0.0);
    glScalef(0.2, 1.8, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

//andi
void dindingkanan()
{
    // Dinding kanan
    glPushMatrix();
    glColor3ub(105, 117, 101);
    glTranslatef(0.65, 0.95, -1.05);
    glScalef(0.7, 1.9, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    // dinding kiri
    glPushMatrix();
    glColor3ub(105, 117, 101);
    glTranslatef(-0.75, 0.95, -1.05);
    glScalef(0.9, 1.9, 0.2);
    glutSolidCube(1.0f);
    glPopMatrix();

    // dinding bawah
    glPushMatrix();
    glColor3ub(105, 117, 101);
    glTranslatef(0.0, 0.25, -1.05);
    glScalef(0.6, 0.5, 0.2);
    glutSolidCube(1.0f);
    glPopMatrix();

    // dinding atas
    glPushMatrix();
    glColor3ub(105, 117, 101);
    glTranslatef(0.0, 1.65, -1.05);
    glScalef(0.6, 0.5, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

//bj
void ubin()
{
    // Ubin
    glPushMatrix();
    glColor3ub(184, 0, 31);
    glScalef(2.0, 0.1, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

//andi
void drawCube(float x, float y, float z)
{
    glPushMatrix();
    glScalef(x, y, z);
    glutSolidCube(1.0);
    glPopMatrix();
}

//andi
void drawKasur()
{
    glPushMatrix();
    glTranslatef(-0.8, 0.0, -0.8);

    // matras
    glColor3f(0.9, 0.9, 0.7);
    glPushMatrix();
    glTranslatef(0.5, 0.15, 0.4);
    drawCube(1.4, 0.2, 0.6);
    glPopMatrix();

    // selimut
    glColor3f(0.0, 0.0, 0.8);
    glPushMatrix();
    glTranslatef(0.7, 0.3, 0.4);
    drawCube(1.0, 0.04, 0.6);
    glPopMatrix();

    // bantal
    glColor3f(0.6, 0.3, 0.2);
    glPushMatrix();
    glTranslatef(-0.05, 0.35, 0.4);
    drawCube(0.25, 0.15, 0.6);
    glPopMatrix();
    glPopMatrix();
}

//andi
void meja()
{
    glPushMatrix();
    glTranslatef(-1.2, 0.0, 0.1);

    // meja
    glColor3f(0.6, 0.4, 0.2);
    glPushMatrix();
    glTranslatef(0.4, 0.3, 0.3);
    drawCube(0.4, 0.5, 0.6);
    glPopMatrix();

    glPopMatrix();

    // laci
    glColor3f(0.82, 0.71, 0.55);
    glPushMatrix();
    glTranslatef(-0.6, 0.35, 0.4);
    drawCube(0.02, 0.18, 0.6);
    glPopMatrix();
}

//bj
void lampu()
{
    // lampu
    glColor3ub(255, 241, 0);
    glPushMatrix();
    glTranslatef(-0.8, 0.9, 0.4);
    glutSolidSphere(0.15, 20, 20);
    glPopMatrix();
}

//bj
void stand()
{
    // stand
    glColor3ub(255, 130, 37);
    glPushMatrix();
    glTranslatef(-0.8, 0.7, 0.4);
    drawCube(0.04, 0.4, 0.04);
    glPopMatrix();
}

//bj
void drawcartecius()
{
    glLineWidth(2.0); 

    // Sumbu X
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glEnd();

    // Sumbu Y
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -50.0, 0.0);
    glVertex3f(0.0, 50.0, 0.0);
    glEnd();

    // Sumbu Z
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -50.0);
    glVertex3f(0.0, 0.0, 50.0);
    glEnd();
}

//bj
void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'c':
        hidden = !hidden;
        break;
    case 'a':
        angle += 10.0;
        break;
    case 'd':
        angle -= 10.0;
        break; 
    case '1':
        scale += 0.1;
        break;
    case '2':
        scale -= 0.1;
        break;
    case 'o':
        lightingEnabled = !lightingEnabled;
        if (lightingEnabled)
        {
            glEnable(GL_LIGHTING);
        }
        else
        {
            glDisable(GL_LIGHTING);
        }
        glutPostRedisplay();
        break;
    }
    glutPostRedisplay();
}

//bj
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0,  // Posisi kamera
              0.0, 1.0, 0.0,  // Titik yang dilihat
              0.0, 1.0, 0.0); // Arah atas kamera

    if (lightingEnabled)
    {
        glEnable(GL_LIGHTING);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
    }
    else
    {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
    }

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glScalef(scale, scale, scale);
    
    dindingkiri();
    dindingkanan();
    ubin();
    drawKasur();
    meja();
    lampu();
    stand();
    glPopMatrix();

    if (hidden)
{
    drawcartecius();
}

    glutSwapBuffers();
}

//bj
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(400, 50);
    glutCreateWindow("TUGAS BESAR KELOMPOK 2");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
    return 0;
}