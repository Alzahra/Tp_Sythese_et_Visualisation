//  GLUTFenetre.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>

//stoper le Timer + faire tourner independamment ou non

using namespace std;

float WIDTH = 400;
float HEIGHT = 400;
//Taille de l'arete
int a = 1;
//pour le TImer
int indiceTimer;

float M1[16] /*= {1.0, 0.0, 0.0,0.0,
                0.0, 1.0, 0.0,0.0,
                0.0, 0.0, 1.0,0.0,
                0.0, 0.0, 0.0,1.0}*/;
float M2[16];
int cptTimer1 =1;
int cptTimer2 =1;
bool quelmat; //1 M1, 0 M2
bool lesdeux; //0 non, 1 les deux
int lemonde = 1;

bool mobile =0;

/***********PROTOTYPES***********/
void def_carre();
void def_axes();
void def_boite(int a);
void affichage();
void redim(int width, int height);
void RotationM(float M[16], int valaxe, float angle);
void Timer(int value);
void clavier(unsigned char key, int x, int y);
/********************************/

//Dessin d'une face
void def_carre(void){

    glBegin(GL_POLYGON);
        glNormal3f(0., 0., 1.) ;
        glVertex3f(-0.5,0.5,0.);
        glVertex3f(0.5,0.5,0.);
        glVertex3f(0.5,-0.5,0.);
        glVertex3f(-0.5 ,-0.5,0.);
    glEnd();

}

//Trace les axes, X rouge, Y Vert, Z Bleu
void def_axes(void){
    
    glBegin(GL_LINES);
        //x
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-1,0.0,0.0);
        glVertex3f(1,0.0,0.0);
        //y
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0,-1,0.0);
        glVertex3f(0.0,1,0.0);
        //z
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0,0.0,-1);
        glVertex3f(0.0,0.0,1);
    glEnd();
}

//Dessine la boite, face par face, d'arrete 'a'
void def_boite(int a){
    
    //Par rapport au carre vert de base
    
    // face bleu, le fond
    //on le met devant en translatant selon z
    glPushMatrix();
        //glColor3f(0.0, 0.1, 1.0);
        GLfloat blue[4] = {0.0f, 0.0f ,1.0f ,1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE , blue);
        glTranslatef(0.0, 0.0, a/2.0);
        glRotatef(180, 1, 0, 0);

        def_carre();
    
    glPopMatrix();
    
    // face rouge, de droite
    //rotation de 90 selon l'axe des y et translation sur les x et z
    glPushMatrix();
        //glColor3f(1.0, 0.0, 0.0);
        GLfloat red[4] = {1.0f, 0.0f ,0.0f ,1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE , red);
    

        glTranslatef(a/2.0, 0.0, 0.0);
        glRotatef(270, 0, 1, 0);
        def_carre();
    glPopMatrix();
    
    // face jaune, de gauche
    glPushMatrix();
        //glColor3f(1.0, 1.0, 0.0);
        GLfloat yel[4] = {1.0f, 1.0f ,0.0f ,1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE , yel);
        glTranslatef(-a/2.0, 0.0,0.0);
        glRotatef(90, 0, 1, 0);
        def_carre();
    glPopMatrix();
    
    // face blanche, de haut
    
    glPushMatrix();
        //glColor3f(1.0, 1.0, 1.0);
        GLfloat blanche[4] = {1.0f, 1.0f ,1.0f ,1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE , blanche);
        glTranslatef(0.0, a/2.0, 0.0 );
        glRotatef(90, 1, 0, 0);
        def_carre();
    glPopMatrix();
    
    glPushMatrix();
    //face verte, derriere
        //glColor3f(0.0, 1.0, 0.0);
        GLfloat green[4] = {0.0f, 1.0f ,0.0f ,1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE , green);
        glTranslatef(0.0, 0.0, -a/2.0 );
        def_carre();
    glPopMatrix();
    
}



