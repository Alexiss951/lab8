//Sanchez Santos B. Alexis 367714
//27/SEPTIEMBRE/2023
//Pedir al usuario que elija una de las opciones y llene los vectores e imprima ya sea el vector o la matriz
//VECTOR Y MATRIZ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>

int vali_num(int ri, int rf, char* msge, char* msge2);
void llenaman(int vec[11], int n);
void llenaut(int vec[11], int n, int ri, int rf);
void llenavec(int vec[11], int vic[11], int voc[21], int n, int m);
int vali_vec(int vec[11], int x, int i);
void impvecs (int vec[11], int vic[11], int voc[21], int n, int m);
void llenamat(int vec[11], int vic[11], int mat[][4], int n, int o);
void impmat(int mat[][4], int o);

int main()
{
    int opc,vec1[11], vec2[11], vec3[21], mat[4][4], n, m, o;
    n=10;
    m=20;
    o=4;
    srand(time(NULL));
    do
    {
        system("CLS");
        printf("\n----------------------MENU-----------------------");
        printf("\n0-------------------------------------------Salir");
        printf("\n1--------------------Llenar un vector manualmente");
        printf("\n2----------------Llenar un vector automaticamente");
        printf("\n3-----Llenar el tercer vector con datos del 1 y 2");
        printf("\n4-------------------------------Imprimir vectores");
        printf("\n5-------------------------------Llenar matriz 4x4");
        printf("\n6-----------------------------Imprimir matriz 4x4\n");
        system("PAUSE");
        opc=vali_num(0, 6, "elige una opcion ", "Favor de elegir una de las opciones antes mostradas (del 0 al 6)");
        switch(opc)
        {
            case 1:
            llenaman(vec1, n);
            break;
            case 2:
            llenaut(vec2, n, 1, 20);
            system("CLS");
            break;
            case 3:
            llenavec(vec1, vec2, vec3, n, m);
            break;
            case 4:
            impvecs(vec1, vec2, vec3, n, m);
            break;
            case 5:
            llenamat(vec1, vec2, mat, n, o);
            break;
            case 6:
            impmat(mat, o);
            break;
            default:
            printf("\nAdios");
        }
    }while(opc!=0);
}

int vali_num(int ri, int rf, char* msge, char* msge2)
{
    char xnum[30];
    int num;
    do
    {
        system("CLS");
        printf("%s",msge);
        fflush(stdin);
        gets(xnum);
        num=atoi(xnum);
        if(num< ri || num> rf)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    }while(num< ri || num> rf);
    return num;
}
void llenaman(int vec[11], int n)
{
    int i, opc;
    system("CLS");
    for(i=0;i<n;i++)
    {
        opc=vali_num(30, 70, "Escribe un numero entre el 30 y el 70 ", "Debe ser entre el 30 al 70");
        vec[i]=opc;
    }
    printf("\nListo\n");
    system("PAUSE");
}

void llenaut(int vec[11], int n, int ri, int rf)
{
    int i, j, band, x;
    j=rf-ri;
    system("CLS");
    vec[0]=(rand()%j)+ri;
    for(i=1;i<n;i++)
    {
        x=(rand()%j)+ri;
        band=vali_vec(vec, x, i);
        if(band==1)
        {
            i=i-1;
        }
        else
        {
            vec[i]=x;
        }
    }
    printf("\nLlenado automatico de vector");
    printf("\nlisto\n");
    system("PAUSE");
}

int vali_vec(int vec[11], int x, int j)
{
    int i;
    for(i=0;i<j;i++)
    {
        if(vec[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

void llenavec(int vec[11], int vic[11], int voc[21], int n, int m)
{
    int i, j;
    j=0;
    printf("\nLlenado de tercer vector con num. del vec.1 y vec.2 ");
    for(i=0;i<m;i++)
    {
        if(i<n)
        {
            voc[i]=vec[i];
        }
        else
        {
            voc[i]=vic[j];
            j=j+1;
        }
    }
    system("CLS");
    printf("\n Listo\n");
    system("PAUSE");
}

void impvecs (int vec[11], int vic[11], int voc[21], int n, int m)
{
    int i;
    system("CLS");
    printf("\nVector 1\n");
    for(i=0;i<n;i++)
    {
        printf("Pocsicion %d = [%d] \n", i, vec[i]);
    }
    printf("\nVector 2\n");
    for(i=0;i<n;i++)
    {
        printf("Pocsicion %d = [%d] \n", i, vic[i]);
    }
    printf("\nVector 3\n");
    for(i=0;i<m;i++)
    {
        printf("Pocsicion %d = [%d] \n", i, voc[i]);
    }
    printf("\nListo\n");
    system("PAUSE");
}
void llenamat(int vec[11], int vic[11], int mat[][4], int n, int o)
{
    int i, j, k, l;
    k=0;
    l=0;
    for(i=0;i<o;i++)
    {
        for(j=0;j<o;j++)
        {
            if(i<2)
            {
                mat[i][j]=vec[k];
                k=k+1;
            }
            else
            {
                mat[i][j]=vic[l];
                l=l+1;
            }
        }
    }
    system("CLS");
    printf("Llenado de matriz con numeros del vec1 y vec 2");
    printf("\nListo\n");
    system("PAUSE");
}
void impmat(int mat[][4], int o)
{
    int i, j;
    system("CLS");
    printf("Impresion de matriz\n");
    for(i=0;i<o;i++)
    {
        printf("\nFila %d ",i);
        for(j=0;j<o;j++)
        {
            printf("[%d] ", mat[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}