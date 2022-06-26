#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdio.h>
 
//-----------------------------------------------------------------------------
 
 struct sim
 {
 int lu;
 char nom[30];
 };
 void insertar(FILE *,struct sim);
 int leer(FILE *,struct sim);
 
 struct sim play;
 FILE *archivo;
 
 
   struct nodo {
 int info;
 struct nodo *sig;
 struct nodo *ant;
 };
 struct nodo *p=NULL,*r=NULL, *pa=NULL;
 void mostrar_lista( struct nodo *p);
 int n, dat;
 int dig;
 int i,cap;
int puntos;
 int ps,ps2;
 int m;
 
 
 
//---------------------------------------------------------------------
 
//---------------------------------------------------------------------
 
 
 void eliminar_ul( struct nodo **p)
 {
 int c;
 struct nodo *ultimo;
 struct  nodo *penultimo;
 for(c=0;c<=cap;c++)
 {
 ultimo=*p;
 penultimo=*p;
 if(ultimo!=NULL)
 {
 if((*p)->sig == NULL)
 {
 
 delete ultimo;
 *p = NULL;
 }else{
 ultimo = ultimo->sig;
 while(ultimo->sig != NULL)
 {
 ultimo = ultimo->sig;
 penultimo= penultimo->sig ;
 }
 penultimo->sig = NULL;
 
 delete ultimo;
 }
 }
 
 else
 
 {
 
 }
 }
 }
 
//---------------------------------------------------------------------
 
 void eliminar_ul1( struct nodo1 **p1){
 int c1;
 
 struct nodo1 *ultimo1;
 struct  nodo1 *penultimo1;
 for(c1=0;c1<=cap;c1++)
 {
 ultimo1=*p1;
 penultimo1=*p1;
 if(ultimo1!=NULL)
 {
 if((*p1)->sig1 == NULL)
 {
 
 delete ultimo1;
 *p1 = NULL;
 }
 
 else
 
 {
 ultimo1 = ultimo1->sig1;
 while(ultimo1->sig1 != NULL)
 {
 ultimo1 = ultimo1->sig1;
 penultimo1= penultimo1->sig1 ;
 }
 penultimo1->sig1 = NULL;
 
 delete ultimo1;
 }
  }
 
  else
 
 {
 
 }
 
 }
 
 }
 
//---------------------------------------------------------------------
 void mostrar_lista1( struct nodo1 *p1)
 {
 clrscr();
 system("color 1e");
 gotoxy(20,2);cout<<"**************PRUEVA TU MEMORIA****************** \n \n";
 
 struct nodo1 *q1;
 q1=p1;
 while(q1!=NULL)
 {
 cout<<q1->info1<<"\t";
 q1=q1->sig1;
 ps++;
 }
  }
 
 
 
 
 void inserta_nodo( struct nodo **p)
 {
 gotoxy(ps2,5);
 cin>>n;
 ps2=ps2+4;
 struct nodo *q;
 
 if (*p==NULL)
 {
 *p=new nodo;
 (*p)->info=n;
 (*p)->sig=NULL;
 (*p)->ant=NULL;
 r=*p;
 }
 
 else
 
 {
 q=new nodo;
 q->info=n;
 q->sig=NULL;
 q->ant=r;
 r->sig=q;
 r=q;
 
}
}
 
 
//---------------------------------------------------------------------
 
 void compararN_V(nodo1 *p1, nodo *p){
 i=0;
 nodo1 *q1;
 nodo *q;
 q1=p1;
 q=p;
 
 
 while(q1!=NULL)
 {
 if(q1->info1==q->info) {
 i++;
 
 q1=q1->sig1;
 q=q->sig;
 }
 
 else
 
 {
 break;
 }
 
 }
 
 }
 
 int main(){
 int opc,o;
 do{
 clrscr();
 i=0;cap=0;puntos=0;
 ps=1;ps2=1;
 
 m=1;
 system("color 5");
 
 
 gotoxy(15,6);
 cout<<"DIGITA UN OPCION";
 gotoxy(13,10);
 cout<<" MENU ";
 gotoxy(25,13);
 cout<<" 1: JUGAR ";
 gotoxy(25,16);
 cout<<"2: PUNTAJES";
 gotoxy(25,19);
 cout<<"3: INFORMACION ";
 gotoxy(25,22);
 cout<<"4: SALIR ";
 gotoxy(25,24);
 cout<<"Digite la opcion:";
 gotoxy(43,24);
 cin>>opc;
 switch(opc){
 
 case 1:
         programa();
         clrscr();
         break;
 
 case 2:
         leer(archivo,play);
         break;
 
 
 case 3:
         informacion();
         break;
 
 
 case 4:
         exit(0);
         default:
         gotoxy(25,26);
 
 cout<<" **** OPCION NO VALIDA **** ";
 
 getch();
 }
 }
 while(opc!=4);
 }
 
 
 
