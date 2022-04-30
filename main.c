/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aspxe
 *
 * Created on 19 de abril de 2022, 01:27 PM
 */

#include <stdio.h>
#include "Funciones.h"
#include <string.h>

struct Usuario {
    int id[10];
    char nombre[20];
    char contrasena[20];
    char nombreValidador[20];
    char contrasenaValidador[20];
    float Depositos[20];
    float Retiros[20];
    char nombreAdmin[20];
    char contrasenaAdmin[20];
    char nombreAdminVal[20];
    char contrasenaAdminVal[20];
};
//Solo puedes crear una cuenta, de momento

/*
 * 
 */
int main(int argc, char** argv) {
    int sel1;
    int contador = 0;
    int validador;
    int n = 0;
    int i;
    int j;
    int tries = 3;
    int cuenta;
    int contadorDep, contadorRet;
    int validadorDep = 0, validadorRet = 0;
    int sel3;
    int sel4;
    float dineroDisponible = 0;
    struct Usuario u;
    do {
        printf("\n::::::::::::::::::::::::::::::\n");
        printf("Welcome, please select an option\n");
        printf("1.- Sign in\n2.- Sign up\n3.- Admin menu\n5.- Exit\nOption: ");
        scanf("%i", &sel1);
        switch (sel1) {
            case 1:
                printf("Name: ");
                fflush(stdin);
                fgets(u.nombreValidador, 20, stdin);
                printf("Password: ");
                fflush(stdin);
                fgets(u.contrasenaValidador, 20, stdin);
                if (strcmp(u.nombre, u.nombreValidador) == 0 && strcmp(u.contrasena, u.contrasenaValidador) == 0) {
                    printf("Welcome, %s\n", u.nombre);
                    printf("1.- Account status\n2.- Deposit\n3.- Withdraw\nOption: ");
                    scanf("%i", &cuenta);
                    if (cuenta < 4 && cuenta > 0) {
                        switch (cuenta) {
                            case 1:

                                printf("\t-----Deposits-----\n");

                                for (contadorDep = 0; contadorDep < validadorDep; contadorDep++) {
                                    printf("Deposit: %0.2f\n", u.Depositos[contadorDep]);
                                }

                                printf("\t-----Withdraws-----\n");

                                for (contadorRet = 0; contadorRet < validadorRet; contadorRet++) {
                                    printf("Withdraw: %0.2f\n", u.Retiros[contadorRet]);
                                }
                                break;
                            case 2:

                                printf("\t-----Deposit-----\n");

                                printf("Deposit money to your account!\n");
                                printf("Quantity: ");
                                for (contadorDep = validadorDep; contadorDep < validadorDep + 1; contadorDep++) {
                                    scanf("%f", &u.Depositos[contadorDep]);
                                    printf("Deposit sucessful\n");
                                }
                                validadorDep += 1;
                                break;
                            case 3:

                                printf("\t-----Withdraw-----\n");
                                if (validadorDep > 0) {
                                    for (contadorRet = validadorDep - 1; contadorRet < validadorDep; contadorRet++) {
                                        dineroDisponible = dineroDisponible + u.Depositos[contadorRet];
                                    }
                                    printf("%0.2f aviable\n", dineroDisponible);
                                    printf("Quantity to withdraw: ");
                                    for (contadorRet = validadorRet; contadorRet < validadorRet + 1; contadorRet++) {
                                        scanf("%f", &u.Retiros[contadorRet]);
                                        dineroDisponible = dineroDisponible - u.Retiros[contadorRet];
                                    }
                                    validadorRet += 1;
                                    printf("Withdraw sucessful!\n");
                                    printf("New balance: %0.2f", dineroDisponible);

                                } else {
                                    printf("No recorded transactions\n");
                                }

                                break;
                        }
                    }
                    else {
                        printf("Incorrect number, try again.");
                    }
                }
                else {
                    if (tries == 3) {
                        printf("Name or password incorrect, try again (%i tries remain)\n", tries);
                        tries -= 1;
                    }
                    else {
                        printf("Name or password incorrect, try again (%i tries remain)\n", tries);
                        tries -= 1;
                    }
                    if (tries == 0) {
                        printf("%i tries remaining, closing program...\n", tries);
                        sel1 == 5;
                        continue;
                    }

                }
                break;
            case 2:
                if (contador == 0) {
                    for (i = n; i < n + 1; i++) {
                        printf("Name(<=20 characters): ");
                        fflush(stdin);
                        fgets(u.nombre, 20, stdin);
                        printf("\nPassword(<=20 characters): ");
                        fflush(stdin);
                        fgets(u.contrasena, 20, stdin);
                        printf("\nAccount registered!\n");
                    }
                    contador += 1;
                    n += 1;
                }
                else {
                    printf("Press 1 to create an new account: ");
                    scanf("%i", &validador);
                    if (validador == 1) {
                        switch (validador) {
                            case 1:
                                for (j = n; j < n + 1; j++) {
                                    printf("Name(<=20 characters): ");
                                    fflush(stdin);
                                    fgets(u.nombre, 20, stdin);
                                    printf("Password(<=20 characters): ");
                                    fflush(stdin);
                                    fgets(u.contrasena, 20, stdin);
                                    printf("Account created!\n");
                                }
                                n += 1;
                                break;
                        }
                    }
                    else {
                        printf("Wrong number, try again.\n");
                    }
                }
                break;
            case 3:
                printf("==============================\n");
                printf("1.- Create admin account\n2.- Log in admin account\nOption: ");
                scanf("%i", &sel3);
                switch (sel3) {
                    case 1:
                        printf("Name(<=20 characters): ");
                        fflush(stdin);
                        fgets(u.nombreAdmin, 20, stdin);
                        printf("Password(<=20 characters): ");
                        fflush(stdin);
                        fgets(u.contrasenaAdmin, 20, stdin);
                        printf("Admin account created!\n");
                        break;
                    case 2:
                        printf("Name: ");
                        fflush(stdin);
                        fgets(u.nombreAdminVal, 20, stdin);
                        printf("Password: ");
                        fflush(stdin);
                        fgets(u.contrasenaAdminVal, 20, stdin);
                        if (strcmp(u.nombreAdmin, u.nombreAdminVal) == 0 && strcmp(u.contrasenaAdmin, u.contrasenaAdminVal) == 0) {
                            printf("Welcome, %s\n", u.nombreAdmin);
                            printf("1.- View user account status\nOption: ");
                            scanf("%i", &sel4);
                            switch (sel4) {
                                case 1:
                                    printf("-----------------------------");
                                    printf("\t-----Deposits-----\n");

                                    for (contadorDep = 0; contadorDep < validadorDep; contadorDep++) {
                                        printf("Deposit: %0.2f\n", u.Depositos[contadorDep]);
                                    }

                                    printf("\t-----Withdraws-----\n");

                                    for (contadorRet = 0; contadorRet < validadorRet; contadorRet++) {
                                        printf("Withdraw: %0.2f\n", u.Retiros[contadorRet]);
                                    }

                                    break;
                            }
                        } else {
                            printf("Name or password incorrect");
                        }
                        break;


                }

                break;

        }
    } while (sel1 != 5);
    return 0;
}

