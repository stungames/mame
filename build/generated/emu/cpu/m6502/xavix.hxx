void xavix_device::callf_xa3_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_special_stack(get_codebank());
	icount--;

	dec_special_stack();

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	//read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write_stack(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 7; return; }
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 8; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 9; return; }
	prefetch();
	icount--;

}

void xavix_device::callf_xa3_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_special_stack(get_codebank());
	icount--;

	dec_special_stack();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	//read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write_stack(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::jmp_xa3_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::jmp_xa3_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::retf_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read_stack(SP));
	icount--;

	inc_special_stack();

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read_special_stack();
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void xavix_device::retf_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read_stack(SP));
	icount--;

	inc_special_stack();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read_special_stack();
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::brk_xav_imp_full()
{

	// there is code in some games to indicate this doesn't always push the far bank to the stack..

	// The 6502 bug when a nmi occurs in a brk is reproduced (case !irq_taken && nmi_pending)

	if(irq_taken) {

	if(icount == 0) { inst_substate = 1; return; }
		read_pc_noinc();
	icount--;

	} else {

	if(icount == 0) { inst_substate = 2; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 3; return; }
	write_special_stack(get_codebank());
	icount--;

	set_codebank(0x00); // epo_efdx, rad_ping and rad_mtrk strongly suggest that interrupts must force bank 0 as code jumps to a ROM pointer stored earlier / a fixed pointer to a rom address in bank 0

	dec_special_stack();

	if(icount == 0) { inst_substate = 4; return; }
	write_stack(SP, PC >> 8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 6; return; }
	write_stack(SP, irq_taken ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(nmi_pending) {

		if (m_vector_callback.isnull())

		{

	if(icount == 0) { inst_substate = 7; return; }
			PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
			PC = set_h(PC, read_arg(0xfffb));
	icount--;

		}

		else

		{

			if (m_vector_callback(0,1) != -1)

			{

				PC = m_vector_callback(0,1);

				PC = set_h(PC, m_vector_callback(0,0));

			}

			else

			{

	if(icount == 0) { inst_substate = 9; return; }
				PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 10; return; }
				PC = set_h(PC, read_arg(0xfffb));
	icount--;

			}

		}

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

		if (m_vector_callback.isnull())

		{

	if(icount == 0) { inst_substate = 11; return; }
			PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 12; return; }
			PC = set_h(PC, read_arg(0xffff));
	icount--;

		}

		else

		{

			if (m_vector_callback(1,1) != -1)

			{

				PC = m_vector_callback(1,1);

				PC = set_h(PC, m_vector_callback(1,0));

			}

			else

			{

	if(icount == 0) { inst_substate = 13; return; }
				PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 14; return; }
				PC = set_h(PC, read_arg(0xffff));
	icount--;

			}

		}

		if(irq_taken)

			standard_irq_callback(IRQ_LINE);

	}

	irq_taken = false;

	P |= F_I; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 15; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void xavix_device::brk_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	// there is code in some games to indicate this doesn't always push the far bank to the stack..

	// The 6502 bug when a nmi occurs in a brk is reproduced (case !irq_taken && nmi_pending)

	if(irq_taken) {

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
		read_pc_noinc();
	icount--;

	} else {

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_special_stack(get_codebank());
	icount--;

	set_codebank(0x00); // epo_efdx, rad_ping and rad_mtrk strongly suggest that interrupts must force bank 0 as code jumps to a ROM pointer stored earlier / a fixed pointer to a rom address in bank 0

	dec_special_stack();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_stack(SP, PC >> 8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write_stack(SP, irq_taken ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(nmi_pending) {

		if (m_vector_callback.isnull())

		{

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
			PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
			PC = set_h(PC, read_arg(0xfffb));
	icount--;

		}

		else

		{

			if (m_vector_callback(0,1) != -1)

			{

				PC = m_vector_callback(0,1);

				PC = set_h(PC, m_vector_callback(0,0));

			}

			else

			{

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
				PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 10; return; }
	[[fallthrough]];
case 10:
				PC = set_h(PC, read_arg(0xfffb));
	icount--;

			}

		}

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

		if (m_vector_callback.isnull())

		{

	if(icount == 0) { inst_substate = 11; return; }
	[[fallthrough]];
case 11:
			PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 12; return; }
	[[fallthrough]];
case 12:
			PC = set_h(PC, read_arg(0xffff));
	icount--;

		}

		else

		{

			if (m_vector_callback(1,1) != -1)

			{

				PC = m_vector_callback(1,1);

				PC = set_h(PC, m_vector_callback(1,0));

			}

			else

			{

	if(icount == 0) { inst_substate = 13; return; }
	[[fallthrough]];
case 13:
				PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 14; return; }
	[[fallthrough]];
case 14:
				PC = set_h(PC, read_arg(0xffff));
	icount--;

			}

		}

		if(irq_taken)

			standard_irq_callback(IRQ_LINE);

	}

	irq_taken = false;

	P |= F_I; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 15; return; }
	[[fallthrough]];
