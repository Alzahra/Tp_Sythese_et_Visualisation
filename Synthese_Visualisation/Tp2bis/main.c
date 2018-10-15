//  GLUTFenetre.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>
#include <stdlib.h>

float WIDTH = 400;
float HEIGHT = 400;
int a = 1;

float anglex =90.0 ;
float angley = 90.0;

void def_carre(void){

    glBegin(GL_POLYGON);
    glVertex2f(-a/2.0,a/2.0);
    glVertex2f(a/2.0,a/2.0);
    glVertex2f(a/2.0,-a/2.0);
    glVertex2f(-a/2.0 ,-a/2.0);
    glEnd();

}

//void def_axes(void){
//    glRotatef(anglex,1,0,0);
//    glRotatef(angley,0,1,0);
//}

void def_axes(void){
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glRotatef(90,0,0,1);
}

void def_boite(int a){
    
    //Par rapport au carre vert de base
    
    // face bleu, le fond
    //on le met devant en translatant selon z
    glPushMatrix();
    glColor3f(0.0, 0.1, 1.0);
    glTranslatef(0.0, 0.0, a/2.0);
    glRotatef(180, 1, 0, 0);
    def_carre();
    glPopMatrix();
    
    // face rouge, de droite
    //rotation de 90 selon l'axe des y et translation sur les x et z
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(a/2.0, 0.0, 0.0);
    glRotatef(270, 0, 1, 0);
    def_carre();
    glPopMatrix();
    
    // face jaune, de gauche
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-a/2.0, 0.0,0.0);
    glRotatef(90, 0, 1, 0);
    def_carre();
    glPopMatrix();
    
    // face blanche, de haut
    
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, a/2.0, 0.0 );
    glRotatef(90, 1, 0, 0);
    def_carre();
    glPopMatrix();
    
    //face verte, derriere
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -a/2.0 );
    def_carre();

    
}


void affichage(void){
    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_BACK, GL_LINE);
   
    def_boite(a);
    def_axes();
    
    //on affiche
    glutSwapBuffers();
}



void redim(int width, int height){
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,width, height);
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    //          left,right,bot,top,nearVal,farVal
    //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
    //ou
    gluPerspective(75,1.0, 1.0,20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //         eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
    //gluLookAt (1.0, -2.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt (0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
}


void clavier(unsigned char key, int x, int y){
    switch (key){
        case 'q':
            //angley = angley - 10.0;
            def_axes();
            glRotatef(-10, 0,1,0);
            break;
        case 'd':
            //angley = angley + 10.0;
            def_axes();
            glRotatef(10, 0,1,0);
            break;
        case 'z':
            //anglex = anglex - 10.0;
            def_axes();
            glRotatef(-10, 1,0,0);
            break;
        case 's':
            //anglex = anglex + 10.0;
            def_axes();
            glRotatef(10, 1,0,0);
            break;
        case 'a':
        case'A' :
            exit (0);
            break;
        default:
            break;
    }glutPostRedisplay();
}

//void clavier(unsigned char key, int x, int y){
//    switch (key){
//        case 'q':
//            def_axes();
//            glRotatef(-30, 0,1,0);
//            break;
//        case 'd':
//            def_axes();
//            glRotatef(30, 0,1,0);
//            break;
//        case 'z':
//            def_axes();
//            glRotatef(-30, 1,0,0);
//            break;
//        case 's':
//            def_axes();
//            glRotatef(30, 1,0,0);
//            break;
//        case 'a':
//        case'A' :
//            exit (0);
//            break;
//    }glutPostRedisplay();
//}


int main (int argc, char **argv){
    
    //Initialisation de GLUT
    glutInit(&argc, argv);
    
    //Taille et emplacemet de la fenetre
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,100);
    
    //Type d'affichage, Tampon de profondeur, Double buffer
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    //Creation de la premiere fenetre
    glutCreateWindow("Polygon");
   
    //Association des callback
    glutDisplayFunc(affichage);
    glutReshapeFunc(redim);
    
    //Action Clavier
    glutKeyboardFunc(clavier);
    //glutMouseFunc(souris);
 
    glutMainLoop();
    
    return 0;
    
}
