#Compilar boot.s 
as --32 boot.s -o boot.o

#Compilar kernel.c
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#Linkear los objetos de kernel y de boot
ld -m elf_i386 -T linker.ld kernel.o boot.o -o GaorgOS.bin -nostdlib

#Definir GaorgOS.bin como kernel
grub-file --is-x86-multiboot GaorgOS.bin

#Crear imagen iso y directorio de boot
mkdir -p Sistema/boot/grub
cp GaorgOS.bin Sistema/boot/GaorgOS.bin
cp grub.cfg Sistema/boot/grub/grub.cfg
grub-mkrescue -o GaorgOS.iso Sistema

