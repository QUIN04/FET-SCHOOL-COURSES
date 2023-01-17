// C Structure of the GDT Descriptor.
struct gdtr {
u16 limite;
u32 base;
} __attribute__ ((packed));

// C Structure of the GDT Entry
struct gdtdesc {
u16 lim0_15;
u16 base0_15;
u8 base16_23;
u8 acces;
u8 lim16_19:4;
u8 other:4;
u8 base24_31;
} __attribute__ ((packed));
//We need now to define our GDT in memory and finally load it using the GDTR registry.
//We are going to store our GDT at the address:
#define GDTBASE 0x00000800
//The function init_gdt_desc in x86.cc initialize a gdt segment descriptor.
void init_gdt_desc(u32 base, u32 limite, u8 acces, u8 other, struct gdtdesc *desc)
{
desc->lim0_15 = (limite & 0xffff);
desc->base0_15 = (base & 0xffff);
desc->base16_23 = (base & 0xff0000) >> 16;
desc->acces = acces;
desc->lim16_19 = (limite & 0xf0000) >> 16;
desc->other = (other & 0xf);
desc->base24_31 = (base & 0xff000000) >> 24;
return;
}
//And the function init_gdt initialize the GDT, some parts of the below function will be explained later and are used for multitasking.
void init_gdt(void)
{
default_tss.debug_flag = 0x00;
default_tss.io_map = 0x00;
default_tss.esp0 = 0x1FFF0;
default_tss.ss0 = 0x18;
/* initialize gdt segments */
init_gdt_desc(0x0, 0x0, 0x0, 0x0, &kgdt[0]);
init_gdt_desc(0x0, 0xFFFFF, 0x9B, 0x0D, &kgdt[1]); /* code */
init_gdt_desc(0x0, 0xFFFFF, 0x93, 0x0D, &kgdt[2]); /* data */
init_gdt_desc(0x0, 0x0, 0x97, 0x0D, &kgdt[3]); /* stack */
init_gdt_desc(0x0, 0xFFFFF, 0xFF, 0x0D, &kgdt[4]); /* ucode */
init_gdt_desc(0x0, 0xFFFFF, 0xF3, 0x0D, &kgdt[5]); /* udata */
init_gdt_desc(0x0, 0x0, 0xF7, 0x0D, &kgdt[6]); /* ustack */
init_gdt_desc((u32) & default_tss, 0x67, 0xE9, 0x00, &kgdt[7]); /* descripteur
de tss */
/* initialize the gdtr structure */
kgdtr.limite = GDTSIZE * 8;
kgdtr.base = GDTBASE;
/* copy the gdtr to its memory area */
memcpy((char *) kgdtr.base, (char *) kgdt, kgdtr.limite);
/* load the gdtr registry */
asm("lgdtl (kgdtr)");
/* initiliaz the segments */
asm(" movw $0x10, %ax \n \
movw %ax, %ds \n \
movw %ax, %es \n \
movw %ax, %fs \n \
movw %ax, %gs \n \
ljmp $0x08, $next \n \
next: \n");
}