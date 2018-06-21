typedef struct{

int codigo;
char descripcion[51];
float importe;
unsigned int cantidad;
unsigned int activo;

}Producto;


Producto* producto_nuevo(void);
