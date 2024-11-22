.global _start
.section .text

_start:

.option arch, +zicsr

csrr t0, mhartid         # read hardware thread ID
bnez t0, _idle           # let default core to run and halt other cores

la sp, _initial_sp       # Setup stack pointer

entry_main:
# Prepare valid argc, argv and envp for main, just in case main uses them
    li a0, 0    # argc = 0
    li a1, 0    # argv = NULL
    li a2, 0    # envp = NULL
    call main

_idle:                  # Infinite loop
  wfi
  j _idle