ENTRY(boot)

SECTIONS {
    /* base memory address */
    . = 0x80200000;

    /* code of the program */
    /* entry point of the kernel */
    .text :{
        KEEP(*(.text.boot));
        *(.text .text.*)
    }

    /* read only data */
    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);
    }

    /* read / write data */
    .data : ALIGN(4) {
        *(.data .data.*);
    }

    .bss : ALIGN(4) {
        __bss = .;
        *(.bss .bss.* .sbss .sbss.*);
        __bss_end = .;
    }

    /* 128 kb kernel stack */
    . = ALIGN(4);
    . += 128 * 1024; /* 128 KB */
    __stack_top = .;
}