void affichage(void){
    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_BACK, GL_LINE);
    //glCullFace(GL_FRONT);
    
    
    def_axes();
    
    //1er cube
    glPushMatrix();
        glTranslatef(-1.0,0.0,0.0);
        glMultMatrixf(M1);
        def_boite(a);
    glPopMatrix();
    
    //2eme cube
    glPushMatrix();
        glTranslatef(1.0,0.0,0.0);
        glMultMatrixf(M2);
        def_boite(a);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glPushMatrix();
        if(mobile){
            glMultMatrixf(M1);
        }
        float lightPosition[4] = {2, 3, 5, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
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
    //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
    //ou
    gluPerspective(75,(float)width/height, 1.0,100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //Initialisation de M1 et M2 = Identity
    glGetFloatv(GL_MODELVIEW_MATRIX,M1);
    glGetFloatv(GL_MODELVIEW_MATRIX,M2);
    
    
    
    //         eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
    //gluLookAt (1.0, -2.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt (0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
}

//Rotation de la boite, avec comme parametre : Matrice de la boite, Axe de rotation, Angle de Rotation
void RotationM(float M[16], int valaxe, float angle) {
    glPushMatrix();
        glLoadIdentity();
        glLoadMatrixf(M);
    
        switch (valaxe) {
            case 1: //x
                glRotatef(angle, 1.0, 0.0, 0.0);
                break;
            case 2: //y
                glRotatef(angle, 0.0, 1.0, 0.0);
                break;
            case 3://z
                glRotatef(angle, 0.0, 0.0, 1.0);
                break;
        }
        glGetFloatv(GL_MODELVIEW_MATRIX, M);
    glPopMatrix();
}


//Timer pour rotation,
//utilise cptTimer1, cptTimer2 pour les compteurs de touches
// lesdeux comme booléen pour savoir si on veut faire tourner les 2 ou non
// quelmat comme booléen pour savoir quelle boite tourne
void Timer(int value){
    
//        glRotatef(-3, 0,1,0);
//        glRotatef(5, 1,0,0);
//        glRotatef(-2, 0,0,1);
    if(!lesdeux && lemonde%2){
        if (quelmat){
            RotationM(M1, 2,-3);
            RotationM(M1, 1,5);
            RotationM(M1, 3,-2);
        }else {
            RotationM(M2, 2,-3);
            RotationM(M2, 1,5);
            RotationM(M2, 3,-2);
        }
    }else if (lesdeux && lemonde%2){
        RotationM(M1, 2,-3);
        RotationM(M1, 1,5);
        RotationM(M1, 3,-2);
        
        RotationM(M2, 2,-3);
        RotationM(M2, 1,5);
        RotationM(M2, 3,-2);
    }
    
    if (lemonde%2 ==0){
        glRotatef(2,0,0,1);
        glRotatef(-3,0,1,0);
        glRotatef(5,1,0,0);
    }
    
    glutPostRedisplay();
    
    if(cptTimer1%2 == 0 && lemonde%2)
        glutTimerFunc(10, Timer, 0);
    else if(cptTimer2%2 == 0 && lemonde%2)
        glutTimerFunc(10, Timer, 0);
    else if(lemonde%2 == 0)
        glutTimerFunc(10, Timer, 0);
}

//Pour binder les touches
//PREMIER CUBE :
// q gauche, d droite, s bas, z haut
// tourner seul f

//SECOND CUBE :
//g gauche, j droite, h bas, y haut
//tourner seul t

//Tourner dans l'espace e
//Tourner les 2 : espace
//Fermer : a, A
void clavier(unsigned char key, int x, int y){

    switch (key){
        //1ercube
        case 'q':
        case 'Q':
            RotationM(M1,2,-10);
            break;
            
        case 'd':
        case 'D':
            RotationM(M1,2,10);
            break;
            
        case 'z':
        case 'Z':
            RotationM(M1,1,-10);
            break;
            
        case 's':
        case 'S':
            RotationM(M1,1,10);
            break;
            
        //2eme cube
        case 'g':
        case 'G':
            RotationM(M2,2,-10);
            break;
        case 'h':
        case 'H':
            RotationM(M2,1,10);
            break;
            
        case 'j':
        case 'J':
            RotationM(M2,2,10);
            break;
            
        case 'y':
        case 'Y':
            RotationM(M2,1,-10);
            break;
            
        //Tourner
        case 'f': //1er cube
        case 'F':
            cptTimer1++;
            quelmat = 1;
            lesdeux =0;
            Timer(0);
            break;
            
        case 't': //2eme cube
        case 'T':
            cptTimer2++;
            quelmat = 0;
            lesdeux =0;
            Timer(0);
            break;
            
        case ' ': //les2
            cptTimer1++;
            cptTimer2++;
            lesdeux = 1;
            Timer(0);
            break;
            
        case 'e': //le monde
        case 'E':
            lemonde++;
            Timer(0);
            break;
            
        //lumiere
        case 'w' :
        case 'W':
            mobile =!mobile;
            break;
            
        //fermer
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
 
    printf( "\nCommandes : \n Pour tourner la scene touche e \n");
    printf("PREMIER CUBE (gauche) : \n q gauche, d droite, s bas, z haut \n tourner seul f\n\n");
    
    printf("SECOND CUBE : \n g gauche, j droite, h bas, y haut \n tourner seul t");
 
    printf("Tourner les 2 : espace\n");
    printf("Fermer : a, A \n");
    
    glutMainLoop();
    
    return 0;
    
}
