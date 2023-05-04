/*Proyeto: Calculo de material en textiles

Compilador: dev-c++ 5.11

Autores: Basto Manuel, Canche Saul, Malagon Alan, Uch Luis

versión: 1.0

fecha:

*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//definicion de struct
struct Material{
    char nombre[50];
    int cantidad;
    float precio;
} Material;
//declaracion de funciones

void menu();
void limpiarPantalla();
void inventario();
void instrucciones();
void agregar_material();
void titulo();

//función principal
int main() {
    //crear el text de los estilos
    FILE *inventario;
    //abrir el archivo
    inventario = fopen("inventario.txt", "a");
    if (inventario == NULL) {
        printf("Error al crear el archivo.");
        return 1;
    }
    titulo();
    menu();
}
void titulo()
{
    printf("   _____             _       \n");
    printf("  / ____|           (_)      \n");
    printf(" | |     _ __   __ _ _ _ __  \n");
    printf(" | |    | '_ \\ / _` | | '_ \\ \n");
    printf(" | |____| | | | (_| | | | | |\n");
    printf("  \\_____|_| |_|\\__, |_|_| |_|\n");
    printf("                 __/ |       \n");
    printf("                |___/        \n");
    printf("\n");
    printf("            T E X T I L E S   \n");
}
void agregar_material() {
    // abrir el archivo de inventario
    FILE *inventario_txt;
    inventario_txt = fopen("inventario.txt", "a");
    if (inventario_txt == NULL) {
        printf("Error al crear el archivo.");
        return;
    }

    // obtener los datos del nuevo material
    struct Material material;

    printf("Ingrese el nombre del material: ");
    scanf("%s", material.nombre);

    printf("Ingrese la cantidad de %s: ", material.nombre);
    scanf("%d", &material.cantidad);

    printf("Ingrese el precio unitario de %s: ", material.nombre);
    scanf("%f", &material.precio);

    // agregar el material al archivo de inventario
    fprintf(inventario_txt, "%s;%d;%.2f\n", material.nombre, material.cantidad, material.precio);

    printf("Material agregado con éxito.\n");

    // cerrar el archivo de inventario
    fclose(inventario_txt);
}


void inventario()
{
    int opcion = 0;
    char opcionStr[10];
    while (opcion != 3) {
        printf("\n");
        printf("====================================\n");
        printf("      INVENTARIO       \n");
        printf("====================================\n");
        printf("1. Agregar nuevo tipo de material\n");
        printf("2. Actualizar existencias\n");
        printf("3. Volver al menú principal\n");
        printf("\nElija una opcion (1-3): ");

        // Leer la opcion elegida
        fgets(opcionStr, sizeof(opcionStr), stdin);
        sscanf(opcionStr, "%d", &opcion);

        // Validar que la opcion elegida sea válida
        if (opcion < 1 || opcion > 3) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();
        printf("Bienvenido!\n\n");

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                agregar_material();
                break;
            case 2:
                //actualizar_existencia();
                break;
            case 3:
                //salida();
                break;
        }
    }

}

void menu()
{
    int opcion = 0;
    char opcionStr[10];
    while (opcion != 7) {
        printf("\n");
        printf("==================================\n");
        printf("      BIENVENIDO     \n");
        printf("==================================\n");
        printf("1. Agregar cliente\n");
        printf("2. Agregar tipo de prenda\n");
        printf("3. Calcular consumo de material\n");
        printf("4. Inventario\n");
        printf("5. Consumo express\n");
        printf("6. Instrucciones\n");
        printf("7. Salir\n");
        printf("\nElija una opcion (1-7): ");

        // Leer la opcion elegida
        fgets(opcionStr, sizeof(opcionStr), stdin);
        sscanf(opcionStr, "%d", &opcion);

        // Validar que la opcion elegida sea válida
        if (opcion < 1 || opcion > 7) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                inventario();
                break;
            case 5:
                break;
            case 6:
                instrucciones();
                break;
            case 7:
                break;
        }
    }


}
void limpiarPantalla() {
    // Se utiliza el comando 'clear' en sistemas tipo Unix, y 'cls' en sistemas tipo Windows
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void instrucciones()
{
    int opcion = 0;
    char opcionStr[10];
    while (opcion != 4) {
        printf("\n");
        printf("====================================\n");
        printf("           MENU DE AYUDA            \n");
        printf("====================================\n");
        printf("1. Instrucciones de ingreso de datos\n");
        printf("2. Instrucciones de uso de inventario\n");
        printf("3. Instrucciones generales\n");
        printf("4. Salir\n");
        printf("\nElija una opcion (1-4): ");

        // Leer la opcion elegida
        fgets(opcionStr, sizeof(opcionStr), stdin);
        sscanf(opcionStr, "%d", &opcion);

        // Validar que la opcion elegida sea válida
        if (opcion < 1 || opcion > 4) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla y mostrar el mensaje de bienvenida
        limpiarPantalla();
        printf("Bienvenido al menu de ayuda!\n\n");

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                printf("Instrucciones de ingreso de datos:\n");
                printf("1. Ingrese el nombre del cliente.\n");
                printf("2. Ingrese el tipo de prenda.\n");
                printf("3. Ingrese la cantidad de material utilizado.\n");
                break;
            case 2:
                printf("Instrucciones de uso de inventario:\n");
                printf("1. Ingrese el nombre del material.\n");
                printf("2. Ingrese la cantidad de material a agregar o retirar.\n");
                printf("3. Confirme la operacion.\n");
                break;
            case 3:
                printf("Instrucciones generales:\n");
                printf("1. Todas las operaciones en este programa son reversibles.\n");
                printf("2. Se recomienda revisar el inventario antes de agregar nuevos tipos de material.\n");
                break;
            case 4:
                printf("Hasta luego!\n");
                break;
        }
    }
}


