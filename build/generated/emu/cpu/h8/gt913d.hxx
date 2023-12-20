const gt913_disassembler::disasm_entry gt913_disassembler::disasm_entries[] = {
	{ 0, 0x00000000, 0x0000ffff, 0x0000, 0x0000, "nop", DASM_none, DASM_none, 2 }, // inherited
	{ 0, 0x00000100, 0x0000ffff, 0x0000, 0x0000, "sleep", DASM_none, DASM_none, 2 }, // inherited
	{ 0, 0x00000240, 0x0000fff0, 0x0000, 0x0000, "stc", DASM_ccr, DASM_r8l, 2 }, // inherited
	{ 0, 0x00000340, 0x0000fff0, 0x0000, 0x0000, "ldc", DASM_r8l, DASM_ccr, 2 }, // inherited
	{ 0, 0x00000380, 0x0000fff0, 0x0000, 0x0000, "ldbank", DASM_r8l, DASM_bankl, 2 }, // needed
	{ 0, 0x000003c0, 0x0000fff0, 0x0000, 0x0000, "ldbank", DASM_r8l, DASM_bankh, 2 }, // needed
	{ 0, 0x00000400, 0x0000ff00, 0x0000, 0x0000, "orc", DASM_imm8, DASM_ccr, 2 }, // inherited
	{ 0, 0x00000500, 0x0000ff00, 0x0000, 0x0000, "xorc", DASM_imm8, DASM_ccr, 2 }, // inherited
	{ 0, 0x00000600, 0x0000ff00, 0x0000, 0x0000, "andc", DASM_imm8, DASM_ccr, 2 }, // inherited
	{ 0, 0x00000740, 0x0000ffc0, 0x0000, 0x0000, "ldc", DASM_imm6l, DASM_ccr, 2 }, // needed
	{ 0, 0x00000780, 0x0000ffc0, 0x0000, 0x0000, "ldbank", DASM_imm6l, DASM_bankl, 2 }, // needed
	{ 0, 0x000007c0, 0x0000ffc0, 0x0000, 0x0000, "ldbank", DASM_imm6l, DASM_bankh, 2 }, // needed
	{ 0, 0x00000800, 0x0000ff00, 0x0000, 0x0000, "add.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00000900, 0x0000ff00, 0x0000, 0x0000, "add.w", DASM_r16h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00000a00, 0x0000fff0, 0x0000, 0x0000, "inc.b", DASM_one, DASM_r8l, 2 }, // inherited
	{ 0, 0x00000b00, 0x0000fff8, 0x0000, 0x0000, "adds.l", DASM_one, DASM_r16l, 2 }, // inherited
	{ 0, 0x00000b80, 0x0000fff8, 0x0000, 0x0000, "adds.l", DASM_two, DASM_r16l, 2 }, // inherited
	{ 0, 0x00000c00, 0x0000ff00, 0x0000, 0x0000, "mov.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00000d00, 0x0000ff00, 0x0000, 0x0000, "mov.w", DASM_r16h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00000e00, 0x0000ff00, 0x0000, 0x0000, "addx.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00000f00, 0x0000ff00, 0x0000, 0x0000, "mulxu.b", DASM_r8h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00001000, 0x0000fff0, 0x0000, 0x0000, "shll.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001080, 0x0000fff0, 0x0000, 0x0000, "shal.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001100, 0x0000fff0, 0x0000, 0x0000, "shlr.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001180, 0x0000fff0, 0x0000, 0x0000, "shar.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001200, 0x0000fff0, 0x0000, 0x0000, "rotxl.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001280, 0x0000fff0, 0x0000, 0x0000, "rotl.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001300, 0x0000fff0, 0x0000, 0x0000, "rotxr.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001380, 0x0000fff0, 0x0000, 0x0000, "rotr.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001400, 0x0000ff00, 0x0000, 0x0000, "or.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001500, 0x0000ff00, 0x0000, 0x0000, "xor.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001600, 0x0000ff00, 0x0000, 0x0000, "and.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001700, 0x0000fff0, 0x0000, 0x0000, "not.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001780, 0x0000fff0, 0x0000, 0x0000, "neg.b", DASM_r8l, DASM_none, 2 }, // inherited
	{ 0, 0x00001800, 0x0000ff00, 0x0000, 0x0000, "sub.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001900, 0x0000ff00, 0x0000, 0x0000, "sub.w", DASM_r16h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00001a00, 0x0000fff0, 0x0000, 0x0000, "dec.b", DASM_one, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001b00, 0x0000fff8, 0x0000, 0x0000, "subs.l", DASM_two, DASM_r16l, 2 }, // inherited
	{ 0, 0x00001b80, 0x0000fff8, 0x0000, 0x0000, "subs.l", DASM_one, DASM_r16l, 2 }, // inherited
	{ 0, 0x00001c00, 0x0000ff00, 0x0000, 0x0000, "cmp.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001d00, 0x0000ff00, 0x0000, 0x0000, "cmp.w", DASM_r16h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00001e00, 0x0000ff00, 0x0000, 0x0000, "subx.b", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00001f00, 0x0000ff00, 0x0000, 0x0000, "divxu.b", DASM_r8h, DASM_r16l, 2 }, // inherited
	{ 0, 0x00002000, 0x0000f000, 0x0000, 0x0000, "mov.b", DASM_abs8, DASM_r8u, 2 }, // inherited
	{ 0, 0x00003000, 0x0000f000, 0x0000, 0x0000, "mov.b", DASM_r8u, DASM_abs8, 2 }, // inherited
	{ 0, 0x00004000, 0x0000ff00, 0x0000, 0x0000, "bt", DASM_rel8, DASM_none, 2 }, // inherited
	{ 0, 0x00004100, 0x0000ff00, 0x0000, 0x0000, "bf", DASM_rel8, DASM_none, 2 }, // inherited
	{ 0, 0x00004200, 0x0000ff00, 0x0000, 0x0000, "bhi", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004300, 0x0000ff00, 0x0000, 0x0000, "bls", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004400, 0x0000ff00, 0x0000, 0x0000, "bcc", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004500, 0x0000ff00, 0x0000, 0x0000, "bcs", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004600, 0x0000ff00, 0x0000, 0x0000, "bne", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004700, 0x0000ff00, 0x0000, 0x0000, "beq", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004800, 0x0000ff00, 0x0000, 0x0000, "bvc", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004900, 0x0000ff00, 0x0000, 0x0000, "bvs", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004a00, 0x0000ff00, 0x0000, 0x0000, "bpl", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004b00, 0x0000ff00, 0x0000, 0x0000, "bmi", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004c00, 0x0000ff00, 0x0000, 0x0000, "bge", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004d00, 0x0000ff00, 0x0000, 0x0000, "blt", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004e00, 0x0000ff00, 0x0000, 0x0000, "bgt", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00004f00, 0x0000ff00, 0x0000, 0x0000, "ble", DASM_rel8, DASM_none, 2 | STEP_COND }, // inherited
	{ 0, 0x00005000, 0x0000ff80, 0x0000, 0x0000, "bset", DASM_imm3, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005100, 0x0000ff00, 0x0000, 0x0000, "bset", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005200, 0x0000ff80, 0x0000, 0x0000, "bclr", DASM_imm3, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005300, 0x0000ff00, 0x0000, 0x0000, "bclr", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005400, 0x0000ff80, 0x0000, 0x0000, "bnot", DASM_imm3, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005500, 0x0000ff00, 0x0000, 0x0000, "bnot", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005600, 0x0000ff80, 0x0000, 0x0000, "btst", DASM_imm3, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005700, 0x0000ff00, 0x0000, 0x0000, "btst", DASM_r8h, DASM_r8l, 2 }, // inherited
	{ 0, 0x00005800, 0x0000ffff, 0x0000, 0x0000, "rts", DASM_none, DASM_none, 2 | STEP_OUT }, // inherited
	{ 0, 0x00005980, 0x0000ffff, 0x0000, 0x0000, "rte", DASM_none, DASM_none, 2 | STEP_OUT }, // inherited
	{ 0, 0x00005a00, 0x0000ff8f, 0x0000, 0x0000, "jmp", DASM_r16h, DASM_none, 2 }, // inherited
	{ 0, 0x00005a80, 0x0000ffff, 0x0000, 0x0000, "jmp", DASM_abs16e, DASM_none, 4 }, // inherited
	{ 0, 0x00005b80, 0x0000ffc0, 0x0000, 0x0000, "jmp", DASM_abs22e, DASM_none, 4 }, // needed
	{ 0, 0x00005c00, 0x0000ff8f, 0x0000, 0x0000, "jsr", DASM_r16h, DASM_none, 2 | STEP_OVER }, // inherited
	{ 0, 0x00005c80, 0x0000ffff, 0x0000, 0x0000, "jsr", DASM_abs16e, DASM_none, 4 | STEP_OVER }, // inherited
	{ 0, 0x00005e00, 0x0000ff00, 0x0000, 0x0000, "bsr", DASM_rel8, DASM_none, 2 | STEP_OVER }, // inherited
	{ 0, 0x00005f00, 0x0000fff0, 0x0000, 0x0000, "mov.w", DASM_imm16, DASM_r16l, 4 }, // inherited
	{ 1, 0x60000000, 0xff8fff8f, 0x0000, 0x0000, "bset", DASM_imm3, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x61000000, 0xff8fff0f, 0x0000, 0x0000, "bset", DASM_r8h, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x62000000, 0xff8fff8f, 0x0000, 0x0000, "bclr", DASM_imm3, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x63000000, 0xff8fff0f, 0x0000, 0x0000, "bclr", DASM_r8h, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x64000000, 0xff8fff8f, 0x0000, 0x0000, "bnot", DASM_imm3, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x65000000, 0xff8fff0f, 0x0000, 0x0000, "bnot", DASM_r8h, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x66000000, 0xff8fff8f, 0x0000, 0x0000, "btst", DASM_imm3, DASM_r16ihh, 4 }, // inherited
	{ 1, 0x67000000, 0xff8fff0f, 0x0000, 0x0000, "btst", DASM_r8h, DASM_r16ihh, 4 }, // inherited
	{ 0, 0x00006800, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r16ih, DASM_r8l, 2 }, // needed
	{ 0, 0x00006900, 0x0000ff88, 0x0000, 0x0000, "mov.w", DASM_r16ih, DASM_r16l, 2 }, // needed
	{ 0, 0x00006a00, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r16ph, DASM_r8l, 2 }, // needed
	{ 0, 0x00006b00, 0x0000ff88, 0x0000, 0x0000, "mov.w", DASM_r16ph, DASM_r16l, 2 }, // needed
	{ 0, 0x00006c00, 0x0000fff0, 0x0000, 0x0000, "mov.b", DASM_abs16, DASM_r8l, 4 }, // inherited
	{ 0, 0x00006d00, 0x0000fff0, 0x0000, 0x0000, "mov.w", DASM_abs16, DASM_r16l, 4 }, // inherited
	{ 0, 0x00006e00, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r16d16h, DASM_r8l, 4 }, // needed
	{ 0, 0x00006f00, 0x0000ff80, 0x0000, 0x0000, "mov.w", DASM_r16d16h, DASM_r16l, 4 }, // needed
	{ 1, 0x70000000, 0xff00ff8f, 0x0000, 0x0000, "bset", DASM_imm3, DASM_abs8, 4 }, // inherited
	{ 1, 0x71000000, 0xff00ff0f, 0x0000, 0x0000, "bset", DASM_r8h, DASM_abs8, 4 }, // inherited
	{ 1, 0x72000000, 0xff00ff8f, 0x0000, 0x0000, "bclr", DASM_imm3, DASM_abs8, 4 }, // inherited
	{ 1, 0x73000000, 0xff00ff0f, 0x0000, 0x0000, "bclr", DASM_r8h, DASM_abs8, 4 }, // inherited
	{ 1, 0x74000000, 0xff00ff8f, 0x0000, 0x0000, "bnot", DASM_imm3, DASM_abs8, 4 }, // inherited
	{ 1, 0x75000000, 0xff00ff0f, 0x0000, 0x0000, "bnot", DASM_r8h, DASM_abs8, 4 }, // inherited
	{ 1, 0x76000000, 0xff00ff8f, 0x0000, 0x0000, "btst", DASM_imm3, DASM_abs8, 4 }, // inherited
	{ 1, 0x77000000, 0xff00ff0f, 0x0000, 0x0000, "btst", DASM_r8h, DASM_abs8, 4 }, // inherited
	{ 0, 0x00007800, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r8l, DASM_r16ih, 2 }, // needed
	{ 0, 0x00007900, 0x0000ff88, 0x0000, 0x0000, "mov.w", DASM_r16l, DASM_r16ih, 2 }, // needed
	{ 0, 0x00007a00, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r8l, DASM_pr16h, 2 }, // needed
	{ 0, 0x00007b00, 0x0000ff88, 0x0000, 0x0000, "mov.w", DASM_r16l, DASM_pr16h, 2 }, // needed
	{ 0, 0x00007c00, 0x0000fff0, 0x0000, 0x0000, "mov.b", DASM_r8l, DASM_abs16, 4 }, // inherited
	{ 0, 0x00007d00, 0x0000fff0, 0x0000, 0x0000, "mov.w", DASM_r16l, DASM_abs16, 4 }, // inherited
	{ 0, 0x00007e00, 0x0000ff80, 0x0000, 0x0000, "mov.b", DASM_r8l, DASM_r16d16h, 4 }, // needed
	{ 0, 0x00007f00, 0x0000ff80, 0x0000, 0x0000, "mov.w", DASM_r16l, DASM_r16d16h, 4 }, // needed
	{ 0, 0x00008000, 0x0000f000, 0x0000, 0x0000, "add.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x00009000, 0x0000f000, 0x0000, 0x0000, "addx.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000a000, 0x0000f000, 0x0000, 0x0000, "cmp.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000b000, 0x0000f000, 0x0000, 0x0000, "subx.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000c000, 0x0000f000, 0x0000, 0x0000, "or.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000d000, 0x0000f000, 0x0000, 0x0000, "xor.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000e000, 0x0000f000, 0x0000, 0x0000, "and.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0x0000f000, 0x0000f000, 0x0000, 0x0000, "mov.b", DASM_imm8, DASM_r8u, 2 }, // inherited
	{ 0, 0, 0, 0, 0, "illegal", 0, 0, 2 },
};

