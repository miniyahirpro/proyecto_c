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
#define NUM_TALLAS 4
//definicion de struct
struct Material{
	int id;
    char nombre[50];
    int cantidad;
    float precio;
} Material;

struct detalles_prenda
{
	int id;
	char talla[5];
    float tela;
    float hilo;
    float bies;
    float elastico;
    int botones;
    int etiquetas;
};
//variables globales
int num_materiales;
char tallas[NUM_TALLAS][3]={"CH", "M", "L", "XL"};
//delcaracion de funciones

//declaracion de menus
void menu();
void menu_almacenista();
void menu_contador();
void menu_usuario();
//declaracion funciones globales
void limpiarPantalla();
void pulseContinuar();
void titulo();
//funciones de menu principal
void inventario();
void instrucciones();
void inst_generales();
void inst_ingreso();
void inst_inventario();
void agregar_cliente();
void agregar_tipo_prenda();
void calcular_consumo_express();
void imprimir_reporte_express();
void prendas_predeterminadas();
void playera_simple();
void playera_polo();
void short_deportivo();
void pantalon_mezclilla();
void prendas_particulares();
void agregar_material();
void consumo_express();
void menu_usuario();
void menu_almacenista();
void menu_contador();
void usuario();
void calcular_consumo();
void proceso_calculo();
void ingreso_talla(int, char[]);
void editMaterial(int);
void printInventory();
//funcion principal
int main() {
    int tipo_usuario;
	setlocale(LC_CTYPE, "Spanish");
    //crear el text del inventario
    FILE *inventario;
    //abrir el archivo
    inventario = fopen("inventario.txt", "a");
    if (inventario == NULL) {
        printf("Error al crear el archivo.");
        return 1;
    }
	// abrir el archivo de estilos
	FILE *estilos_txt;
	estilos_txt = fopen("estilos.txt", "a");
	if (estilos_txt == NULL) {
		printf("Error al crear el archivo.");
		return 1;
	}
    usuario();
    return 0;
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

void pulseContinuar()
{
    printf("\nPulse cualquier tecla para continuar...\n");
    getch();
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
/*INICIA FUNCIONES PRINCIPALES*/
/*-------------------------------------------------------------------------
        FUNCION VERIFICAR USUARIO
--------------------------------------------------------------------------*/
void usuario()
{
    int opcion=0;
    int password=0;
    int error=0;
    while(opcion!=5)
    {
        titulo();
        printf("==================================\n");
        printf("      BIENVENIDO     \n");
        printf("==================================\n");
        printf("Bienvenido a Stitch Mate, por favor selecione su perfil:\n");
        printf("1. Admin\n");
        printf("2. Calculista\n");
        printf("3. Almacenista\n");
        printf("4. Contador\n");
        printf("5. Salir del programa\n");
        printf("\nElija una opcion (1-5): ");
        scanf("%i", &opcion);
        if (opcion>=1 && opcion <=4)
        {
            printf("Por favor, ingrese la contraseÃ±a: ");
            scanf("%i", &password);
        }

        switch(opcion)
        {
            case 1:
                if(password==123)
                {
                    limpiarPantalla();
                    menu();
                }
                else
                {
                    error=1;
                }
                break;
            case 2:
                if(password==123)
                {
                    limpiarPantalla();
                    menu_usuario();
                }
                else
                {
                    error=1;
                }
                break;
            case 3:
                if(password==123)
                {
                    limpiarPantalla();
                    menu_almacenista();
                }
                else
                {
                    error=1;
                }
                break;
            case 4:
                if(password==123)
                {
                    limpiarPantalla();
                    menu_contador();
                }
                else
                {
                    error=1;
                }
                break;
            case 5:
                break;
            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                pulseContinuar();
                limpiarPantalla();
        }
        if (error==1)
        {
            printf("ContraseÃ±a invalida. Por favor, elija una opcion valida.\n");
            pulseContinuar();
            limpiarPantalla();

        }

    }

}
/*-------------------------------------------------------------------------
        FUNCIONES DEL MENU DEL ADMIN
--------------------------------------------------------------------------*/

//menu principal
void menu()
{
    int opcion=0;
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
        //carga de opcion
        printf("\nElija una opcion (1-7): ");
        scanf("%i", &opcion);
        // Validar que la opcion elegida sea vÃƒÂ¡lida
        if (opcion < 1 || opcion > 7) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            pulseContinuar();
            limpiarPantalla();
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                agregar_cliente();
                break;
            case 2:
                agregar_tipo_prenda();
                break;
            case 3:
                break;
            case 4:
                inventario();
                break;
            case 5:
                calcular_consumo_express();
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
/*-------------------------------------------------------------------------
        FUNCION MENU DE USUARIO
--------------------------------------------------------------------------*/

void menu_usuario()
{
    int opcion=0;
    while (opcion != 4) {
        titulo();
        printf("\n");
        printf("==================================\n");
        printf("      BIENVENIDO      \n");
        printf("==================================\n");
        printf("1. Calcular consumo de material\n");
        printf("2. Consumo express\n");
        printf("3. Instrucciones\n");
        printf("4. Salir\n");
        //carga de opcion
        printf("\nElija una opcion (1-4): ");
        scanf("%i", &opcion);
        // Validar que la opcion elegida sea valida
        if (opcion < 1 || opcion > 4) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            pulseContinuar();
            limpiarPantalla();
            continue;
        }
        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                calcular_consumo();
                break;
            case 2:
                break;
            case 3:
                instrucciones();
                break;
            case 4:
                break;
        }
    }
}
/*-------------------------------------------------------------------------
        FUNCION MENU DE ALMACENISTA
--------------------------------------------------------------------------*/
void menu_almacenista()
{
    int opcion=0;
    while (opcion != 3) {
        titulo();
        printf("\n");
        printf("==================================\n");
        printf("      BIENVENIDO      \n");
        printf("==================================\n");
        printf("1. Inventario\n");
        printf("2. Instrucciones\n");
        printf("3. Salir\n");
        //carga de opcion
        printf("\nElija una opcion (1-3): ");
        scanf("%i", &opcion);
        // Validar que la opcion elegida sea valida
        if (opcion < 1 || opcion > 3) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            pulseContinuar();
            limpiarPantalla();
            continue;
        }
        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                inventario();
                break;
            case 2:
                instrucciones();
                break;
            case 3:
                break;

        }
    }
}
/*-------------------------------------------------------------------------
        FUNCION MENU CONTADOR
--------------------------------------------------------------------------*/
void menu_contador()
{
    int opcion=0;
    while (opcion != 4) {
        titulo();
        printf("\n");
        printf("==================================\n");
        printf("      BIENVENIDO      \n");
        printf("==================================\n");
        printf("1. Calcular consumo de material\n");
        printf("2. Inventario\n");
        printf("3. Instrucciones\n");
        printf("4. Salir\n");
        //carga de opcion
        printf("\nElija una opcion (1-4): ");
        scanf("%i", &opcion);
        // Validar que la opcion elegida sea valida
        if (opcion < 1 || opcion > 4) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            pulseContinuar();
            limpiarPantalla();
            continue;
        }
        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                calcular_consumo();
                break;
            case 2:
                inventario();
                break;
            case 3:
                instrucciones();
                break;
            case 4:
                break;
        }
    }
}
/*-------------------------------------------------------------------------
        FUNCION 1.- Agregar cliente.
--------------------------------------------------------------------------*/
void agregar_cliente()
{
    fflush(stdin);
    char nombre_cliente[50];
    limpiarPantalla();
    printf("Ingrese el nombre del cliente: ");
    gets(nombre_cliente);
    printf("Cliente agregado con exito.\n");
    pulseContinuar();
    limpiarPantalla();
}
/*-------------------------------------------------------------------------
        FUNCION 2.- Agregar tipo de prenda.
--------------------------------------------------------------------------*/
void agregar_tipo_prenda()
{
    //variables
    int id;
    int i;
    //mensjae bienvenida
    printf("====================================\n");
    printf("      NUEVO TIPO DE PRENDA       \n");
    printf("====================================\n");
    printf("Ingrese el id del tipo de prenda: ");
    scanf("%i", &id);
    //ingreso de todas las tallas
    for(i=0;i<NUM_TALLAS;i++)
    {
        ingreso_talla(id, tallas[i]);
    }
    pulseContinuar();
    limpiarPantalla();
}
void ingreso_talla(int id, char talla[3])
{
	// abrir el archivo de inventario
	FILE *estilos_txt;
	estilos_txt = fopen("estilos.txt", "a");
	if (estilos_txt == NULL) {
		printf("Error al crear el archivo.");
		return;
	}
    struct detalles_prenda prenda;
    printf("\tDATOS DE LA TALLA %s\n", talla);
    printf("Ingrese la cantidad de tela para la talla %s:", talla);
    scanf("%f", &prenda.tela);
    printf("Ingrese la cantidad de hilo para la talla %s:", talla);
    scanf("%f", &prenda.hilo);
    printf("Ingrese la cantidad de bies para la talla %s:", talla);
    scanf("%f", &prenda.bies);
    printf("Ingrese la cantidad de elastico para la talla %s:", talla);
    scanf("%f", &prenda.elastico);
    printf("Ingrese la cantidad de botones para la talla %s:", talla);
    scanf("%i", &prenda.botones);
    printf("Ingrese la cantidad de etiquetas para la talla %s:", talla);
    scanf("%f", &prenda.etiquetas);
	// Guardar en archivo
	fprintf(estilos_txt, "%d %s %.2f %.2f %.2f %.2f %d %d\n", id, talla, prenda.tela, prenda.hilo, prenda.bies, prenda.elastico, prenda.botones, prenda.etiquetas);

	fclose(estilos_txt);

	printf("Datos de la talla guardada con exito.\n\n");
}
/*-------------------------------------------------------------------------
        FUNCION 3.- Calcular consumo.
--------------------------------------------------------------------------*/
void calcular_consumo()
{
    int id;
    printf("====================================\n");
    printf("      CALCULAR CONSUMO       \n");
    printf("====================================\n");
    printf("Por favor, ingrese el ID del estilo de la prenda:");
    scanf("%i", &id);
    proceso_calculo();
    pulseContinuar();
    limpiarPantalla();
}
void proceso_calculo()
{
    printf("hola");
}


