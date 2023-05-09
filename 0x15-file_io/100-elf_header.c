#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void print_class(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void clode_elf(int elf);

/**
 * check_elf - to check file
 * @e_ident: ptr
 */
void check_elf(unsigned char *e_ident)
{
	int dex;

	for (dex = 0; dex < 4; dex++)
	{
		if (e_ident[dex] != 127 &&
				e_ident[dex] != 'E' &&
				e_ident[dex] != 'L' &&
				e_ident[dex] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - print mag num
 * @e_ident: ptr
 */
void print_magic(unsigned char *e_ident)
{
	int dex;

	printf("Magic: ");
	for (dex = 0; dex < EI_NIDENT; dex++)
	{
		printf("%02x", e_ident[dex]);
		if (dex == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_data - print data
 * @e_ident: ptr
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:    ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_class - print class of elf
 * @e_ident: ptr
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_version - print ver of elf
 * @e_ident: ptr
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("(current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabi - print os/abi
 * @e_ident: ptr
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - print ABI
 * @e_ident: ptr
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI version: %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * print_type - print type of elf
 * @e_type: type
 * @e_ident: ptr
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("type: ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (none)\n");
			break;
		case ET_REL:
			printf("REL (relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - print ent point
 * @e_entry: address
 * @e_ident: ptr
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - close elf
 * @elf: desc of elf
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: cant close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - to disp the info
 * @argc: the num of args
 * @argv: arr
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);
free(header);
close_elf(o);
return (0);
}
