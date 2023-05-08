/*Proyeto: Calculo de material en textiles

Compilador: dev-c++ 5.11

Autores: Basto Manuel, Canche Saul, Malagon Alan, Uch Luis

version: 1.4

fecha:

*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>
#include<conio.h>
//definicion de struct
struct Material{
	int id;
    char nombre[50];
    int cantidad;
    float precio;
} Material;

void menu();
void limpiarPantalla();
void inventario();
void instrucciones();
void agregar_material();
void titulo();
void consumo_express();

//funcion principal
int main() {
	setlocale(LC_CTYPE, "Spanish");
    //crear el text de los estilos
    FILE *inventario;
    //abrir el archivo
    inventario = fopen("inventario.txt", "a");
    if (inventario == NULL) {
        printf("Error al crear el archivo.");
        return 1;
    }
    menu();
}

void menu()
{
    int opcion = 0;
    char opcionStr[10];
    while (opcion != 7) {
        titulo();
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

        // Validar que la opcion elegida sea vÃ¡lida
        if (opcion < 1 || opcion > 7) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            pulseConitnuar();
            limpiarPantalla();
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
                //inventario apartado
                inventario();
                break;
            case 5:
                break;
            case 6:
                //isntrucciones, partado listo
                instrucciones();
                break;
            case 7:
                break;
        }
    }


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
int generateUniqueId() {
	int id;
	FILE *file;
	struct Material material;
	int found;

	do {
		found = 0;
		id = rand();

		file = fopen("inventario.txt", "r");
		if (file != NULL) {
			while (fscanf(file, "%d;%[^;];%d;%f\n", &material.id, material.nombre, &material.cantidad, &material.precio) == 4) {
				if (material.id == id) {
					found = 1;
					break;
				}
			}
			fclose(file);
		}
	} while (found);

	return id;
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

	material.id = generateUniqueId();

	printf("Ingrese el nombre del material: ");
	scanf("%s", material.nombre);

	printf("Ingrese la cantidad de %s: ", material.nombre);
	scanf("%d", &material.cantidad);

	printf("Ingrese el precio unitario de %s: ", material.nombre);
	scanf("%f", &material.precio);

	// agregar el material al archivo de inventario
	fprintf(inventario_txt, "%d;%s;%d;%.2f\n", material.id, material.nombre, material.cantidad, material.precio);

	printf("Material agregado con exito.\n");

	// cerrar el archivo de inventario
	fclose(inventario_txt);
}
void printInventory() {
    FILE *file;
    struct Material material;

    file = fopen("inventario.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("%-10s %-50s %-10s %-10s\n", "ID", "Nombre", "Cantidad", "Precio");
    while (fscanf(file, "%d;%[^;];%d;%f\n", &material.id, material.nombre, &material.cantidad, &material.precio) == 4) {
        printf("%-10d %-50s %-10d %-10.2f\n", material.id, material.nombre, material.cantidad, material.precio);
    }

    fclose(file);
    pulseConitnuar();
    limpiarPantalla();
}

void editMaterial(int id) {
	FILE *file;
	FILE *tempFile;
	struct Material material;
	int found = 0;

	file = fopen("inventario.txt", "r");
	if (file == NULL) {
		printf("Error al abrir archivo\n");
		exit(1);
	}

	tempFile = tmpfile();
	if (tempFile == NULL) {
		printf("Error creando archivo temporal\n");
		exit(1);
	}

	while (fscanf(file, "%d;%[^;];%d;%f\n", &material.id, material.nombre, &material.cantidad, &material.precio) == 4) {
		if (material.id == id) {
			found = 1;

			printf("Editando material con ID %d\n", id);

			printf("Nombre Actual: %s\n", material.nombre);
			printf("Ingrese Nuevo nombre: ");
			scanf("%s", material.nombre);

			printf("Cantidad Actual: %d\n", material.cantidad);
			printf("Ingrese Nueva cantidad: ");
			scanf("%d", &material.cantidad);

			printf("Precio Actual: %.2f\n", material.precio);
			printf("Ingrese Precio Nuevo: ");
			scanf("%f", &material.precio);
		}
		fprintf(tempFile, "%d;%s;%d;%.2f\n", material.id, material.nombre, material.cantidad, material.precio);
	}

	fclose(file);

	if (!found) {
		printf("Material con ID %d no encontrado\n", id);
		return;
	}

	file = fopen("inventario.txt", "w");
	if (file == NULL) {
		printf("Error al abrir archivo\n");
		exit(1);
	}

	rewind(tempFile);
	while (fscanf(tempFile, "%d;%[^;];%d;%f\n", &material.id, material.nombre, &material.cantidad, &material.precio) == 4) {
		fprintf(file, "%d;%s;%d;%.2f\n", material.id, material.nombre, material.cantidad, material.precio);
	}

	fclose(file);
}
int num_materiales;
//menu de opciones de inventario.
void inventario()
{
    int opcion = 0;
    int i;
    char opcionStr[10];
    while (opcion != 4) {
        printf("\n");
        printf("====================================\n");
        printf("      INVENTARIO       \n");
        printf("====================================\n");
        printf("1. Agregar nuevo tipo de material\n");
        printf("2. Actualizar existencias\n");
		printf("3. Ver inventario\n");
        printf("4. Volver al menú principal\n");
        printf("\nElija una opcion (1-4): ");

        // Leer la opcion elegida
        fgets(opcionStr, sizeof(opcionStr), stdin);
        sscanf(opcionStr, "%d", &opcion);

        // Validar que la opcion elegida sea válida
        if (opcion < 1 || opcion > 4) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();
        printf("Bienvenido!\n\n");

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
				printf("¿Cuantos materiales desea añadir? Ingrese 0 para salir: ");
				scanf("%d", &num_materiales);
				// clear input buffer
				while (getchar() != '\n');
				for (i = 0; i < num_materiales; i++) {
				    //retorno al menu de opciones
                    limpiarPantalla();
					agregar_material();
				};
				break;
            case 2:
                //actualizar_existencia();
				printf("¿Cuantos materiales desea editar? Ingrese 0 para salir: ");
				scanf("%d", &num_materiales);
				// clear input buffer
				while (getchar() != '\n');
				for (i = 0; i < num_materiales; i++) {
					int id;

					printf("Ingresa el id del material a editar: ");
					scanf("%d", &id);

					editMaterial(id);
				};
				break;
			case 3:
				//Ver inventario
				printInventory();
				break;
            case 4:
                //salida();
				volver_menu();
        }
    }

}

//funciones de ayuda
void limpiarPantalla() {
    // Se utiliza el comando 'clear' en sistemas tipo Unix, y 'cls' en sistemas tipo Windows
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pulseConitnuar()
{
    printf("\nPulse cualquier tecla para continuar...\n");
    getch();
}

//menu de instrucciones opcion 6
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
        printf("4. Volver al menú principal\n");
        printf("\nElija una opcion (1-4): ");

        // Leer la opcion elegida
        fgets(opcionStr, sizeof(opcionStr), stdin);
        sscanf(opcionStr, "%d", &opcion);

        // Validar que la opcion elegida sea vÃ¡lida
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
                inst_ingreso();
                break;
            case 2:
                inst_inventario();
                break;
            case 3:
                inst_generales();
                break;
            case 4:
                volver_menu();
        }
    }
}
//funciones de explicacion de instrucciones
void inst_ingreso()
{
    printf("====================================\n");
    printf("           INSTRUCCIONES DE USO            \n");
    printf("====================================\n");
    printf("Instrucciones por apartado del programa.\n");
    printf("Agregar cliente\n");
    printf("Se ingresa el nombre del cliente para asociarlo a diferentes estilos de prendas.\n ");
    printf("Agregar estilo\n");
    printf("Se ingresa un id asociado al tipo de prenda para luego asociarlo a un cliente.\nAl final se piden las especificaciones por cada talla.");
    printf("Calcular consumo\n");
    printf("Se ingresa el ID del tipo de prenda, luego se ingresa la cantidad por talla para\nque el programa retorne el material necesario para esa producción.\n");
    printf("Consumo express\n");
    printf("En esta sección se elige un tipo de prenda predeterminado por el programa, o en su\n defecto algun tipo de de prenda especifica del usuario.");
}
void inst_generales()
{
    printf("====================================\n");
    printf("           INSTRUCCIONES GENERALES            \n");
    printf("====================================\n");
    printf("1.- Para seleccionar una opción únicamente se necesita ingresar el número de opción asociada.\n");
    printf("2.-Puede volver al menu principal desde cualquier menú seleccionando la opcion asociada.\n ");
    printf("3.-Para salir de la aplicación, se debe seleccionar la opción 7 del menú principal.");
}
void inst_inventario()
{
    printf("====================================\n");
    printf("           INSTRUCCIONES DE INVENTARIO            \n");
    printf("====================================\n");
    printf("El inventario se encarga de la gestión de material disponible, por lo cual existen \nvarias opciones para el uso correcto de esta sección.");
    printf("Agregar nuevo tipo de material\n");
    printf("Se ingresa cuantos materiales se quieren registrar, luego se pide el nombre y cantidad de cada material nuevo.\n");
    printf("Actualizar existencias\n");
    printf("Apartado para modificar el numero de existencias totales de algun tipo de material,\nse debe especificar el ID del material y el nuevo número de existencias.");
}
void volver_menu()
{
    limpiarPantalla();
    menu();
}
void consumo_express(){
	//definición de variables
	int opcion=0,i;
	char opcionstr[10];

	while (opcion != 4){
		printf("  ====================================\n");
    		printf("        Consumo express       \n");
    		printf("  ====================================\n");
    		printf("  1. Usar un estilo de prenda predeterminado \n");
    		printf("  2. Calcular el consumo de una prenda particular \n");
		printf("  3. Ver instrucciones de uso \n");
    		printf("  4. salir\n");
    		printf("  \nElija una opcion (1-4):  ");

    	fgets(opcionstr, sizeof(opcionstr), stdin);
        sscanf(opcionstr, "%d", &opcion);

        if (opcion < 1 || opcion > 4) {
            printf("  Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        limpiarPantalla();
        printf("Bienvenido!\n\n");

        switch (opcion){
        	case 1:
        		printf(" Las prendas predeterminadas son: \n");
        		printf("\n  opción 1: \n  CAMISETA BÁSICA \n");
        		printf("    __   __" );
        		printf("\n  /|  `-´  |\\ " );
        		printf("\n /_|       |_\\ " );
        		printf("\n   |       |" );
        		printf("\n   |       |" );
        		printf("\n   |_______|\n" );
        		printf("\n Tamaños: Chica, mediana y grande \n ");


		}
	}

}


