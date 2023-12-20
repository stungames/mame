const i8xc196_disassembler::disasm_entry i8xc196_disassembler::disasm_entries[0x100] = {
	{ "skip", NULL, DASM_immed_1b, 0 },
	{ "clr", NULL, DASM_direct_1w, 0 },
	{ "not", NULL, DASM_direct_1w, 0 },
	{ "neg", NULL, DASM_direct_1w, 0 },
	{ "xch", NULL, DASM_direct_2w, 0 },
	{ "dec", NULL, DASM_direct_1w, 0 },
	{ "ext", NULL, DASM_direct_1w, 0 },
	{ "inc", NULL, DASM_direct_1w, 0 },
	{ "shr", NULL, DASM_immed_or_reg_2w, 0 },
	{ "shl", NULL, DASM_immed_or_reg_2w, 0 },
	{ "shra", NULL, DASM_immed_or_reg_2w, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "shrl", NULL, DASM_immed_or_reg_2w, 0 },
	{ "shll", NULL, DASM_immed_or_reg_2w, 0 },
	{ "shral", NULL, DASM_immed_or_reg_2w, 0 },
	{ "norml", NULL, DASM_direct_2e, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "clrb", NULL, DASM_direct_1b, 0 },
	{ "notb", NULL, DASM_direct_1b, 0 },
	{ "negb", NULL, DASM_direct_1b, 0 },
	{ "xchb", NULL, DASM_direct_2b, 0 },
	{ "decb", NULL, DASM_direct_1b, 0 },
	{ "extb", NULL, DASM_direct_1b, 0 },
	{ "incb", NULL, DASM_direct_1b, 0 },
	{ "shrb", NULL, DASM_immed_or_reg_2b, 0 },
	{ "shlb", NULL, DASM_immed_or_reg_2b, 0 },
	{ "shrab", NULL, DASM_immed_or_reg_2b, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "sjmp", NULL, DASM_rel11, 0 },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "scall", NULL, DASM_rel11, STEP_OVER },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbc", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "jbs", NULL, DASM_brrel8, STEP_COND },
	{ "and", NULL, DASM_direct_3w, 0 },
	{ "and", NULL, DASM_immed_3w, 0 },
	{ "and", NULL, DASM_indirect_3w, 0 },
	{ "and", NULL, DASM_indexed_3w, 0 },
	{ "add", NULL, DASM_direct_3w, 0 },
	{ "add", NULL, DASM_immed_3w, 0 },
	{ "add", NULL, DASM_indirect_3w, 0 },
	{ "add", NULL, DASM_indexed_3w, 0 },
	{ "sub", NULL, DASM_direct_3w, 0 },
	{ "sub", NULL, DASM_immed_3w, 0 },
	{ "sub", NULL, DASM_indirect_3w, 0 },
	{ "sub", NULL, DASM_indexed_3w, 0 },
	{ "mulu", "mul", DASM_direct_3w, 0 },
	{ "mulu", "mul", DASM_immed_3w, 0 },
	{ "mulu", "mul", DASM_indirect_3w, 0 },
	{ "mulu", "mul", DASM_indexed_3w, 0 },
	{ "andb", NULL, DASM_direct_3b, 0 },
	{ "andb", NULL, DASM_immed_3b, 0 },
	{ "andb", NULL, DASM_indirect_3b, 0 },
	{ "andb", NULL, DASM_indexed_3b, 0 },
	{ "addb", NULL, DASM_direct_3b, 0 },
	{ "addb", NULL, DASM_immed_3b, 0 },
	{ "addb", NULL, DASM_indirect_3b, 0 },
	{ "addb", NULL, DASM_indexed_3b, 0 },
	{ "subb", NULL, DASM_direct_3b, 0 },
	{ "subb", NULL, DASM_immed_3b, 0 },
	{ "subb", NULL, DASM_indirect_3b, 0 },
	{ "subb", NULL, DASM_indexed_3b, 0 },
	{ "mulub", "mulb", DASM_direct_3e, 0 },
	{ "mulub", "mulb", DASM_immed_3e, 0 },
	{ "mulub", "mulb", DASM_indirect_3e, 0 },
	{ "mulub", "mulb", DASM_indexed_3e, 0 },
	{ "and", NULL, DASM_direct_2w, 0 },
	{ "and", NULL, DASM_immed_2w, 0 },
	{ "and", NULL, DASM_indirect_2w, 0 },
	{ "and", NULL, DASM_indexed_2w, 0 },
	{ "add", NULL, DASM_direct_2w, 0 },
	{ "add", NULL, DASM_immed_2w, 0 },
	{ "add", NULL, DASM_indirect_2w, 0 },
	{ "add", NULL, DASM_indexed_2w, 0 },
	{ "sub", NULL, DASM_direct_2w, 0 },
	{ "sub", NULL, DASM_immed_2w, 0 },
	{ "sub", NULL, DASM_indirect_2w, 0 },
	{ "sub", NULL, DASM_indexed_2w, 0 },
	{ "mulu", "mul", DASM_direct_2w, 0 },
	{ "mulu", "mul", DASM_immed_2w, 0 },
	{ "mulu", "mul", DASM_indirect_2w, 0 },
	{ "mulu", "mul", DASM_indexed_2w, 0 },
	{ "andb", NULL, DASM_direct_2b, 0 },
	{ "andb", NULL, DASM_immed_2b, 0 },
	{ "andb", NULL, DASM_indirect_2b, 0 },
	{ "andb", NULL, DASM_indexed_2b, 0 },
	{ "addb", NULL, DASM_direct_2b, 0 },
	{ "addb", NULL, DASM_immed_2b, 0 },
	{ "addb", NULL, DASM_indirect_2b, 0 },
	{ "addb", NULL, DASM_indexed_2b, 0 },
	{ "subb", NULL, DASM_direct_2b, 0 },
	{ "subb", NULL, DASM_immed_2b, 0 },
	{ "subb", NULL, DASM_indirect_2b, 0 },
	{ "subb", NULL, DASM_indexed_2b, 0 },
	{ "mulub", "mulb", DASM_direct_2b, 0 },
	{ "mulub", "mulb", DASM_immed_2b, 0 },
	{ "mulub", "mulb", DASM_indirect_2b, 0 },
	{ "mulub", "mulb", DASM_indexed_2b, 0 },
	{ "or", NULL, DASM_direct_2w, 0 },
	{ "or", NULL, DASM_immed_2w, 0 },
	{ "or", NULL, DASM_indirect_2w, 0 },
	{ "or", NULL, DASM_indexed_2w, 0 },
	{ "xor", NULL, DASM_direct_2w, 0 },
	{ "xor", NULL, DASM_immed_2w, 0 },
	{ "xor", NULL, DASM_indirect_2w, 0 },
	{ "xor", NULL, DASM_indexed_2w, 0 },
	{ "cmp", NULL, DASM_direct_2w, 0 },
	{ "cmp", NULL, DASM_immed_2w, 0 },
	{ "cmp", NULL, DASM_indirect_2w, 0 },
	{ "cmp", NULL, DASM_indexed_2w, 0 },
	{ "divu", "div", DASM_direct_2w, 0 },
	{ "divu", "div", DASM_immed_2w, 0 },
	{ "divu", "div", DASM_indirect_2w, 0 },
	{ "divu", "div", DASM_indexed_2w, 0 },
	{ "orb", NULL, DASM_direct_2b, 0 },
	{ "orb", NULL, DASM_immed_2b, 0 },
	{ "orb", NULL, DASM_indirect_2b, 0 },
	{ "orb", NULL, DASM_indexed_2b, 0 },
	{ "xorb", NULL, DASM_direct_2b, 0 },
	{ "xorb", NULL, DASM_immed_2b, 0 },
	{ "xorb", NULL, DASM_indirect_2b, 0 },
	{ "xorb", NULL, DASM_indexed_2b, 0 },
	{ "cmpb", NULL, DASM_direct_2b, 0 },
	{ "cmpb", NULL, DASM_immed_2b, 0 },
	{ "cmpb", NULL, DASM_indirect_2b, 0 },
	{ "cmpb", NULL, DASM_indexed_2b, 0 },
	{ "divub", "divb", DASM_direct_2e, 0 },
	{ "divub", "divb", DASM_immed_2e, 0 },
	{ "divub", "divb", DASM_indirect_2w, 0 },
	{ "divub", "divb", DASM_indexed_2w, 0 },
	{ "ld", NULL, DASM_direct_2w, 0 },
	{ "ld", NULL, DASM_immed_2w, 0 },
	{ "ld", NULL, DASM_indirect_2w, 0 },
	{ "ld", NULL, DASM_indexed_2w, 0 },
	{ "addc", NULL, DASM_direct_2w, 0 },
	{ "addc", NULL, DASM_immed_2w, 0 },
	{ "addc", NULL, DASM_indirect_2w, 0 },
	{ "addc", NULL, DASM_indexed_2w, 0 },
	{ "subc", NULL, DASM_direct_2w, 0 },
	{ "subc", NULL, DASM_immed_2w, 0 },
	{ "subc", NULL, DASM_indirect_2w, 0 },
	{ "subc", NULL, DASM_indexed_2w, 0 },
	{ "ldbze", NULL, DASM_direct_2e, 0 },
	{ "ldbze", NULL, DASM_immed_2e, 0 },
	{ "ldbze", NULL, DASM_indirect_2w, 0 },
	{ "ldbze", NULL, DASM_indexed_2w, 0 },
	{ "ldb", NULL, DASM_direct_2b, 0 },
	{ "ldb", NULL, DASM_immed_2b, 0 },
	{ "ldb", NULL, DASM_indirect_2b, 0 },
	{ "ldb", NULL, DASM_indexed_2b, 0 },
	{ "addcb", NULL, DASM_direct_2b, 0 },
	{ "addcb", NULL, DASM_immed_2b, 0 },
	{ "addcb", NULL, DASM_indirect_2b, 0 },
	{ "addcb", NULL, DASM_indexed_2b, 0 },
	{ "subcb", NULL, DASM_direct_2b, 0 },
	{ "subcb", NULL, DASM_immed_2b, 0 },
	{ "subcb", NULL, DASM_indirect_2b, 0 },
	{ "subcb", NULL, DASM_indexed_2b, 0 },
	{ "ldbse", NULL, DASM_direct_2e, 0 },
	{ "ldbse", NULL, DASM_immed_2e, 0 },
	{ "ldbse", NULL, DASM_indirect_2w, 0 },
	{ "ldbse", NULL, DASM_indexed_2w, 0 },
	{ "st", NULL, DASM_direct_2w, 0 },
	{ "bmov", NULL, DASM_direct_2w, 0 },
	{ "st", NULL, DASM_indirect_2w, 0 },
	{ "st", NULL, DASM_indexed_2w, 0 },
	{ "stb", NULL, DASM_direct_2b, 0 },
	{ "cmpl", NULL, DASM_direct_2w, 0 },
	{ "stb", NULL, DASM_indirect_2b, 0 },
	{ "stb", NULL, DASM_indexed_2b, 0 },
	{ "push", NULL, DASM_direct_1w, 0 },
	{ "push", NULL, DASM_immed_1w, 0 },
	{ "push", NULL, DASM_indirect_1w, 0 },
	{ "push", NULL, DASM_indexed_1w, 0 },
	{ "pop", NULL, DASM_direct_1w, 0 },
	{ "bmovi", NULL, DASM_direct_2w, 0 },
	{ "pop", NULL, DASM_indirect_1w, 0 },
	{ "pop", NULL, DASM_indexed_1w, 0 },
	{ "jnst", NULL, DASM_rel8, STEP_COND },
	{ "jnh", NULL, DASM_rel8, STEP_COND },
	{ "jgt", NULL, DASM_rel8, STEP_COND },
	{ "jnc", NULL, DASM_rel8, STEP_COND },
	{ "jnvt", NULL, DASM_rel8, STEP_COND },
	{ "jnv", NULL, DASM_rel8, STEP_COND },
	{ "jge", NULL, DASM_rel8, STEP_COND },
	{ "jne", NULL, DASM_rel8, STEP_COND },
	{ "jst", NULL, DASM_rel8, STEP_COND },
	{ "jh", NULL, DASM_rel8, STEP_COND },
	{ "jle", NULL, DASM_rel8, STEP_COND },
	{ "jc", NULL, DASM_rel8, STEP_COND },
	{ "jvt", NULL, DASM_rel8, STEP_COND },
	{ "jv", NULL, DASM_rel8, STEP_COND },
	{ "jlt", NULL, DASM_rel8, STEP_COND },
	{ "je", NULL, DASM_rel8, STEP_COND },
	{ "djnz", NULL, DASM_rrel8, STEP_COND },
	{ "djnzw", NULL, DASM_wrrel8, STEP_COND },
	{ "???", NULL, DASM_none, 0 },
	{ "br", NULL, DASM_indirect_1n, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "ljmp", NULL, DASM_rel16, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "lcall", NULL, DASM_rel16, STEP_OVER },
	{ "ret", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "pushf", NULL, DASM_none, 0 },
	{ "popf", NULL, DASM_none, 0 },
	{ "pusha", NULL, DASM_none, 0 },
	{ "popa", NULL, DASM_none, 0 },
	{ "idlpd", NULL, DASM_none, 0 },
	{ "trap", NULL, DASM_none, 0 },
	{ "clrc", NULL, DASM_none, 0 },
	{ "setc", NULL, DASM_none, 0 },
	{ "di", NULL, DASM_none, 0 },
	{ "ei", NULL, DASM_none, 0 },
	{ "clrvt", NULL, DASM_none, 0 },
	{ "nop", NULL, DASM_none, 0 },
	{ "???", NULL, DASM_none, 0 },
	{ "rst", NULL, DASM_none, 0 },
};