//---------------------------------------------------------------------
 
 
 int programa(){
 clrscr();
 randomize();
 int enter;
 system("color 7");
 gotoxy(20,2);cprintf("********PRUEBA TU MEMORIA AL MAXIMO*********");
 gotoxy(17,5);
 cout<<" DIGITE SU NOMBRE\n";
 gotoxy(10,8);
 gets(play.nom);
 
 
 clrscr();
 do{
 inserta_nodo1(&p1);
 mostrar_lista1(p1);
 system("color 5");
 Sleep(2600+tiempo);
 tiempo=tiempo+600;
 if(m%2==0){
 tiempo=tiempo+100;
 
 
 }
 clrscr();
 m++;
 system("color 4");
 gotoxy(20,2);cprintf("***************Prueba tu memoria***************");
 
 gotoxy(20,4);cout<<"°°°°°° Ingresa Los Numeros Memorizados °°°°°°°";
 system("color 4");
 ps2=2;
 for(int F=1;F<=cap;F++){
 inserta_nodo(&p);
 }
 compararN_V(p1,p);
 
 
 
 sleep(1); gotoxy(48,21);cout<<"Solicitando Partida...........";
 sleep(1); gotoxy(58,23);cout<<"Cargando............";
 int puntaje;
 if(i==cap)
 {
 
 eliminar_ul(&p);
 
 
 sleep(2);
 }
 
 else
 
 {
 puntaje=cap-1;
 
 gotoxy(3,22);cout<<"TU PUNTAJE ES: "<<puntaje;
 play.lu=puntaje;
 eliminar_ul(&p);
 eliminar_ul1(&p1);
 insertar(archivo,play);
 }
 
 }
 while(i==cap);
 gotoxy(3,23);cout<<"GRACIAS POR JUGAR PRUEVA TU MEMORIA..\n";
 
 getch();
 return(0);
 }
 
 
 void insertar(FILE *archi, struct sim play)
 {
 
 archi = fopen("datos.bin", "a+b");
 
 fwrite(&play, sizeof(play), 1, archivo);
 fclose(archivo);
 
 }
 
 
//---------------------------------------------------------------------
 
 int leer(FILE *archi,struct sim juego)
 
 {
 
 system("cls");
 if ((archi = fopen("datos.bin", "rb"))== NULL)
 
 {
 
 printf("imposible abrir el archivo o el archivo no existe\n\n\n");
 printf("Presione una tecla para continuar");
 
 getchar();
 return 1;
 
 }
 
 else
 
 {
 
 fread(&juego, sizeof(juego), 1, archi);
 while (feof(archi)==0)
 {
 
 printf("\puntaje:%d",juego.lu);
 printf("\nNombre:");
 puts(juego.nom);
 printf("\n.....................\n");
 fread(&juego, sizeof(juego), 1, archi);
 }
 
 system("pause");
 fclose(archi);
 return 0;
 
 }
 
 }
