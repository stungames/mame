void xavix2000_device::phy_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_stack(SP, Y);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix2000_device::phy_imp_partial()
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
	write_stack(SP, Y);
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


void xavix2000_device::phx_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_stack(SP, X);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix2000_device::phx_imp_partial()
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
	write_stack(SP, X);
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


void xavix2000_device::plx_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	X = read_stack(SP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix2000_device::plx_imp_partial()
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
	X = read_stack(SP);
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


void xavix2000_device::ply_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_stack(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	Y = read_stack(SP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ply_imp_partial()
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
	Y = read_stack(SP);
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


void xavix2000_device::clr_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::clr_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::dec_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::dec_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::not_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = A ^ 0xff;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::not_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = A ^ 0xff;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::inc_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::inc_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::neg_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (0x00 - A) & 0xff;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::neg_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (0x00 - A) & 0xff;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::oraj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A |= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::oraj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A |= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::orak_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A |= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::orak_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A |= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::oral_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A |= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::oral_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A |= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::oram_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A |= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::oram_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A |= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A &= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A &= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andk_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A &= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andk_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A &= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andl_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A &= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andl_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A &= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andm_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A &= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andm_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A &= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eorj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A ^= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eorj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A ^= m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eork_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A ^= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eork_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A ^= m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eorl_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A ^= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eorl_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A ^= m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eorm_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A ^= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eorm_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A ^= m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adcj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_adc(m_j);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adcj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_adc(m_j);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adck_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_adc(m_k);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adck_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_adc(m_k);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adcl_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_adc(m_l);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adcl_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_adc(m_l);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adcm_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_adc(m_m);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adcm_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_adc(m_m);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::staj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_j = A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::staj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_j = A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stak_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_k = A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stak_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_k = A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stal_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_l = A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stal_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_l = A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stam_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_m = A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stam_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_m = A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldaj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldaj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = m_j;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldak_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldak_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = m_k;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldal_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldal_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = m_l;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldam_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldam_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = m_m;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmpj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_cmp(A, m_j);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmpj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_cmp(A, m_j);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmpk_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_cmp(A, m_k);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmpk_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_cmp(A, m_k);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmpl_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_cmp(A, m_l);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmpl_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_cmp(A, m_l);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmpm_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_cmp(A, m_m);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmpm_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_cmp(A, m_m);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbcj_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_sbc(m_j);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbcj_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_sbc(m_j);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbck_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_sbc(m_k);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbck_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_sbc(m_k);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbcl_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_sbc(m_l);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbcl_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_sbc(m_l);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbcm_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	do_sbc(m_m);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbcm_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	do_sbc(m_m);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spa0_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0xffff00) | A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spa0_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0xffff00) | A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpa0_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pa & 0x0000ff) >> 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpa0_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pa & 0x0000ff) >> 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spa1_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0xff00ff) | (A << 8);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spa1_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0xff00ff) | (A << 8);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpa1_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pa & 0x00ff00) >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpa1_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pa & 0x00ff00) >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spa2_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0x00ffff) | (A << 16);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spa2_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & 0x00ffff) | (A << 16);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpa2_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pa & 0xff0000) >> 16;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpa2_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pa & 0xff0000) >> 16;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spb0_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0xffff00) | A;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spb0_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0xffff00) | A;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpb0_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pb & 0x0000ff) >> 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpb0_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pb & 0x0000ff) >> 0;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spb1_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0xff00ff) | (A << 8);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spb1_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0xff00ff) | (A << 8);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpb1_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pb & 0x00ff00) >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpb1_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pb & 0x00ff00) >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::spb2_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0x00ffff) | (A << 16);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::spb2_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & 0x00ffff) | (A << 16);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::lpb2_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = (m_pb & 0xff0000) >> 16;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::lpb2_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = (m_pb & 0xff0000) >> 16;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::incpa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & ~0xff) | ((m_pa+1) & 0xff);

	set_nz(m_pa&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::incpa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & ~0xff) | ((m_pa+1) & 0xff);

	set_nz(m_pa&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::incpb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & ~0xff) | ((m_pb+1) & 0xff);

	set_nz(m_pb&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::incpb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & ~0xff) | ((m_pb+1) & 0xff);

	set_nz(m_pb&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::decpa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & ~0xff) | ((m_pa-1) & 0xff);

	set_nz(m_pa&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::decpa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pa = (m_pa & ~0xff) | ((m_pa-1) & 0xff);

	set_nz(m_pa&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::decpb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & ~0xff) | ((m_pb-1) & 0xff);

	set_nz(m_pb&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::decpb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_pb = (m_pb & ~0xff) | ((m_pb-1) & 0xff);

	set_nz(m_pb&0xff); // startup code seems to require flag to set if low byte is 0x00?

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::orapa_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::orapa_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andpa_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andpa_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eorpa_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eorpa_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adcpa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	do_adc(read_full_data(m_pa));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adcpa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	do_adc(read_full_data(m_pa));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stapa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	write_full_data(m_pa, A);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stapa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	write_full_data(m_pa, A);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldapa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	A = read_full_data(m_pa);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldapa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	A = read_full_data(m_pa);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmppa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_full_data(m_pa);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmppa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_full_data(m_pa);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbcpa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	do_sbc(read_full_data(m_pa));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbcpa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	do_sbc(read_full_data(m_pa));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::orapb_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::orapb_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::andpb_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::andpb_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::eorpb_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::eorpb_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::adcpb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	do_adc(read_full_data(m_pb));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::adcpb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	do_adc(read_full_data(m_pb));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stapb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	write_full_data(m_pb, A);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stapb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	write_full_data(m_pb, A);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::ldapb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	A = read_full_data(m_pb);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::ldapb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	A = read_full_data(m_pb);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmppb_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmppb_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sbcpb_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	do_sbc(read_full_data(m_pb));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sbcpb_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	do_sbc(read_full_data(m_pb));
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stx_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+Y, X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stx_aby_partial()
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
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP+Y, X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sty_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+X, Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sty_abx_partial()
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
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP+X, Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stz_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write_zeropage(TMP, 0x00);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stz_xav_zpg_partial()
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
	write_zeropage(TMP, 0x00);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::stz_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, 0x00);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void xavix2000_device::stz_aba_partial()
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
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, 0x00);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::bit_xav_zpx_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::bit_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::bit_abx_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::bit_abx_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::bit_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(A & TMP)

		P &= ~F_Z;

	else

		P |= F_Z;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::bit_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(A & TMP)

		P &= ~F_Z;

	else

		P |= F_Z;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::asr_xav_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc(); // TODO: verify this, should it write back or set A?
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_zeropage(TMP);
	icount--;

	do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void xavix2000_device::asr_xav_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc(); // TODO: verify this, should it write back or set A?
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_zeropage(TMP);
	icount--;

	do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::asr_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asr(TMP2); // used by xavbox, see 14e8

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix2000_device::asr_aba_partial()
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
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, TMP2);
	icount--;

	TMP2 = do_asr(TMP2); // used by xavbox, see 14e8

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