/*-------------------------------------------------------------------------
        FUNCION 4.- inventario.
--------------------------------------------------------------------------*/
//menu de opciones de inventario.
void inventario()
{
    int opcion = 0;
    int i;
    while (opcion != 4) {
        printf("\n");
        printf("====================================\n");
        printf("      INVENTARIO       \n");
        printf("====================================\n");
        printf("1. Agregar nuevo tipo de material\n");
        printf("2. Actualizar existencias\n");
		printf("3. Ver inventario\n");
        printf("4. Volver al menÃº principal\n");
        printf("\nElija una opcion (1-4): ");
        scanf("%i", &opcion);
        // Validar que la opcion elegida sea vÃ¡lida
        if (opcion < 1 || opcion > 4) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
				printf("Â¿Cuantos materiales desea añadir? Ingrese 0 para salir: ");
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
				printf("Â¿Cuantos materiales desea editar? Ingrese 0 para salir: ");
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
                break;
        }
        limpiarPantalla();
    }

}

int generateUniqueId() {
	int id;
	FILE *file;
	struct Material material;
	int found;

	do {
		found = 0;
		id = rand();

		file = fopen("inventario.txt", "a");
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
    pulseContinuar();
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
/*-------------------------------------------------------------------------
        FUNCION 5.- calcular consumo express
--------------------------------------------------------------------------*/
void calcular_consumo_express()
{
    int opcion=0;
    while (opcion != 3) {
        printf("\n");
        printf("====================================\n");
        printf("           CONSUMO EXPRESS           \n");
        printf("====================================\n");
        printf("1. Prendas predeterminadas.\n");
        printf("2. Prenda particular\n");
        printf("3. Volver al menÃº principal\n");
        printf("\nElija una opcion (1-3): ");
        scanf("%i", &opcion);

        // Validar que la opcion elegida sea vÃƒÂ¡lida
        if (opcion < 1 || opcion > 3) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                prendas_predeterminadas();
                break;
            case 2:
                /*prendas_particulares();*/
                break;
            case 3:

                break;
        }
    }
}
void prendas_predeterminadas()
{
    int opcion=0;
    while (opcion != 5) {
        printf("\n");
        printf("====================================\n");
        printf("           PRENDAS PARTICULARES           \n");
        printf("====================================\n");
        printf("1. Playera simple.\n");
        printf("2. Playera polo\n");
        printf("3. Short deportivo\n");
        printf("4. PantalÃ³n de mezclilla\n");
        printf("5. Volver al menu de opciones.\n");
        printf("\nElija una opcion (1-5): ");
        scanf("%i", &opcion);

        // Validar que la opcion elegida sea vÃƒÂ¡lida
        if (opcion < 1 || opcion > 5) {
            printf("Opcion invalida. Por favor, elija una opcion valida.\n");
            continue;
        }

        // Limpiar la pantalla
        limpiarPantalla();

        // Ejecutar la accion correspondiente a la opcion elegida
        switch(opcion) {
            case 1:
                playera_simple();
                break;
            case 2:
                playera_polo();
                break;
            case 3:
                short_deportivo();
            case 4:
                pantalon_mezclilla();
                break;
        }
    }
}
void playera_simple()
{
    //varibles
    int i;
    int numprendas[NUM_TALLAS];
    //varible del total del material
    struct detalles_prenda total={0, 0, 0, 0, 0, 0};
    //inicializacion datos de la prenda simple
    struct detalles_prenda simpleCH={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleM={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleL={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleXL={1.30, 110, .60, 0, 0, 1};

    //carga de datos
    for(i=0;i<NUM_TALLAS;i++)
    {
        printf("Ingrese el nÃºmero de prendas de la talla %s:", tallas[i]);
        scanf("%i", &numprendas[i]);
    }
    //sumatoria de todos los materiales
    total.tela=simpleCH.tela*numprendas[0]+simpleM.tela*numprendas[1]+simpleL.tela*numprendas[2]+simpleXL.tela*numprendas[3];
    total.hilo=simpleCH.hilo*numprendas[0]+simpleM.hilo*numprendas[1]+simpleL.hilo*numprendas[2]+simpleXL.hilo*numprendas[3];
    total.bies=simpleCH.bies*numprendas[0]+simpleM.bies*numprendas[1]+simpleL.bies*numprendas[2]+simpleXL.bies*numprendas[3];
    total.elastico=simpleCH.elastico*numprendas[0]+simpleM.elastico*numprendas[1]+simpleL.elastico*numprendas[2]+simpleXL.elastico*numprendas[3];
    total.botones=simpleCH.botones*numprendas[0]+simpleM.botones*numprendas[1]+simpleL.botones*numprendas[2]+simpleXL.botones*numprendas[3];
    total.etiquetas=simpleCH.etiquetas*numprendas[0]+simpleM.etiquetas*numprendas[1]+simpleL.etiquetas*numprendas[2]+simpleXL.etiquetas*numprendas[3];
    imprimir_reporte_express(total);
    pulseContinuar();

}
void playera_polo()
{
     //varibles
    int i;
    int numprendas[NUM_TALLAS];
    //varible del total del material
    struct detalles_prenda total={0, 0, 0, 0, 0, 0};
    //inicializacion datos de la prenda simple
    struct detalles_prenda simpleCH={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleM={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleL={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleXL={1.30, 110, .60, 0, 0, 1};

    //carga de datos
    for(i=0;i<NUM_TALLAS;i++)
    {
        printf("Ingrese el nÃºmero de prendas de la talla %s:", tallas[i]);
        scanf("%i", &numprendas[i]);
    }
    //sumatoria de todos los materiales
    total.tela=simpleCH.tela*numprendas[0]+simpleM.tela*numprendas[1]+simpleL.tela*numprendas[2]+simpleXL.tela*numprendas[3];
    total.hilo=simpleCH.hilo*numprendas[0]+simpleM.hilo*numprendas[1]+simpleL.hilo*numprendas[2]+simpleXL.hilo*numprendas[3];
    total.bies=simpleCH.bies*numprendas[0]+simpleM.bies*numprendas[1]+simpleL.bies*numprendas[2]+simpleXL.bies*numprendas[3];
    total.elastico=simpleCH.elastico*numprendas[0]+simpleM.elastico*numprendas[1]+simpleL.elastico*numprendas[2]+simpleXL.elastico*numprendas[3];
    total.botones=simpleCH.botones*numprendas[0]+simpleM.botones*numprendas[1]+simpleL.botones*numprendas[2]+simpleXL.botones*numprendas[3];
    total.etiquetas=simpleCH.etiquetas*numprendas[0]+simpleM.etiquetas*numprendas[1]+simpleL.etiquetas*numprendas[2]+simpleXL.etiquetas*numprendas[3];
    imprimir_reporte_express(total);
    pulseContinuar();
}

void short_deportivo()
{
     //varibles
    int i;
    int numprendas[NUM_TALLAS];
    //varible del total del material
    struct detalles_prenda total={0, 0, 0, 0, 0, 0};
    //inicializacion datos de la prenda simple
    struct detalles_prenda simpleCH={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleM={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleL={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleXL={1.30, 110, .60, 0, 0, 1};

    //carga de datos
    for(i=0;i<NUM_TALLAS;i++)
    {
        printf("Ingrese el nÃºmero de prendas de la talla %s:", tallas[i]);
        scanf("%i", &numprendas[i]);
    }
    //sumatoria de todos los materiales
    total.tela=simpleCH.tela*numprendas[0]+simpleM.tela*numprendas[1]+simpleL.tela*numprendas[2]+simpleXL.tela*numprendas[3];
    total.hilo=simpleCH.hilo*numprendas[0]+simpleM.hilo*numprendas[1]+simpleL.hilo*numprendas[2]+simpleXL.hilo*numprendas[3];
    total.bies=simpleCH.bies*numprendas[0]+simpleM.bies*numprendas[1]+simpleL.bies*numprendas[2]+simpleXL.bies*numprendas[3];
    total.elastico=simpleCH.elastico*numprendas[0]+simpleM.elastico*numprendas[1]+simpleL.elastico*numprendas[2]+simpleXL.elastico*numprendas[3];
    total.botones=simpleCH.botones*numprendas[0]+simpleM.botones*numprendas[1]+simpleL.botones*numprendas[2]+simpleXL.botones*numprendas[3];
    total.etiquetas=simpleCH.etiquetas*numprendas[0]+simpleM.etiquetas*numprendas[1]+simpleL.etiquetas*numprendas[2]+simpleXL.etiquetas*numprendas[3];
    imprimir_reporte_express(total);
    pulseContinuar();
}
void pantalon_mezclilla()
{
     //varibles
    int i;
    int numprendas[NUM_TALLAS];
    //varible del total del material
    struct detalles_prenda total={0, 0, 0, 0, 0, 0};
    //inicializacion datos de la prenda simple
    struct detalles_prenda simpleCH={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleM={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleL={1.30, 110, .60, 0, 0, 1};
    struct detalles_prenda simpleXL={1.30, 110, .60, 0, 0, 1};

    //carga de datos
    for(i=0;i<NUM_TALLAS;i++)
    {
        printf("Ingrese el nÃºmero de prendas de la talla %s:", tallas[i]);
        scanf("%i", &numprendas[i]);
    }
    //sumatoria de todos los materiales
    total.tela=simpleCH.tela*numprendas[0]+simpleM.tela*numprendas[1]+simpleL.tela*numprendas[2]+simpleXL.tela*numprendas[3];
    total.hilo=simpleCH.hilo*numprendas[0]+simpleM.hilo*numprendas[1]+simpleL.hilo*numprendas[2]+simpleXL.hilo*numprendas[3];
    total.bies=simpleCH.bies*numprendas[0]+simpleM.bies*numprendas[1]+simpleL.bies*numprendas[2]+simpleXL.bies*numprendas[3];
    total.elastico=simpleCH.elastico*numprendas[0]+simpleM.elastico*numprendas[1]+simpleL.elastico*numprendas[2]+simpleXL.elastico*numprendas[3];
    total.botones=simpleCH.botones*numprendas[0]+simpleM.botones*numprendas[1]+simpleL.botones*numprendas[2]+simpleXL.botones*numprendas[3];
    total.etiquetas=simpleCH.etiquetas*numprendas[0]+simpleM.etiquetas*numprendas[1]+simpleL.etiquetas*numprendas[2]+simpleXL.etiquetas*numprendas[3];
    imprimir_reporte_express(total);
    pulseContinuar();
}
void prendas_particulares()
{

}
void imprimir_reporte_express(struct detalles_prenda total)
{
    printf("====================================\n");
    printf("           CONSUMO TOTAL           \n");
    printf("====================================\n");
    printf("1. Cantidad total de tela: %.2f\n", total.tela);
    printf("1. Cantidad total de hilo: %.2f\n", total.hilo);
    printf("1. Cantidad total de bies: %.2f\n", total.bies);
    printf("1. Cantidad total de elastico: %.2f\n", total.elastico);
    printf("1. Cantidad total de botones: %.2f\n", total.botones);
    printf("1. Cantidad total de etiquetas: %.2f\n", total.etiquetas);
}
/*-------------------------------------------------------------------------
        FUNCION 6.- INSTRUCCIOINES.
--------------------------------------------------------------------------*/


//menu de instrucciones opcion 6
void instrucciones()
{
    int opcion = 0;
    while (opcion != 4) {
        printf("\n");
        printf("====================================\n");
        printf("           MENU DE AYUDA            \n");
        printf("====================================\n");
        printf("1. Instrucciones de ingreso de datos\n");
        printf("2. Instrucciones de uso de inventario\n");
        printf("3. Instrucciones generales\n");
        printf("4. Volver al menÃº principal\n");
        printf("\nElija una opcion (1-4): ");
        scanf("%i", &opcion);

        // Validar que la opcion elegida sea vÃƒÂ¡lida
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
                break;
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
    printf("Se ingresa el ID del tipo de prenda, luego se ingresa la cantidad por talla para\nque el programa retorne el material necesario para esa producciÃ³n.\n");
    printf("Consumo express\n");
    printf("En esta secciÃ³n se elige un tipo de prenda predeterminado por el programa, o en su\n defecto algun tipo de de prenda especifica del usuario.");
}
void inst_generales()
{
    printf("====================================\n");
    printf("           INSTRUCCIONES GENERALES            \n");
    printf("====================================\n");
    printf("1.- Para seleccionar una opciÃ³n Ãºnicamente se necesita ingresar el nÃºmero de opciÃ³n asociada.\n");
    printf("2.-Puede volver al menu principal desde cualquier menu seleccionando la opcion asociada.\n ");
    printf("3.-Para salir de la aplicaciÃ³n, se debe seleccionar la opciÃ³n 7 del menÃº principal.");
}
void inst_inventario()
{
    printf("====================================\n");
    printf("           INSTRUCCIONES DE INVENTARIO            \n");
    printf("====================================\n");
    printf("El inventario se encarga de la gestiÃ³n de material disponible, por lo cual existen \nvarias opciones para el uso correcto de esta secciÃ³n.");
    printf("Agregar nuevo tipo de material\n");
    printf("Se ingresa cuantos materiales se quieren registrar, luego se pide el nombre y cantidad de cada material nuevo.\n");
    printf("Actualizar existencias\n");
    printf("Apartado para modificar el numero de existencias totales de algun tipo de material,\nse debe especificar el ID del material y el nuevo nÃºmero de existencias.");
}
