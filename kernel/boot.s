# Flags en 0
.set FLAGS,    0

# Se identifica el bootloader con 0x1BADB002 
.set MAGIC,    0x1BADB002

.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot  # Habilitar multiboot

# Defino Longs
.long MAGIC
.long FLAGS
.long CHECKSUM

stackBottom:

# 512bytes es el maximo para el stack
.skip 512


# Se define el stack para la parte Top.Se empieza _start como funcion
stackTop:

.section .text
.global _start
.type _start, @function


_start:

  # Mover el puntero del stack a Top
	mov $stackTop, %esp

  # Llama a KERNEL_MAIN de kernel.c
	call KERNEL_MAIN

	cli


# Detiene el sistema en un loop
hltLoop:

	hlt
	jmp hltLoop

.size _start, . - _start