void xavix2000_device::asr_xav_zpx_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::asr_xav_zpx_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::asr_acc_full()
{

	A = do_asr(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void xavix2000_device::asr_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_asr(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::asr_abx_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::asr_abx_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::cmc_imp_full()
{

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::cmc_imp_partial()
{
switch(inst_substate) {
case 0:

	fatalerror("unhandled opcode %02x%04x: %02x\n", m_codebank, PPC, inst_state);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::sev_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P |= F_V;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void xavix2000_device::sev_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P |= F_V;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void xavix2000_device::jmpf_ind_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read(set_l(TMP, TMP+1)));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP+2);
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void xavix2000_device::jmpf_ind_partial()
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
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read(set_l(TMP, TMP+1)));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP+2);
	icount--;

	set_codebank(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}




void xavix2000_device::do_exec_full()
{
	switch(inst_state) {

	case 0x00: brk_xav_imp_full(); break;
	case 0x01: ora_xav_idx_full(); break;
	case 0x02: cmc_imp_full(); break;
	case 0x03: oraj_imp_full(); break;
	case 0x04: asr_xav_zpg_full(); break;
	case 0x05: ora_xav_zpg_full(); break;
	case 0x06: asl_xav_zpg_full(); break;
	case 0x07: orak_imp_full(); break;
	case 0x08: php_xav_imp_full(); break;
	case 0x09: ora_imm_full(); break;
	case 0x0a: asl_acc_full(); break;
	case 0x0b: oral_imp_full(); break;
	case 0x0c: asr_aba_full(); break;
	case 0x0d: ora_aba_full(); break;
	case 0x0e: asl_aba_full(); break;
	case 0x0f: oram_imp_full(); break;
	case 0x10: bpl_rel_full(); break;
	case 0x11: ora_xav_idy_full(); break;
	case 0x12: phx_imp_full(); break;
	case 0x13: orapa_imp_full(); break;
	case 0x14: asr_xav_zpx_full(); break;
	case 0x15: ora_xav_zpx_full(); break;
	case 0x16: asl_xav_zpx_full(); break;
	case 0x17: orapb_imp_full(); break;
	case 0x18: clc_imp_full(); break;
	case 0x19: ora_aby_full(); break;
	case 0x1a: asr_acc_full(); break;
	case 0x1b: spa0_imp_full(); break;
	case 0x1c: asr_abx_full(); break;
	case 0x1d: ora_abx_full(); break;
	case 0x1e: asl_abx_full(); break;
	case 0x1f: spb0_imp_full(); break;
	case 0x20: jsr_xav_adr_full(); break;
	case 0x21: and_xav_idx_full(); break;
	case 0x22: callf_xa3_full(); break;
	case 0x23: andj_imp_full(); break;
	case 0x24: bit_xav_zpg_full(); break;
	case 0x25: and_xav_zpg_full(); break;
	case 0x26: rol_xav_zpg_full(); break;
	case 0x27: andk_imp_full(); break;
	case 0x28: plp_xav_imp_full(); break;
	case 0x29: and_imm_full(); break;
	case 0x2a: rol_acc_full(); break;
	case 0x2b: andl_imp_full(); break;
	case 0x2c: bit_aba_full(); break;
	case 0x2d: and_aba_full(); break;
	case 0x2e: rol_aba_full(); break;
	case 0x2f: andm_imp_full(); break;
	case 0x30: bmi_rel_full(); break;
	case 0x31: and_xav_idy_full(); break;
	case 0x32: plx_imp_full(); break;
	case 0x33: andpa_imp_full(); break;
	case 0x34: bit_xav_zpx_full(); break;
	case 0x35: and_xav_zpx_full(); break;
	case 0x36: rol_xav_zpx_full(); break;
	case 0x37: andpb_imp_full(); break;
	case 0x38: sec_imp_full(); break;
	case 0x39: and_aby_full(); break;
	case 0x3a: bit_imm_full(); break;
	case 0x3b: lpa0_imp_full(); break;
	case 0x3c: bit_abx_full(); break;
	case 0x3d: and_abx_full(); break;
	case 0x3e: rol_abx_full(); break;
	case 0x3f: lpb0_imp_full(); break;
	case 0x40: rti_xav_imp_full(); break;
	case 0x41: eor_xav_idx_full(); break;
	case 0x42: nop_imp_full(); break;
	case 0x43: eorj_imp_full(); break;
	case 0x44: nop_imp_full(); break;
	case 0x45: eor_xav_zpg_full(); break;
	case 0x46: lsr_xav_zpg_full(); break;
	case 0x47: eork_imp_full(); break;
	case 0x48: pha_xav_imp_full(); break;
	case 0x49: eor_imm_full(); break;
	case 0x4a: lsr_acc_full(); break;
	case 0x4b: eorl_imp_full(); break;
	case 0x4c: jmp_adr_full(); break;
	case 0x4d: eor_aba_full(); break;
	case 0x4e: lsr_aba_full(); break;
	case 0x4f: eorm_imp_full(); break;
	case 0x50: bvc_rel_full(); break;
	case 0x51: eor_xav_idy_full(); break;
	case 0x52: phy_imp_full(); break;
	case 0x53: eorpa_imp_full(); break;
	case 0x54: nop_imp_full(); break;
	case 0x55: eor_xav_zpx_full(); break;
	case 0x56: lsr_xav_zpx_full(); break;
	case 0x57: eorpb_imp_full(); break;
	case 0x58: cli_imp_full(); break;
	case 0x59: eor_aby_full(); break;
	case 0x5a: nop_imp_full(); break;
	case 0x5b: spa1_imp_full(); break;
	case 0x5c: jmp_xa3_full(); break;
	case 0x5d: eor_abx_full(); break;
	case 0x5e: lsr_abx_full(); break;
	case 0x5f: spb1_imp_full(); break;
	case 0x60: rts_xav_imp_full(); break;
	case 0x61: adc_xav_idx_full(); break;
	case 0x62: nop_imp_full(); break;
	case 0x63: adcj_imp_full(); break;
	case 0x64: nop_imp_full(); break;
	case 0x65: adc_xav_zpg_full(); break;
	case 0x66: ror_xav_zpg_full(); break;
	case 0x67: adck_imp_full(); break;
	case 0x68: pla_xav_imp_full(); break;
	case 0x69: adc_imm_full(); break;
	case 0x6a: ror_acc_full(); break;
	case 0x6b: adcl_imp_full(); break;
	case 0x6c: jmp_ind_full(); break;
	case 0x6d: adc_aba_full(); break;
	case 0x6e: ror_aba_full(); break;
	case 0x6f: adcm_imp_full(); break;
	case 0x70: bvs_rel_full(); break;
	case 0x71: adc_xav_idy_full(); break;
	case 0x72: ply_imp_full(); break;
	case 0x73: adcpa_imp_full(); break;
	case 0x74: nop_imp_full(); break;
	case 0x75: adc_xav_zpx_full(); break;
	case 0x76: ror_xav_zpx_full(); break;
	case 0x77: adcpb_imp_full(); break;
	case 0x78: sei_imp_full(); break;
	case 0x79: adc_aby_full(); break;
	case 0x7a: nop_imp_full(); break;
	case 0x7b: lpa1_imp_full(); break;
	case 0x7c: jmpf_ind_full(); break;
	case 0x7d: adc_abx_full(); break;
	case 0x7e: ror_abx_full(); break;
	case 0x7f: lpb1_imp_full(); break;
	case 0x80: retf_imp_full(); break;
	case 0x81: sta_xav_idx_full(); break;
	case 0x82: stz_xav_zpg_full(); break;
	case 0x83: staj_imp_full(); break;
	case 0x84: sty_xav_zpg_full(); break;
	case 0x85: sta_xav_zpg_full(); break;
	case 0x86: stx_xav_zpg_full(); break;
	case 0x87: stak_imp_full(); break;
	case 0x88: dey_imp_full(); break;
	case 0x89: sev_imp_full(); break;
	case 0x8a: txa_imp_full(); break;
	case 0x8b: stal_imp_full(); break;
	case 0x8c: sty_aba_full(); break;
	case 0x8d: sta_aba_full(); break;
	case 0x8e: stx_aba_full(); break;
	case 0x8f: stam_imp_full(); break;
	case 0x90: bcc_rel_full(); break;
	case 0x91: sta_xav_idy_full(); break;
	case 0x92: stz_aba_full(); break;
	case 0x93: stapa_imp_full(); break;
	case 0x94: sty_xav_zpx_full(); break;
	case 0x95: sta_xav_zpx_full(); break;
	case 0x96: stx_xav_zpy_full(); break;
	case 0x97: stapb_imp_full(); break;
	case 0x98: tya_imp_full(); break;
	case 0x99: sta_aby_full(); break;
	case 0x9a: txs_imp_full(); break;
	case 0x9b: spa2_imp_full(); break;
	case 0x9c: sty_abx_full(); break;
	case 0x9d: sta_abx_full(); break;
	case 0x9e: stx_aby_full(); break;
	case 0x9f: spb2_imp_full(); break;
	case 0xa0: ldy_imm_full(); break;
	case 0xa1: lda_xav_idx_full(); break;
	case 0xa2: ldx_imm_full(); break;
	case 0xa3: ldaj_imp_full(); break;
	case 0xa4: ldy_xav_zpg_full(); break;
	case 0xa5: lda_xav_zpg_full(); break;
	case 0xa6: ldx_xav_zpg_full(); break;
	case 0xa7: ldak_imp_full(); break;
	case 0xa8: tay_imp_full(); break;
	case 0xa9: lda_imm_full(); break;
	case 0xaa: tax_imp_full(); break;
	case 0xab: ldal_imp_full(); break;
	case 0xac: ldy_aba_full(); break;
	case 0xad: lda_aba_full(); break;
	case 0xae: ldx_aba_full(); break;
	case 0xaf: ldam_imp_full(); break;
	case 0xb0: bcs_rel_full(); break;
	case 0xb1: lda_xav_idy_full(); break;
	case 0xb2: clr_acc_full(); break;
	case 0xb3: ldapa_imp_full(); break;
	case 0xb4: ldy_xav_zpx_full(); break;
	case 0xb5: lda_xav_zpx_full(); break;
	case 0xb6: ldx_xav_zpy_full(); break;
	case 0xb7: ldapb_imp_full(); break;
	case 0xb8: clv_imp_full(); break;
	case 0xb9: lda_aby_full(); break;
	case 0xba: tsx_imp_full(); break;
	case 0xbb: lpa2_imp_full(); break;
	case 0xbc: ldy_abx_full(); break;
	case 0xbd: lda_abx_full(); break;
	case 0xbe: ldx_aby_full(); break;
	case 0xbf: lpb2_imp_full(); break;
	case 0xc0: cpy_imm_full(); break;
	case 0xc1: cmp_xav_idx_full(); break;
	case 0xc2: dec_acc_full(); break;
	case 0xc3: cmpj_imp_full(); break;
	case 0xc4: cpy_xav_zpg_full(); break;
	case 0xc5: cmp_xav_zpg_full(); break;
	case 0xc6: dec_xav_zpg_full(); break;
	case 0xc7: cmpk_imp_full(); break;
	case 0xc8: iny_imp_full(); break;
	case 0xc9: cmp_imm_full(); break;
	case 0xca: dex_imp_full(); break;
	case 0xcb: cmpl_imp_full(); break;
	case 0xcc: cpy_aba_full(); break;
	case 0xcd: cmp_aba_full(); break;
	case 0xce: dec_aba_full(); break;
	case 0xcf: cmpm_imp_full(); break;
	case 0xd0: bne_rel_full(); break;
	case 0xd1: cmp_xav_idy_full(); break;
	case 0xd2: not_acc_full(); break;
	case 0xd3: cmppa_imp_full(); break;
	case 0xd4: nop_imp_full(); break;
	case 0xd5: cmp_xav_zpx_full(); break;
	case 0xd6: dec_xav_zpx_full(); break;
	case 0xd7: cmppb_imp_full(); break;
	case 0xd8: cld_imp_full(); break;
	case 0xd9: cmp_aby_full(); break;
	case 0xda: nop_imp_full(); break;
	case 0xdb: decpa_imp_full(); break;
	case 0xdc: nop_imp_full(); break;
	case 0xdd: cmp_abx_full(); break;
	case 0xde: dec_abx_full(); break;
	case 0xdf: decpb_imp_full(); break;
	case 0xe0: cpx_imm_full(); break;
	case 0xe1: sbc_xav_idx_full(); break;
	case 0xe2: inc_acc_full(); break;
	case 0xe3: sbcj_imp_full(); break;
	case 0xe4: cpx_xav_zpg_full(); break;
	case 0xe5: sbc_xav_zpg_full(); break;
	case 0xe6: inc_xav_zpg_full(); break;
	case 0xe7: sbck_imp_full(); break;
	case 0xe8: inx_imp_full(); break;
	case 0xe9: sbc_imm_full(); break;
	case 0xea: nop_imp_full(); break;
	case 0xeb: sbcl_imp_full(); break;
	case 0xec: cpx_aba_full(); break;
	case 0xed: sbc_aba_full(); break;
	case 0xee: inc_aba_full(); break;
	case 0xef: sbcm_imp_full(); break;
	case 0xf0: beq_rel_full(); break;
	case 0xf1: sbc_xav_idy_full(); break;
	case 0xf2: neg_acc_full(); break;
	case 0xf3: sbcpa_imp_full(); break;
	case 0xf4: nop_imp_full(); break;
	case 0xf5: sbc_xav_zpx_full(); break;
	case 0xf6: inc_xav_zpx_full(); break;
	case 0xf7: sbcpb_imp_full(); break;
	case 0xf8: sed_imp_full(); break;
	case 0xf9: sbc_aby_full(); break;
	case 0xfa: nop_imp_full(); break;
	case 0xfb: incpa_imp_full(); break;
	case 0xfc: nop_imp_full(); break;
	case 0xfd: sbc_abx_full(); break;
	case 0xfe: inc_abx_full(); break;
	case 0xff: incpb_imp_full(); break;
	case STATE_RESET: reset_full(); break;
	}
}

void xavix2000_device::do_exec_partial()
{
	switch(inst_state) {

	case 0x00: brk_xav_imp_partial(); break;
	case 0x01: ora_xav_idx_partial(); break;
	case 0x02: cmc_imp_partial(); break;
	case 0x03: oraj_imp_partial(); break;
	case 0x04: asr_xav_zpg_partial(); break;
	case 0x05: ora_xav_zpg_partial(); break;
	case 0x06: asl_xav_zpg_partial(); break;
	case 0x07: orak_imp_partial(); break;
	case 0x08: php_xav_imp_partial(); break;
	case 0x09: ora_imm_partial(); break;
	case 0x0a: asl_acc_partial(); break;
	case 0x0b: oral_imp_partial(); break;
	case 0x0c: asr_aba_partial(); break;
	case 0x0d: ora_aba_partial(); break;
	case 0x0e: asl_aba_partial(); break;
	case 0x0f: oram_imp_partial(); break;
	case 0x10: bpl_rel_partial(); break;
	case 0x11: ora_xav_idy_partial(); break;
	case 0x12: phx_imp_partial(); break;
	case 0x13: orapa_imp_partial(); break;
	case 0x14: asr_xav_zpx_partial(); break;
	case 0x15: ora_xav_zpx_partial(); break;
	case 0x16: asl_xav_zpx_partial(); break;
	case 0x17: orapb_imp_partial(); break;
	case 0x18: clc_imp_partial(); break;
	case 0x19: ora_aby_partial(); break;
	case 0x1a: asr_acc_partial(); break;
	case 0x1b: spa0_imp_partial(); break;
	case 0x1c: asr_abx_partial(); break;
	case 0x1d: ora_abx_partial(); break;
	case 0x1e: asl_abx_partial(); break;
	case 0x1f: spb0_imp_partial(); break;
	case 0x20: jsr_xav_adr_partial(); break;
	case 0x21: and_xav_idx_partial(); break;
	case 0x22: callf_xa3_partial(); break;
	case 0x23: andj_imp_partial(); break;
	case 0x24: bit_xav_zpg_partial(); break;
	case 0x25: and_xav_zpg_partial(); break;
	case 0x26: rol_xav_zpg_partial(); break;
	case 0x27: andk_imp_partial(); break;
	case 0x28: plp_xav_imp_partial(); break;
	case 0x29: and_imm_partial(); break;
	case 0x2a: rol_acc_partial(); break;
	case 0x2b: andl_imp_partial(); break;
	case 0x2c: bit_aba_partial(); break;
	case 0x2d: and_aba_partial(); break;
	case 0x2e: rol_aba_partial(); break;
	case 0x2f: andm_imp_partial(); break;
	case 0x30: bmi_rel_partial(); break;
	case 0x31: and_xav_idy_partial(); break;
	case 0x32: plx_imp_partial(); break;
	case 0x33: andpa_imp_partial(); break;
	case 0x34: bit_xav_zpx_partial(); break;
	case 0x35: and_xav_zpx_partial(); break;
	case 0x36: rol_xav_zpx_partial(); break;
	case 0x37: andpb_imp_partial(); break;
	case 0x38: sec_imp_partial(); break;
	case 0x39: and_aby_partial(); break;
	case 0x3a: bit_imm_partial(); break;
	case 0x3b: lpa0_imp_partial(); break;
	case 0x3c: bit_abx_partial(); break;
	case 0x3d: and_abx_partial(); break;
	case 0x3e: rol_abx_partial(); break;
	case 0x3f: lpb0_imp_partial(); break;
	case 0x40: rti_xav_imp_partial(); break;
	case 0x41: eor_xav_idx_partial(); break;
	case 0x42: nop_imp_partial(); break;
	case 0x43: eorj_imp_partial(); break;
	case 0x44: nop_imp_partial(); break;
	case 0x45: eor_xav_zpg_partial(); break;
	case 0x46: lsr_xav_zpg_partial(); break;
	case 0x47: eork_imp_partial(); break;
	case 0x48: pha_xav_imp_partial(); break;
	case 0x49: eor_imm_partial(); break;
	case 0x4a: lsr_acc_partial(); break;
	case 0x4b: eorl_imp_partial(); break;
	case 0x4c: jmp_adr_partial(); break;
	case 0x4d: eor_aba_partial(); break;
	case 0x4e: lsr_aba_partial(); break;
	case 0x4f: eorm_imp_partial(); break;
	case 0x50: bvc_rel_partial(); break;
	case 0x51: eor_xav_idy_partial(); break;
	case 0x52: phy_imp_partial(); break;
	case 0x53: eorpa_imp_partial(); break;
	case 0x54: nop_imp_partial(); break;
	case 0x55: eor_xav_zpx_partial(); break;
	case 0x56: lsr_xav_zpx_partial(); break;
	case 0x57: eorpb_imp_partial(); break;
	case 0x58: cli_imp_partial(); break;
	case 0x59: eor_aby_partial(); break;
	case 0x5a: nop_imp_partial(); break;
	case 0x5b: spa1_imp_partial(); break;
	case 0x5c: jmp_xa3_partial(); break;
	case 0x5d: eor_abx_partial(); break;
	case 0x5e: lsr_abx_partial(); break;
	case 0x5f: spb1_imp_partial(); break;
	case 0x60: rts_xav_imp_partial(); break;
	case 0x61: adc_xav_idx_partial(); break;
	case 0x62: nop_imp_partial(); break;
	case 0x63: adcj_imp_partial(); break;
	case 0x64: nop_imp_partial(); break;
	case 0x65: adc_xav_zpg_partial(); break;
	case 0x66: ror_xav_zpg_partial(); break;
	case 0x67: adck_imp_partial(); break;
	case 0x68: pla_xav_imp_partial(); break;
	case 0x69: adc_imm_partial(); break;
	case 0x6a: ror_acc_partial(); break;
	case 0x6b: adcl_imp_partial(); break;
	case 0x6c: jmp_ind_partial(); break;
	case 0x6d: adc_aba_partial(); break;
	case 0x6e: ror_aba_partial(); break;
	case 0x6f: adcm_imp_partial(); break;
	case 0x70: bvs_rel_partial(); break;
	case 0x71: adc_xav_idy_partial(); break;
	case 0x72: ply_imp_partial(); break;
	case 0x73: adcpa_imp_partial(); break;
	case 0x74: nop_imp_partial(); break;
	case 0x75: adc_xav_zpx_partial(); break;
	case 0x76: ror_xav_zpx_partial(); break;
	case 0x77: adcpb_imp_partial(); break;
	case 0x78: sei_imp_partial(); break;
	case 0x79: adc_aby_partial(); break;
	case 0x7a: nop_imp_partial(); break;
	case 0x7b: lpa1_imp_partial(); break;
	case 0x7c: jmpf_ind_partial(); break;
	case 0x7d: adc_abx_partial(); break;
	case 0x7e: ror_abx_partial(); break;
	case 0x7f: lpb1_imp_partial(); break;
	case 0x80: retf_imp_partial(); break;
	case 0x81: sta_xav_idx_partial(); break;
	case 0x82: stz_xav_zpg_partial(); break;
	case 0x83: staj_imp_partial(); break;
	case 0x84: sty_xav_zpg_partial(); break;
	case 0x85: sta_xav_zpg_partial(); break;
	case 0x86: stx_xav_zpg_partial(); break;
	case 0x87: stak_imp_partial(); break;
	case 0x88: dey_imp_partial(); break;
	case 0x89: sev_imp_partial(); break;
	case 0x8a: txa_imp_partial(); break;
	case 0x8b: stal_imp_partial(); break;
	case 0x8c: sty_aba_partial(); break;
	case 0x8d: sta_aba_partial(); break;
	case 0x8e: stx_aba_partial(); break;
	case 0x8f: stam_imp_partial(); break;
	case 0x90: bcc_rel_partial(); break;
	case 0x91: sta_xav_idy_partial(); break;
	case 0x92: stz_aba_partial(); break;
	case 0x93: stapa_imp_partial(); break;
	case 0x94: sty_xav_zpx_partial(); break;
	case 0x95: sta_xav_zpx_partial(); break;
	case 0x96: stx_xav_zpy_partial(); break;
	case 0x97: stapb_imp_partial(); break;
	case 0x98: tya_imp_partial(); break;
	case 0x99: sta_aby_partial(); break;
	case 0x9a: txs_imp_partial(); break;
	case 0x9b: spa2_imp_partial(); break;
	case 0x9c: sty_abx_partial(); break;
	case 0x9d: sta_abx_partial(); break;
	case 0x9e: stx_aby_partial(); break;
	case 0x9f: spb2_imp_partial(); break;
	case 0xa0: ldy_imm_partial(); break;
	case 0xa1: lda_xav_idx_partial(); break;
	case 0xa2: ldx_imm_partial(); break;
	case 0xa3: ldaj_imp_partial(); break;
	case 0xa4: ldy_xav_zpg_partial(); break;
	case 0xa5: lda_xav_zpg_partial(); break;
	case 0xa6: ldx_xav_zpg_partial(); break;
	case 0xa7: ldak_imp_partial(); break;
	case 0xa8: tay_imp_partial(); break;
	case 0xa9: lda_imm_partial(); break;
	case 0xaa: tax_imp_partial(); break;
	case 0xab: ldal_imp_partial(); break;
	case 0xac: ldy_aba_partial(); break;
	case 0xad: lda_aba_partial(); break;
	case 0xae: ldx_aba_partial(); break;
	case 0xaf: ldam_imp_partial(); break;
	case 0xb0: bcs_rel_partial(); break;
	case 0xb1: lda_xav_idy_partial(); break;
	case 0xb2: clr_acc_partial(); break;
	case 0xb3: ldapa_imp_partial(); break;
	case 0xb4: ldy_xav_zpx_partial(); break;
	case 0xb5: lda_xav_zpx_partial(); break;
	case 0xb6: ldx_xav_zpy_partial(); break;
	case 0xb7: ldapb_imp_partial(); break;
	case 0xb8: clv_imp_partial(); break;
	case 0xb9: lda_aby_partial(); break;
	case 0xba: tsx_imp_partial(); break;
	case 0xbb: lpa2_imp_partial(); break;
	case 0xbc: ldy_abx_partial(); break;
	case 0xbd: lda_abx_partial(); break;
	case 0xbe: ldx_aby_partial(); break;
	case 0xbf: lpb2_imp_partial(); break;
	case 0xc0: cpy_imm_partial(); break;
	case 0xc1: cmp_xav_idx_partial(); break;
	case 0xc2: dec_acc_partial(); break;
	case 0xc3: cmpj_imp_partial(); break;
	case 0xc4: cpy_xav_zpg_partial(); break;
	case 0xc5: cmp_xav_zpg_partial(); break;
	case 0xc6: dec_xav_zpg_partial(); break;
	case 0xc7: cmpk_imp_partial(); break;
	case 0xc8: iny_imp_partial(); break;
	case 0xc9: cmp_imm_partial(); break;
	case 0xca: dex_imp_partial(); break;
	case 0xcb: cmpl_imp_partial(); break;
	case 0xcc: cpy_aba_partial(); break;
	case 0xcd: cmp_aba_partial(); break;
	case 0xce: dec_aba_partial(); break;
	case 0xcf: cmpm_imp_partial(); break;
	case 0xd0: bne_rel_partial(); break;
	case 0xd1: cmp_xav_idy_partial(); break;
	case 0xd2: not_acc_partial(); break;
	case 0xd3: cmppa_imp_partial(); break;
	case 0xd4: nop_imp_partial(); break;
	case 0xd5: cmp_xav_zpx_partial(); break;
	case 0xd6: dec_xav_zpx_partial(); break;
	case 0xd7: cmppb_imp_partial(); break;
	case 0xd8: cld_imp_partial(); break;
	case 0xd9: cmp_aby_partial(); break;
	case 0xda: nop_imp_partial(); break;
	case 0xdb: decpa_imp_partial(); break;
	case 0xdc: nop_imp_partial(); break;
	case 0xdd: cmp_abx_partial(); break;
	case 0xde: dec_abx_partial(); break;
	case 0xdf: decpb_imp_partial(); break;
	case 0xe0: cpx_imm_partial(); break;
	case 0xe1: sbc_xav_idx_partial(); break;
	case 0xe2: inc_acc_partial(); break;
	case 0xe3: sbcj_imp_partial(); break;
	case 0xe4: cpx_xav_zpg_partial(); break;
	case 0xe5: sbc_xav_zpg_partial(); break;
	case 0xe6: inc_xav_zpg_partial(); break;
	case 0xe7: sbck_imp_partial(); break;
	case 0xe8: inx_imp_partial(); break;
	case 0xe9: sbc_imm_partial(); break;
	case 0xea: nop_imp_partial(); break;
	case 0xeb: sbcl_imp_partial(); break;
	case 0xec: cpx_aba_partial(); break;
	case 0xed: sbc_aba_partial(); break;
	case 0xee: inc_aba_partial(); break;
	case 0xef: sbcm_imp_partial(); break;
	case 0xf0: beq_rel_partial(); break;
	case 0xf1: sbc_xav_idy_partial(); break;
	case 0xf2: neg_acc_partial(); break;
	case 0xf3: sbcpa_imp_partial(); break;
	case 0xf4: nop_imp_partial(); break;
	case 0xf5: sbc_xav_zpx_partial(); break;
	case 0xf6: inc_xav_zpx_partial(); break;
	case 0xf7: sbcpb_imp_partial(); break;
	case 0xf8: sed_imp_partial(); break;
	case 0xf9: sbc_aby_partial(); break;
	case 0xfa: nop_imp_partial(); break;
	case 0xfb: incpa_imp_partial(); break;
	case 0xfc: nop_imp_partial(); break;
	case 0xfd: sbc_abx_partial(); break;
	case 0xfe: inc_abx_partial(); break;
	case 0xff: incpb_imp_partial(); break;
	case STATE_RESET: reset_partial(); break;
	}
}

