//  GLUTFenetre.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>
#include <stdlib.h>

#define LONGUEUR 10
#define SECTION 1

float WIDTH = 400;
float HEIGHT = 400;

float teta =-30;


void def_carre(float a){
    glBegin(GL_POLYGON);
    glVertex2f(-a/2.0,a/2.0);
    glVertex2f(a/2.0 ,a/2.0);
    glVertex2f(a/2.0,-a/2.0);
    glVertex2f(-a/2.0 ,-a/2.0);
    glEnd();
}


void def_boite(float a){
    
    //Par rapport au carre vert de base
    
    // face bleu, le fond
    //on le met devant en translatant selon z
    glPushMatrix();
    glColor3f(0.0, 0.1, 1.0);
    glTranslatef(0.0, 0.0, a/2.0);
    glRotatef(180, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    // face rouge, basse
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, -a/2., 0.0);
    glRotatef(270, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    // face jaune, de gauche
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-LONGUEUR/2.0 , 0.0,0.0);
    glRotatef(90, 0, 1, 0);
    //membre(0,a);
    def_carre(a);
    glPopMatrix();
    
    // face blanche, de haut
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, a/2.0, 0.0 );
    glRotatef(90, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    //face verte, derriere
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -a/2.0 );
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
}

void def_oreille(float a){
    //Par rapport au carre vert de base
    
    // face bleu, le fond
    //on le met devant en translatant selon z
    glPushMatrix();
    glColor3f(0.0, 0.1, 1.0);
    glTranslatef(0.0, 0.0, SECTION/2.0);
    glRotatef(180, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    // face rouge, basse
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, -SECTION/2., 0.0);
    glRotatef(270, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    // face jaune, de gauche
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-LONGUEUR/2.0 , 0.0,0.0);
    glRotatef(90, 0, 1, 0);
    //membre(0,a);
    def_carre(a);
    glPopMatrix();
    
    // face blanche, de haut
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, SECTION/2.0, 0.0 );
    glRotatef(90, 1, 0, 0);
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
    
    //face verte, derriere
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -SECTION/2.0 );
    //membre(LONGUEUR,a);
    glScalef(LONGUEUR*a,SECTION,SECTION);
    def_carre(a);
    glPopMatrix();
}


void affichage(void){
    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_BACK, GL_LINE);
   
    glPushMatrix();
    def_boite(SECTION);
    glPopMatrix();
    
    glPushMatrix();
    //glTranslatef(-4, 1.,0.);
    def_oreille(SECTION/10.);
    glPopMatrix();
    
    //on affiche
    glutSwapBuffers();
}



void redim(int width, int height){
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,width, height);
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    //          left,right,bot,top,nearVal,farVal
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //         eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
    //gluLookAt (1.0, -2.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
}


void clavier(unsigned char key, int x, int y){
    switch (key){
            
        case 'q':
            glRotatef(-10, 0,1,0);
            break;
        case 'd':
            glRotatef(10, 0,1,0);
            break;
        case 'z':
            glRotatef(-10, 1,0,0);
            break;
        case 's':
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
