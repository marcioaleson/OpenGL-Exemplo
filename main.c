#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>

void init(void); void display(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
int x3 = 0, x4 = 0, y3 = 0, y4 = 0;

float vermelho = 0.0, verde = 0.0, azul = 0.0;

float a, b;


int main(int argc, char** argv){
    srand(time(NULL));
    printf("\tCoordenadas da primeira linha:\n\n");
    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    printf("\n\tCoordenadas da segunda linha:\n\n");
    printf("x3: ");
    scanf("%d", &x3);
    printf("y3: ");
    scanf("%d", &y3);
    printf("x4: ");
    scanf("%d", &x4);
    printf("y4: ");
    scanf("%d", &y4);

    a = (float)(y4-y3)/(float)(x4-x3);
    b = (float)y4 - a*(float)x4;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (256, 256);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Resultado");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
return 0;
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();

    glColor3f (vermelho, verde, azul);
    glBegin(GL_LINES);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y){

    switch (key){
        case 27:
            exit(0);
        break;
        case 'c':
        case 'C':
            vermelho = (float)rand()/(float)RAND_MAX;
            verde = (float)rand()/(float)RAND_MAX;
            azul = (float)rand()/(float)RAND_MAX;
            display();
        break;
        case 'a':
        case 'A':
            y1 += 1;
            y2 += 1;
            display();
        break;
        case 'z':
        case 'Z':
            y1 -= 1;
            y2 -= 1;
            display();
        break;
        case 'q':
        case 'Q':
            x1 -= 1;
            x2 -= 1;
            display();
        break;
        case 'w':
        case 'W':
            x1 += 1;
            x2 += 1;
            display();
        break;
        case 'f':
        case 'F':
            if(x3 == x4){
                if(y3 > y4){
                    y3 += 1;
                    y4 -= 1;
                }else{
                    y3 -= 1;
                    y4 += 1;
                }
            }
            if(y3 == y4){
                if(x3 > x4){
                    x3 += 1;
                    x4 -= 1;
                }else{
                    x3 -= 1;
                    x4 += 1;
                }
            }

            if(x3 != x4 && y3 != y4){
                if(x3 < x4){
                    x3 = x3 - 1;
                    x4 = x4 + 1;
                    y3 = a * x3 + b;
                    y4 = a * x4 + b;
                }
                if(x3 > x4){
                    x3 = x3 + 1;
                    x4 = x4 - 1;
                    y3 = a * y4 + b;
                    y4 = a * x4 + b;
                }
            }
            display();
        break;
        case 'v':
        case 'V':
            if(x3 == x4){
                if(y3 > y4){
                    if((y3-1) != (y4+1)){
                        y3 -= 1;
                        y4 += 1;
                    }
                }else{
                    if((y3+1) != (y4-1)){
                        y3 += 1;
                        y4 -= 1;
                    }
                }
            }

            if(y3 == y4){
                if(x3 > x4){
                    if((x3-1) != (x4+1)){
                        x3 -= 1;
                        x4 += 1;
                    }
                }else{
                    if((x3+1) != (x4-1)){
                        x3 += 1;
                        x4 -= 1;
                    }
                }
            }

            if(x3 != x4 && y3 != y4){
                if(x3 < x4){
                    if((x3+1) != (x4-1)){
                        x3 = x3 + 1;
                        x4 = x4 - 1;
                        y3 = a * x3 + b;
                        y4 = a * x4 + b;
                    }
                }
                if(x3 > x4){
                    if((x3-1) != (x4+1)){
                        x3 = x3 - 1;
                        x4 = x4 + 1;
                        y3 = a * y4 + b;
                        y4 = a * x4 + b;
                    }
                }
            }
            display();
        break;
        case 'b':
        case 'B':
             init();
             display();
        break;
    }
}
