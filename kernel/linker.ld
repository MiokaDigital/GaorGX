/* El siguiente codigo solo declara las secciones que debe tener en cuenta para funcionar, se pueden agregar mas de ser necesario 
 Se pueden formar otras secciones por el compilador, en ese caso se agregan al linker*/
ENTRY(_start)

SECTIONS
{
	
	. = 1M;
    /* Espacio de 1MiB para cargar el bootloader */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	/* Se carga primero el  header del multiboot y no el .txt para que no de      errores con el formato del archivo */
	}
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata) /*Solo lectura*/
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Stack y datos inicializados*/
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}