case 15:
	prefetch();
	icount--;

	inst_state = -1;

}
	inst_substate = 0;
}


void xavix_device::rti_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	P = read_stack(SP) | (F_B|F_E);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	PC = set_h(PC, read_stack(SP));
	icount--;

	inc_special_stack();

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 = read_special_stack();
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void xavix_device::rti_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	P = read_stack(SP) | (F_B|F_E);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	PC = set_h(PC, read_stack(SP));
	icount--;

	inc_special_stack();

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 = read_special_stack();
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::pha_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_stack(SP, A);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::pha_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_stack(SP, A);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::php_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_stack(SP, P);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::php_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_stack(SP, P);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::jsr_xav_adr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_stack(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::jsr_xav_adr_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_stack(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_stack(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::pla_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	A = read_stack(SP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::pla_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A = read_stack(SP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::plp_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_stack(SP) | (F_B|F_E);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

	P = TMP; // Do *not* move it before the prefetch

}

void xavix_device::plp_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_stack(SP) | (F_B|F_E);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

	P = TMP; // Do *not* move it before the prefetch

}
	inst_substate = 0;
}


void xavix_device::rts_xav_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read_stack(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::rts_xav_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read_stack(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lda_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc(); // we need to fetch the zero page part from zero page, but the rest as if zero page wasn't there, similar to the 6509
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::lda_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc(); // we need to fetch the zero page part from zero page, but the rest as if zero page wasn't there, similar to the 6509
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::adc_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_adc(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::adc_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_adc(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cmp_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_cmp(A, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::cmp_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_cmp(A, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sbc_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_sbc(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sbc_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_sbc(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::eor_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A ^= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::eor_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A ^= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::and_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A &= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::and_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A &= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ora_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A |= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::ora_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A |= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ora_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::ora_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::and_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::and_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::eor_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::eor_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::adc_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	do_adc(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::adc_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_adc(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lda_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::lda_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cmp_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	do_cmp(A, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::cmp_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_cmp(A, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sbc_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	do_sbc(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sbc_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_sbc(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sta_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read_zeropage(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP+Y, A); // TODO
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sta_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read_zeropage(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP+Y, A); // TODO
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sta_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, A); // TODO
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sta_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, A); // TODO
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::adc_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::adc_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::and_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A &= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::and_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A &= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::asl_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::asl_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::bit_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	do_bit(read_zeropage(TMP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::bit_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	do_bit(read_zeropage(TMP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cmp_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::cmp_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cpx_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(X, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::cpx_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(X, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cpy_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(Y, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::cpy_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_cmp(Y, TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dec_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::dec_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::eor_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A ^= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::eor_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A ^= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::inc_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::inc_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lda_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::lda_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ldx_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	X = read_zeropage(TMP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::ldx_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	X = read_zeropage(TMP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ldy_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	Y = read_zeropage(TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::ldy_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	Y = read_zeropage(TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lsr_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::lsr_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ora_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A |= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::ora_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A |= read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rol_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::rol_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ror_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::ror_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sbc_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::sbc_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sta_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_zeropage(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::sta_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_zeropage(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::stx_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_zeropage(TMP, X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::stx_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_zeropage(TMP, X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sty_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_zeropage(TMP, Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::sty_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_zeropage(TMP, Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dcp_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::dcp_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::isb_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::isb_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lax_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = X = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::lax_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A = X = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rla_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::rla_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rra_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::rra_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sax_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 2; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::sax_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::slo_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::slo_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sre_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void xavix_device::sre_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::nop_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix_device::nop_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ldx_xav_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	X = read_zeropage(uint8_t(TMP+Y));
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::ldx_xav_zpy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	X = read_zeropage(uint8_t(TMP+Y));
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::stx_xav_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(uint8_t(TMP+Y), X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::stx_xav_zpy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(uint8_t(TMP+Y), X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lax_xav_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+Y);

	if(icount == 0) { inst_substate = 3; return; }
	A = X = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::lax_xav_zpy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+Y);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A = X = read_zeropage(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sax_xav_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy reaad
	icount--;

	TMP = uint8_t(TMP+Y);

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::sax_xav_zpy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy reaad
	icount--;

	TMP = uint8_t(TMP+Y);

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::adc_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::adc_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::and_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A &= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::and_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A &= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::asl_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::asl_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::cmp_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::cmp_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dec_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::dec_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::eor_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A ^= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::eor_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A ^= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::inc_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::inc_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lda_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A = read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::lda_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A = read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ldy_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	Y = read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::ldy_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	Y = read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lsr_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::lsr_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ora_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A |= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::ora_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A |= read_zeropage(uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rol_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::rol_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::ror_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::ror_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sbc_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::sbc_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(uint8_t(TMP+X));
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sta_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(uint8_t(TMP+X), A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::sta_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(uint8_t(TMP+X), A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sty_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write_zeropage(uint8_t(TMP+X), Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::sty_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write_zeropage(uint8_t(TMP+X), Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dcp_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::dcp_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::isb_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::isb_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rla_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::rla_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rra_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::rra_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::slo_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::slo_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sre_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write_zeropage(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sre_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP); // dummy read
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write_zeropage(TMP, TMP2); // dummy write
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write_zeropage(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::nop_xav_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_zeropage(uint8_t(TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix_device::nop_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_zeropage(uint8_t(TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::slo_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::slo_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rla_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::rla_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sre_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::sre_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rra_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::rra_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sax_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sax_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	TMP2 = A & X;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lax_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dumm read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A = X = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::lax_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dumm read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = X = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dcp_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::dcp_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::isb_xav_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::isb_xav_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_zeropage(TMP2); // dummy read
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read_zeropage(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::slo_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::slo_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A |= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rla_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::rla_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A &= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sre_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::sre_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	A ^= TMP2;

	set_nz(A);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::rra_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::rra_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_adc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::sha_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP2 = A & X & ((TMP >> 8)+1);

	if(page_changing(TMP, Y))

		TMP = set_h(TMP+Y, TMP2);

	else

		TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::sha_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP2 = A & X & ((TMP >> 8)+1);

	if(page_changing(TMP, Y))

		TMP = set_h(TMP+Y, TMP2);

	else

		TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::lax_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A = X = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix_device::lax_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = X = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::dcp_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::dcp_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_cmp(A, TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix_device::isb_xav_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void xavix_device::isb_xav_idy_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_zeropage(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_zeropage((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+Y)); // dummy read
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	do_sbc(TMP2);

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}




void xavix_device::do_exec_full()
{
	switch(inst_state) {

	case 0x00: brk_xav_imp_full(); break;
	case 0x01: ora_xav_idx_full(); break;
	case 0x02: kil_non_full(); break;
	case 0x03: slo_xav_idx_full(); break;
	case 0x04: nop_xav_zpg_full(); break;
	case 0x05: ora_xav_zpg_full(); break;
	case 0x06: asl_xav_zpg_full(); break;
	case 0x07: slo_xav_zpg_full(); break;
	case 0x08: php_xav_imp_full(); break;
	case 0x09: ora_imm_full(); break;
	case 0x0a: asl_acc_full(); break;
	case 0x0b: anc_imm_full(); break;
	case 0x0c: nop_aba_full(); break;
	case 0x0d: ora_aba_full(); break;
	case 0x0e: asl_aba_full(); break;
	case 0x0f: slo_aba_full(); break;
	case 0x10: bpl_rel_full(); break;
	case 0x11: ora_xav_idy_full(); break;
	case 0x12: kil_non_full(); break;
	case 0x13: slo_xav_idy_full(); break;
	case 0x14: nop_xav_zpx_full(); break;
	case 0x15: ora_xav_zpx_full(); break;
	case 0x16: asl_xav_zpx_full(); break;
	case 0x17: slo_xav_zpx_full(); break;
	case 0x18: clc_imp_full(); break;
	case 0x19: ora_aby_full(); break;
	case 0x1a: nop_imp_full(); break;
	case 0x1b: slo_aby_full(); break;
	case 0x1c: nop_abx_full(); break;
	case 0x1d: ora_abx_full(); break;
	case 0x1e: asl_abx_full(); break;
	case 0x1f: slo_abx_full(); break;
	case 0x20: jsr_xav_adr_full(); break;
	case 0x21: and_xav_idx_full(); break;
	case 0x22: callf_xa3_full(); break;
	case 0x23: rla_xav_idx_full(); break;
	case 0x24: bit_xav_zpg_full(); break;
	case 0x25: and_xav_zpg_full(); break;
	case 0x26: rol_xav_zpg_full(); break;
	case 0x27: rla_xav_zpg_full(); break;
	case 0x28: plp_xav_imp_full(); break;
	case 0x29: and_imm_full(); break;
	case 0x2a: rol_acc_full(); break;
	case 0x2b: anc_imm_full(); break;
	case 0x2c: bit_aba_full(); break;
	case 0x2d: and_aba_full(); break;
	case 0x2e: rol_aba_full(); break;
	case 0x2f: rla_aba_full(); break;
	case 0x30: bmi_rel_full(); break;
	case 0x31: and_xav_idy_full(); break;
	case 0x32: kil_non_full(); break;
	case 0x33: rla_xav_idy_full(); break;
	case 0x34: nop_xav_zpx_full(); break;
	case 0x35: and_xav_zpx_full(); break;
	case 0x36: rol_xav_zpx_full(); break;
	case 0x37: rla_xav_zpx_full(); break;
	case 0x38: sec_imp_full(); break;
	case 0x39: and_aby_full(); break;
	case 0x3a: nop_imp_full(); break;
	case 0x3b: rla_aby_full(); break;
	case 0x3c: nop_abx_full(); break;
	case 0x3d: and_abx_full(); break;
	case 0x3e: rol_abx_full(); break;
	case 0x3f: rla_abx_full(); break;
	case 0x40: rti_xav_imp_full(); break;
	case 0x41: eor_xav_idx_full(); break;
	case 0x42: kil_non_full(); break;
	case 0x43: sre_xav_idx_full(); break;
	case 0x44: nop_xav_zpg_full(); break;
	case 0x45: eor_xav_zpg_full(); break;
	case 0x46: lsr_xav_zpg_full(); break;
	case 0x47: sre_xav_zpg_full(); break;
	case 0x48: pha_xav_imp_full(); break;
	case 0x49: eor_imm_full(); break;
	case 0x4a: lsr_acc_full(); break;
	case 0x4b: asr_imm_full(); break;
	case 0x4c: jmp_adr_full(); break;
	case 0x4d: eor_aba_full(); break;
	case 0x4e: lsr_aba_full(); break;
	case 0x4f: sre_aba_full(); break;
	case 0x50: bvc_rel_full(); break;
	case 0x51: eor_xav_idy_full(); break;
	case 0x52: kil_non_full(); break;
	case 0x53: sre_xav_idy_full(); break;
	case 0x54: nop_xav_zpx_full(); break;
	case 0x55: eor_xav_zpx_full(); break;
	case 0x56: lsr_xav_zpx_full(); break;
	case 0x57: sre_xav_zpx_full(); break;
	case 0x58: cli_imp_full(); break;
	case 0x59: eor_aby_full(); break;
	case 0x5a: nop_imp_full(); break;
	case 0x5b: sre_aby_full(); break;
	case 0x5c: nop_abx_full(); break;
	case 0x5d: eor_abx_full(); break;
	case 0x5e: lsr_abx_full(); break;
	case 0x5f: sre_abx_full(); break;
	case 0x60: rts_xav_imp_full(); break;
	case 0x61: adc_xav_idx_full(); break;
	case 0x62: kil_non_full(); break;
	case 0x63: rra_xav_idx_full(); break;
	case 0x64: nop_xav_zpg_full(); break;
	case 0x65: adc_xav_zpg_full(); break;
	case 0x66: ror_xav_zpg_full(); break;
	case 0x67: rra_xav_zpg_full(); break;
	case 0x68: pla_xav_imp_full(); break;
	case 0x69: adc_imm_full(); break;
	case 0x6a: ror_acc_full(); break;
	case 0x6b: arr_imm_full(); break;
	case 0x6c: jmp_ind_full(); break;
	case 0x6d: adc_aba_full(); break;
	case 0x6e: ror_aba_full(); break;
	case 0x6f: rra_aba_full(); break;
	case 0x70: bvs_rel_full(); break;
	case 0x71: adc_xav_idy_full(); break;
	case 0x72: kil_non_full(); break;
	case 0x73: rra_xav_idy_full(); break;
	case 0x74: nop_xav_zpx_full(); break;
	case 0x75: adc_xav_zpx_full(); break;
	case 0x76: ror_xav_zpx_full(); break;
	case 0x77: rra_xav_zpx_full(); break;
	case 0x78: sei_imp_full(); break;
	case 0x79: adc_aby_full(); break;
	case 0x7a: nop_imp_full(); break;
	case 0x7b: rra_aby_full(); break;
	case 0x7c: nop_abx_full(); break;
	case 0x7d: adc_abx_full(); break;
	case 0x7e: ror_abx_full(); break;
	case 0x7f: rra_abx_full(); break;
	case 0x80: retf_imp_full(); break;
	case 0x81: sta_xav_idx_full(); break;
	case 0x82: nop_imm_full(); break;
	case 0x83: sax_xav_idx_full(); break;
	case 0x84: sty_xav_zpg_full(); break;
	case 0x85: sta_xav_zpg_full(); break;
	case 0x86: stx_xav_zpg_full(); break;
	case 0x87: sax_xav_zpg_full(); break;
	case 0x88: dey_imp_full(); break;
	case 0x89: nop_imm_full(); break;
	case 0x8a: txa_imp_full(); break;
	case 0x8b: ane_imm_full(); break;
	case 0x8c: sty_aba_full(); break;
	case 0x8d: sta_aba_full(); break;
	case 0x8e: stx_aba_full(); break;
	case 0x8f: sax_aba_full(); break;
	case 0x90: bcc_rel_full(); break;
	case 0x91: sta_xav_idy_full(); break;
	case 0x92: kil_non_full(); break;
	case 0x93: sha_xav_idy_full(); break;
	case 0x94: sty_xav_zpx_full(); break;
	case 0x95: sta_xav_zpx_full(); break;
	case 0x96: stx_xav_zpy_full(); break;
	case 0x97: sax_xav_zpy_full(); break;
	case 0x98: tya_imp_full(); break;
	case 0x99: sta_aby_full(); break;
	case 0x9a: txs_imp_full(); break;
	case 0x9b: shs_aby_full(); break;
	case 0x9c: shy_abx_full(); break;
	case 0x9d: sta_abx_full(); break;
	case 0x9e: shx_aby_full(); break;
	case 0x9f: sha_aby_full(); break;
	case 0xa0: ldy_imm_full(); break;
	case 0xa1: lda_xav_idx_full(); break;
	case 0xa2: ldx_imm_full(); break;
	case 0xa3: lax_xav_idx_full(); break;
	case 0xa4: ldy_xav_zpg_full(); break;
	case 0xa5: lda_xav_zpg_full(); break;
	case 0xa6: ldx_xav_zpg_full(); break;
	case 0xa7: lax_xav_zpg_full(); break;
	case 0xa8: tay_imp_full(); break;
	case 0xa9: lda_imm_full(); break;
	case 0xaa: tax_imp_full(); break;
	case 0xab: lxa_imm_full(); break;
	case 0xac: ldy_aba_full(); break;
	case 0xad: lda_aba_full(); break;
	case 0xae: ldx_aba_full(); break;
	case 0xaf: lax_aba_full(); break;
	case 0xb0: bcs_rel_full(); break;
	case 0xb1: lda_xav_idy_full(); break;
	case 0xb2: kil_non_full(); break;
	case 0xb3: lax_xav_idy_full(); break;
	case 0xb4: ldy_xav_zpx_full(); break;
	case 0xb5: lda_xav_zpx_full(); break;
	case 0xb6: ldx_xav_zpy_full(); break;
	case 0xb7: lax_xav_zpy_full(); break;
	case 0xb8: clv_imp_full(); break;
	case 0xb9: lda_aby_full(); break;
	case 0xba: tsx_imp_full(); break;
	case 0xbb: las_aby_full(); break;
	case 0xbc: ldy_abx_full(); break;
	case 0xbd: lda_abx_full(); break;
	case 0xbe: ldx_aby_full(); break;
	case 0xbf: lax_aby_full(); break;
	case 0xc0: cpy_imm_full(); break;
	case 0xc1: cmp_xav_idx_full(); break;
	case 0xc2: nop_imm_full(); break;
	case 0xc3: dcp_xav_idx_full(); break;
	case 0xc4: cpy_xav_zpg_full(); break;
	case 0xc5: cmp_xav_zpg_full(); break;
	case 0xc6: dec_xav_zpg_full(); break;
	case 0xc7: dcp_xav_zpg_full(); break;
	case 0xc8: iny_imp_full(); break;
	case 0xc9: cmp_imm_full(); break;
	case 0xca: dex_imp_full(); break;
	case 0xcb: sbx_imm_full(); break;
	case 0xcc: cpy_aba_full(); break;
	case 0xcd: cmp_aba_full(); break;
	case 0xce: dec_aba_full(); break;
	case 0xcf: dcp_aba_full(); break;
	case 0xd0: bne_rel_full(); break;
	case 0xd1: cmp_xav_idy_full(); break;
	case 0xd2: kil_non_full(); break;
	case 0xd3: dcp_xav_idy_full(); break;
	case 0xd4: nop_xav_zpx_full(); break;
	case 0xd5: cmp_xav_zpx_full(); break;
	case 0xd6: dec_xav_zpx_full(); break;
	case 0xd7: dcp_xav_zpx_full(); break;
	case 0xd8: cld_imp_full(); break;
	case 0xd9: cmp_aby_full(); break;
	case 0xda: nop_imp_full(); break;
	case 0xdb: dcp_aby_full(); break;
	case 0xdc: nop_abx_full(); break;
	case 0xdd: cmp_abx_full(); break;
	case 0xde: dec_abx_full(); break;
	case 0xdf: dcp_abx_full(); break;
	case 0xe0: cpx_imm_full(); break;
	case 0xe1: sbc_xav_idx_full(); break;
	case 0xe2: nop_imm_full(); break;
	case 0xe3: isb_xav_idx_full(); break;
	case 0xe4: cpx_xav_zpg_full(); break;
	case 0xe5: sbc_xav_zpg_full(); break;
	case 0xe6: inc_xav_zpg_full(); break;
	case 0xe7: isb_xav_zpg_full(); break;
	case 0xe8: inx_imp_full(); break;
	case 0xe9: sbc_imm_full(); break;
	case 0xea: nop_imp_full(); break;
	case 0xeb: sbc_imm_full(); break;
	case 0xec: cpx_aba_full(); break;
	case 0xed: sbc_aba_full(); break;
	case 0xee: inc_aba_full(); break;
	case 0xef: isb_aba_full(); break;
	case 0xf0: beq_rel_full(); break;
	case 0xf1: sbc_xav_idy_full(); break;
	case 0xf2: kil_non_full(); break;
	case 0xf3: isb_xav_idy_full(); break;
	case 0xf4: nop_xav_zpx_full(); break;
	case 0xf5: sbc_xav_zpx_full(); break;
	case 0xf6: inc_xav_zpx_full(); break;
	case 0xf7: isb_xav_zpx_full(); break;
	case 0xf8: sed_imp_full(); break;
	case 0xf9: sbc_aby_full(); break;
	case 0xfa: nop_imp_full(); break;
	case 0xfb: isb_aby_full(); break;
	case 0xfc: nop_abx_full(); break;
	case 0xfd: sbc_abx_full(); break;
	case 0xfe: inc_abx_full(); break;
	case 0xff: isb_abx_full(); break;
	case STATE_RESET: reset_full(); break;
	}
}

void xavix_device::do_exec_partial()
{
	switch(inst_state) {

	case 0x00: brk_xav_imp_partial(); break;
	case 0x01: ora_xav_idx_partial(); break;
	case 0x02: kil_non_partial(); break;
	case 0x03: slo_xav_idx_partial(); break;
	case 0x04: nop_xav_zpg_partial(); break;
	case 0x05: ora_xav_zpg_partial(); break;
	case 0x06: asl_xav_zpg_partial(); break;
	case 0x07: slo_xav_zpg_partial(); break;
	case 0x08: php_xav_imp_partial(); break;
	case 0x09: ora_imm_partial(); break;
	case 0x0a: asl_acc_partial(); break;
	case 0x0b: anc_imm_partial(); break;
	case 0x0c: nop_aba_partial(); break;
	case 0x0d: ora_aba_partial(); break;
	case 0x0e: asl_aba_partial(); break;
	case 0x0f: slo_aba_partial(); break;
	case 0x10: bpl_rel_partial(); break;
	case 0x11: ora_xav_idy_partial(); break;
	case 0x12: kil_non_partial(); break;
	case 0x13: slo_xav_idy_partial(); break;
	case 0x14: nop_xav_zpx_partial(); break;
	case 0x15: ora_xav_zpx_partial(); break;
	case 0x16: asl_xav_zpx_partial(); break;
	case 0x17: slo_xav_zpx_partial(); break;
	case 0x18: clc_imp_partial(); break;
	case 0x19: ora_aby_partial(); break;
	case 0x1a: nop_imp_partial(); break;
	case 0x1b: slo_aby_partial(); break;
	case 0x1c: nop_abx_partial(); break;
	case 0x1d: ora_abx_partial(); break;
	case 0x1e: asl_abx_partial(); break;
	case 0x1f: slo_abx_partial(); break;
	case 0x20: jsr_xav_adr_partial(); break;
	case 0x21: and_xav_idx_partial(); break;
	case 0x22: callf_xa3_partial(); break;
	case 0x23: rla_xav_idx_partial(); break;
	case 0x24: bit_xav_zpg_partial(); break;
	case 0x25: and_xav_zpg_partial(); break;
	case 0x26: rol_xav_zpg_partial(); break;
	case 0x27: rla_xav_zpg_partial(); break;
	case 0x28: plp_xav_imp_partial(); break;
	case 0x29: and_imm_partial(); break;
	case 0x2a: rol_acc_partial(); break;
	case 0x2b: anc_imm_partial(); break;
	case 0x2c: bit_aba_partial(); break;
	case 0x2d: and_aba_partial(); break;
	case 0x2e: rol_aba_partial(); break;
	case 0x2f: rla_aba_partial(); break;
	case 0x30: bmi_rel_partial(); break;
	case 0x31: and_xav_idy_partial(); break;
	case 0x32: kil_non_partial(); break;
	case 0x33: rla_xav_idy_partial(); break;
	case 0x34: nop_xav_zpx_partial(); break;
	case 0x35: and_xav_zpx_partial(); break;
	case 0x36: rol_xav_zpx_partial(); break;
	case 0x37: rla_xav_zpx_partial(); break;
	case 0x38: sec_imp_partial(); break;
	case 0x39: and_aby_partial(); break;
	case 0x3a: nop_imp_partial(); break;
	case 0x3b: rla_aby_partial(); break;
	case 0x3c: nop_abx_partial(); break;
	case 0x3d: and_abx_partial(); break;
	case 0x3e: rol_abx_partial(); break;
	case 0x3f: rla_abx_partial(); break;
	case 0x40: rti_xav_imp_partial(); break;
	case 0x41: eor_xav_idx_partial(); break;
	case 0x42: kil_non_partial(); break;
	case 0x43: sre_xav_idx_partial(); break;
	case 0x44: nop_xav_zpg_partial(); break;
	case 0x45: eor_xav_zpg_partial(); break;
	case 0x46: lsr_xav_zpg_partial(); break;
	case 0x47: sre_xav_zpg_partial(); break;
	case 0x48: pha_xav_imp_partial(); break;
	case 0x49: eor_imm_partial(); break;
	case 0x4a: lsr_acc_partial(); break;
	case 0x4b: asr_imm_partial(); break;
	case 0x4c: jmp_adr_partial(); break;
	case 0x4d: eor_aba_partial(); break;
	case 0x4e: lsr_aba_partial(); break;
	case 0x4f: sre_aba_partial(); break;
	case 0x50: bvc_rel_partial(); break;
	case 0x51: eor_xav_idy_partial(); break;
	case 0x52: kil_non_partial(); break;
	case 0x53: sre_xav_idy_partial(); break;
	case 0x54: nop_xav_zpx_partial(); break;
	case 0x55: eor_xav_zpx_partial(); break;
	case 0x56: lsr_xav_zpx_partial(); break;
	case 0x57: sre_xav_zpx_partial(); break;
	case 0x58: cli_imp_partial(); break;
	case 0x59: eor_aby_partial(); break;
	case 0x5a: nop_imp_partial(); break;
	case 0x5b: sre_aby_partial(); break;
	case 0x5c: nop_abx_partial(); break;
	case 0x5d: eor_abx_partial(); break;
	case 0x5e: lsr_abx_partial(); break;
	case 0x5f: sre_abx_partial(); break;
	case 0x60: rts_xav_imp_partial(); break;
	case 0x61: adc_xav_idx_partial(); break;
	case 0x62: kil_non_partial(); break;
	case 0x63: rra_xav_idx_partial(); break;
	case 0x64: nop_xav_zpg_partial(); break;
	case 0x65: adc_xav_zpg_partial(); break;
	case 0x66: ror_xav_zpg_partial(); break;
	case 0x67: rra_xav_zpg_partial(); break;
	case 0x68: pla_xav_imp_partial(); break;
	case 0x69: adc_imm_partial(); break;
	case 0x6a: ror_acc_partial(); break;
	case 0x6b: arr_imm_partial(); break;
	case 0x6c: jmp_ind_partial(); break;
	case 0x6d: adc_aba_partial(); break;
	case 0x6e: ror_aba_partial(); break;
	case 0x6f: rra_aba_partial(); break;
	case 0x70: bvs_rel_partial(); break;
	case 0x71: adc_xav_idy_partial(); break;
	case 0x72: kil_non_partial(); break;
	case 0x73: rra_xav_idy_partial(); break;
	case 0x74: nop_xav_zpx_partial(); break;
	case 0x75: adc_xav_zpx_partial(); break;
	case 0x76: ror_xav_zpx_partial(); break;
	case 0x77: rra_xav_zpx_partial(); break;
	case 0x78: sei_imp_partial(); break;
	case 0x79: adc_aby_partial(); break;
	case 0x7a: nop_imp_partial(); break;
	case 0x7b: rra_aby_partial(); break;
	case 0x7c: nop_abx_partial(); break;
	case 0x7d: adc_abx_partial(); break;
	case 0x7e: ror_abx_partial(); break;
	case 0x7f: rra_abx_partial(); break;
	case 0x80: retf_imp_partial(); break;
	case 0x81: sta_xav_idx_partial(); break;
	case 0x82: nop_imm_partial(); break;
	case 0x83: sax_xav_idx_partial(); break;
	case 0x84: sty_xav_zpg_partial(); break;
	case 0x85: sta_xav_zpg_partial(); break;
	case 0x86: stx_xav_zpg_partial(); break;
	case 0x87: sax_xav_zpg_partial(); break;
	case 0x88: dey_imp_partial(); break;
	case 0x89: nop_imm_partial(); break;
	case 0x8a: txa_imp_partial(); break;
	case 0x8b: ane_imm_partial(); break;
	case 0x8c: sty_aba_partial(); break;
	case 0x8d: sta_aba_partial(); break;
	case 0x8e: stx_aba_partial(); break;
	case 0x8f: sax_aba_partial(); break;
	case 0x90: bcc_rel_partial(); break;
	case 0x91: sta_xav_idy_partial(); break;
	case 0x92: kil_non_partial(); break;
	case 0x93: sha_xav_idy_partial(); break;
	case 0x94: sty_xav_zpx_partial(); break;
	case 0x95: sta_xav_zpx_partial(); break;
	case 0x96: stx_xav_zpy_partial(); break;
	case 0x97: sax_xav_zpy_partial(); break;
	case 0x98: tya_imp_partial(); break;
	case 0x99: sta_aby_partial(); break;
	case 0x9a: txs_imp_partial(); break;
	case 0x9b: shs_aby_partial(); break;
	case 0x9c: shy_abx_partial(); break;
	case 0x9d: sta_abx_partial(); break;
	case 0x9e: shx_aby_partial(); break;
	case 0x9f: sha_aby_partial(); break;
	case 0xa0: ldy_imm_partial(); break;
	case 0xa1: lda_xav_idx_partial(); break;
	case 0xa2: ldx_imm_partial(); break;
	case 0xa3: lax_xav_idx_partial(); break;
	case 0xa4: ldy_xav_zpg_partial(); break;
	case 0xa5: lda_xav_zpg_partial(); break;
	case 0xa6: ldx_xav_zpg_partial(); break;
	case 0xa7: lax_xav_zpg_partial(); break;
	case 0xa8: tay_imp_partial(); break;
	case 0xa9: lda_imm_partial(); break;
	case 0xaa: tax_imp_partial(); break;
	case 0xab: lxa_imm_partial(); break;
	case 0xac: ldy_aba_partial(); break;
	case 0xad: lda_aba_partial(); break;
	case 0xae: ldx_aba_partial(); break;
	case 0xaf: lax_aba_partial(); break;
	case 0xb0: bcs_rel_partial(); break;
	case 0xb1: lda_xav_idy_partial(); break;
	case 0xb2: kil_non_partial(); break;
	case 0xb3: lax_xav_idy_partial(); break;
	case 0xb4: ldy_xav_zpx_partial(); break;
	case 0xb5: lda_xav_zpx_partial(); break;
	case 0xb6: ldx_xav_zpy_partial(); break;
	case 0xb7: lax_xav_zpy_partial(); break;
	case 0xb8: clv_imp_partial(); break;
	case 0xb9: lda_aby_partial(); break;
	case 0xba: tsx_imp_partial(); break;
	case 0xbb: las_aby_partial(); break;
	case 0xbc: ldy_abx_partial(); break;
	case 0xbd: lda_abx_partial(); break;
	case 0xbe: ldx_aby_partial(); break;
	case 0xbf: lax_aby_partial(); break;
	case 0xc0: cpy_imm_partial(); break;
	case 0xc1: cmp_xav_idx_partial(); break;
	case 0xc2: nop_imm_partial(); break;
	case 0xc3: dcp_xav_idx_partial(); break;
	case 0xc4: cpy_xav_zpg_partial(); break;
	case 0xc5: cmp_xav_zpg_partial(); break;
	case 0xc6: dec_xav_zpg_partial(); break;
	case 0xc7: dcp_xav_zpg_partial(); break;
	case 0xc8: iny_imp_partial(); break;
	case 0xc9: cmp_imm_partial(); break;
	case 0xca: dex_imp_partial(); break;
	case 0xcb: sbx_imm_partial(); break;
	case 0xcc: cpy_aba_partial(); break;
	case 0xcd: cmp_aba_partial(); break;
	case 0xce: dec_aba_partial(); break;
	case 0xcf: dcp_aba_partial(); break;
	case 0xd0: bne_rel_partial(); break;
	case 0xd1: cmp_xav_idy_partial(); break;
	case 0xd2: kil_non_partial(); break;
	case 0xd3: dcp_xav_idy_partial(); break;
	case 0xd4: nop_xav_zpx_partial(); break;
	case 0xd5: cmp_xav_zpx_partial(); break;
	case 0xd6: dec_xav_zpx_partial(); break;
	case 0xd7: dcp_xav_zpx_partial(); break;
	case 0xd8: cld_imp_partial(); break;
	case 0xd9: cmp_aby_partial(); break;
	case 0xda: nop_imp_partial(); break;
	case 0xdb: dcp_aby_partial(); break;
	case 0xdc: nop_abx_partial(); break;
	case 0xdd: cmp_abx_partial(); break;
	case 0xde: dec_abx_partial(); break;
	case 0xdf: dcp_abx_partial(); break;
	case 0xe0: cpx_imm_partial(); break;
	case 0xe1: sbc_xav_idx_partial(); break;
	case 0xe2: nop_imm_partial(); break;
	case 0xe3: isb_xav_idx_partial(); break;
	case 0xe4: cpx_xav_zpg_partial(); break;
	case 0xe5: sbc_xav_zpg_partial(); break;
	case 0xe6: inc_xav_zpg_partial(); break;
	case 0xe7: isb_xav_zpg_partial(); break;
	case 0xe8: inx_imp_partial(); break;
	case 0xe9: sbc_imm_partial(); break;
	case 0xea: nop_imp_partial(); break;
	case 0xeb: sbc_imm_partial(); break;
	case 0xec: cpx_aba_partial(); break;
	case 0xed: sbc_aba_partial(); break;
	case 0xee: inc_aba_partial(); break;
	case 0xef: isb_aba_partial(); break;
	case 0xf0: beq_rel_partial(); break;
	case 0xf1: sbc_xav_idy_partial(); break;
	case 0xf2: kil_non_partial(); break;
	case 0xf3: isb_xav_idy_partial(); break;
	case 0xf4: nop_xav_zpx_partial(); break;
	case 0xf5: sbc_xav_zpx_partial(); break;
	case 0xf6: inc_xav_zpx_partial(); break;
	case 0xf7: isb_xav_zpx_partial(); break;
	case 0xf8: sed_imp_partial(); break;
	case 0xf9: sbc_aby_partial(); break;
	case 0xfa: nop_imp_partial(); break;
	case 0xfb: isb_aby_partial(); break;
	case 0xfc: nop_abx_partial(); break;
	case 0xfd: sbc_abx_partial(); break;
	case 0xfe: inc_abx_partial(); break;
	case 0xff: isb_abx_partial(); break;
	case STATE_RESET: reset_partial(); break;
	}
}

