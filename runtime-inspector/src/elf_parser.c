#include <stdio.h>
#include <elf.h>
#include "elf_parser.h"

void analyze_elf(const char* path) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        perror("Cannot open ELF file");
        return;
    }

    Elf64_Ehdr header;
    fread(&header, 1, sizeof(header), f);

    printf("ELF Entry Point: 0x%lx\n", header.e_entry);
    printf("Machine: %d\n", header.e_machine);
    printf("Sections: %d\n", header.e_shnum);

    fclose(f);
}