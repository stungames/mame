void gt913_device::ldbank_r8l_bankl_full()
{
	TMP1 = r8_r(IR[0]) & 0x3f;
	m_banknum = (m_banknum & 0xffc0) | TMP1;
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void gt913_device::ldbank_r8l_bankl_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r8_r(IR[0]) & 0x3f;
	m_banknum = (m_banknum & 0xffc0) | TMP1;
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void gt913_device::ldbank_r8l_bankh_full()
{
	TMP1 = r8_r(IR[0]) & 0x3f;
	m_banknum = (TMP1 << 6) | (m_banknum & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void gt913_device::ldbank_r8l_bankh_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r8_r(IR[0]) & 0x3f;
	m_banknum = (TMP1 << 6) | (m_banknum & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void gt913_device::ldc_imm6l_ccr_full()
{
	CCR = IR[0] & 0x3f;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void gt913_device::ldc_imm6l_ccr_partial()
{
switch(inst_substate) {
case 0:
	CCR = IR[0] & 0x3f;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void gt913_device::ldbank_imm6l_bankl_full()
{
	m_banknum = (m_banknum & 0xffc0) | (IR[0] & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void gt913_device::ldbank_imm6l_bankl_partial()
{
switch(inst_substate) {
case 0:
	m_banknum = (m_banknum & 0xffc0) | (IR[0] & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void gt913_device::ldbank_imm6l_bankh_full()
{
	m_banknum = ((IR[0] & 0x3f) << 6) | (m_banknum & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void gt913_device::ldbank_imm6l_bankh_partial()
{
switch(inst_substate) {
case 0:
	m_banknum = ((IR[0] & 0x3f) << 6) | (m_banknum & 0x3f);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void gt913_device::jmp_abs22e_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	internal(1);
	m_banknum = ((IR[0] & 0x3f) << 2) | (IR[1] >> 14);
	PC = 0x8000 | (IR[1] & 0x3fff);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void gt913_device::jmp_abs22e_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	internal(1);
	m_banknum = ((IR[0] & 0x3f) << 2) | (IR[1] >> 14);
	PC = 0x8000 | (IR[1] & 0x3fff);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r16ih_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read8ib(r16_r(IR[0] >> 4));
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
}

void gt913_device::mov_b_r16ih_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read8ib(r16_r(IR[0] >> 4));
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16ih_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16ib(r16_r(IR[0] >> 4));
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
}

void gt913_device::mov_w_r16ih_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16ib(r16_r(IR[0] >> 4));
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r16ph_r8l_full()
{
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(2);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read8ib(TMP2);
	TMP2 += 1;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
}

void gt913_device::mov_b_r16ph_r8l_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read8ib(TMP2);
	TMP2 += 1;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16ph_r16l_full()
{
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(2);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16ib(TMP2);
	TMP2 += 2;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
}

void gt913_device::mov_w_r16ph_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16ib(TMP2);
	TMP2 += 2;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r16d16h_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read8ib(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[0], TMP2);
	prefetch_done();
}

void gt913_device::mov_b_r16d16h_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read8ib(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[0], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16d16h_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16ib(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[0], TMP2);
	prefetch_done();
}

void gt913_device::mov_w_r16d16h_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16ib(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[0], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r8l_r16ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write8ib(r16_r(IR[0] >> 4), TMP1);
	prefetch_done();
}

void gt913_device::mov_b_r8l_r16ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write8ib(r16_r(IR[0] >> 4), TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16l_r16ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16ib(r16_r(IR[0] >> 4), TMP1);
	prefetch_done();
}

void gt913_device::mov_w_r16l_r16ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16ib(r16_r(IR[0] >> 4), TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r8l_pr16h_full()
{
	TMP1 = r8_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP2 -= 1;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write8ib(TMP2, TMP1);
	prefetch_done();
}

void gt913_device::mov_b_r8l_pr16h_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r8_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP2 -= 1;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write8ib(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16l_pr16h_full()
{
	TMP1 = r16_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP2 -= 2;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16ib(TMP2, TMP1);
	prefetch_done();
}

void gt913_device::mov_w_r16l_pr16h_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r16_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP2 -= 2;
	r16_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16ib(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_b_r8l_r16d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	TMP2 = r8_r(IR[0]);
	set_nzv8(TMP2);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8ib(TMP1, TMP2);
	prefetch_done();
}

void gt913_device::mov_b_r8l_r16d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	TMP2 = r8_r(IR[0]);
	set_nzv8(TMP2);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8ib(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::mov_w_r16l_r16d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	TMP2 = r16_r(IR[0]);
	set_nzv16(TMP2);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16ib(TMP1, TMP2);
	prefetch_done();
}

void gt913_device::mov_w_r16l_r16d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = uint16_t(r16_r(IR[0] >> 4) + IR[1]);
	TMP2 = r16_r(IR[0]);
	set_nzv16(TMP2);
	internal(1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16ib(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6000_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x20000 | IR[1];
}

void gt913_device::dispatch_6000_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x20000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6100_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x30000 | IR[1];
}

void gt913_device::dispatch_6100_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x30000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6200_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x40000 | IR[1];
}

void gt913_device::dispatch_6200_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x40000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6300_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x50000 | IR[1];
}

void gt913_device::dispatch_6300_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x50000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6400_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x60000 | IR[1];
}

void gt913_device::dispatch_6400_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x60000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6500_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x70000 | IR[1];
}

void gt913_device::dispatch_6500_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x70000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6600_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x80000 | IR[1];
}

void gt913_device::dispatch_6600_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x80000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_6700_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x90000 | IR[1];
}

void gt913_device::dispatch_6700_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x90000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7000_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xa0000 | IR[1];
}

void gt913_device::dispatch_7000_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xa0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7100_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xb0000 | IR[1];
}

void gt913_device::dispatch_7100_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xb0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7200_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xc0000 | IR[1];
}

void gt913_device::dispatch_7200_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xc0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7300_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xd0000 | IR[1];
}

void gt913_device::dispatch_7300_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xd0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7400_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xe0000 | IR[1];
}

void gt913_device::dispatch_7400_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xe0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7500_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0xf0000 | IR[1];
}

void gt913_device::dispatch_7500_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0xf0000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7600_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x100000 | IR[1];
}

void gt913_device::dispatch_7600_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x100000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::dispatch_7700_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	IR[1] = fetch();
	inst_state = 0x110000 | IR[1];
}

void gt913_device::dispatch_7700_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	IR[1] = fetch();
	inst_state = 0x110000 | IR[1];
	break;
}
	inst_substate = 0;
}

void gt913_device::do_exec_full()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: sleep_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x40: stc_ccr_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x40: ldc_r8l_ccr_full(); break;
			case 0x80: ldbank_r8l_bankl_full(); break;
			case 0xc0: ldbank_r8l_bankh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_full();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_full();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_full();
			break;
		}
		case 0x07: {
			switch(inst_state & 0xc0) {
			case 0x40: ldc_imm6l_ccr_full(); break;
			case 0x80: ldbank_imm6l_bankl_full(); break;
			case 0xc0: ldbank_imm6l_bankh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_full();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_full();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf0) {
			case 0x00: inc_b_one_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r16l_full(); break;
			case 0x80: adds_l_two_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_full();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_full();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_full();
			break;
		}
		case 0x0f: {
			mulxu_b_r8h_r16l_full();
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf0) {
			case 0x00: shll_b_r8l_full(); break;
			case 0x80: shal_b_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf0) {
			case 0x00: shlr_b_r8l_full(); break;
			case 0x80: shar_b_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf0) {
			case 0x00: rotxl_b_r8l_full(); break;
			case 0x80: rotl_b_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf0) {
			case 0x00: rotxr_b_r8l_full(); break;
			case 0x80: rotr_b_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_full();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_full();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_full();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf0) {
			case 0x00: not_b_r8l_full(); break;
			case 0x80: neg_b_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_full();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_full();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf0) {
			case 0x00: dec_b_one_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_two_r16l_full(); break;
			case 0x80: subs_l_one_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_full();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_full();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_full();
			break;
		}
		case 0x1f: {
			divxu_b_r8h_r16l_full();
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_full();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_full();
			break;
		}
		case 0x40: {
			bt_rel8_full();
			break;
		}
		case 0x41: {
			bf_rel8_full();
			break;
		}
		case 0x42: {
			bhi_rel8_full();
			break;
		}
		case 0x43: {
			bls_rel8_full();
			break;
		}
		case 0x44: {
			bcc_rel8_full();
			break;
		}
		case 0x45: {
			bcs_rel8_full();
			break;
		}
		case 0x46: {
			bne_rel8_full();
			break;
		}
		case 0x47: {
			beq_rel8_full();
			break;
		}
		case 0x48: {
			bvc_rel8_full();
			break;
		}
		case 0x49: {
			bvs_rel8_full();
			break;
		}
		case 0x4a: {
			bpl_rel8_full();
			break;
		}
		case 0x4b: {
			bmi_rel8_full();
			break;
		}
		case 0x4c: {
			bge_rel8_full();
			break;
		}
		case 0x4d: {
			blt_rel8_full();
			break;
		}
		case 0x4e: {
			bgt_rel8_full();
			break;
		}
		case 0x4f: {
			ble_rel8_full();
			break;
		}
		case 0x50: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x51: {
			bset_r8h_r8l_full();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			bclr_r8h_r8l_full();
			break;
		}
		case 0x54: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bnot_r8h_r8l_full();
			break;
		}
		case 0x56: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			btst_r8h_r8l_full();
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: rts_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x80: rte_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x10: case 0x20: case 0x30: case 0x40: case 0x50: case 0x60: case 0x70: jmp_r16h_full(); break;
			case 0x80: jmp_abs16e_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5b: {
			switch(inst_state & 0xc0) {
			case 0x80: jmp_abs22e_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x10: case 0x20: case 0x30: case 0x40: case 0x50: case 0x60: case 0x70: jsr_r16h_full(); break;
			case 0x80: jsr_abs16e_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			bsr_rel8_full();
			break;
		}
		case 0x5f: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x60: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6000_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6100_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6200_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x63: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6300_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x64: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6400_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6500_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6600_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6700_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16ih_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16ih_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16ph_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16ph_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_b_abs16_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16d16h_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r16d16h_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			dispatch_7000_full();
			break;
		}
		case 0x71: {
			dispatch_7100_full();
			break;
		}
		case 0x72: {
			dispatch_7200_full();
			break;
		}
		case 0x73: {
			dispatch_7300_full();
			break;
		}
		case 0x74: {
			dispatch_7400_full();
			break;
		}
		case 0x75: {
			dispatch_7500_full();
			break;
		}
		case 0x76: {
			dispatch_7600_full();
			break;
		}
		case 0x77: {
			dispatch_7700_full();
			break;
		}
		case 0x78: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_r16ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16l_r16ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_pr16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16l_pr16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_b_r8l_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_r16l_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_r16d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r16l_r16d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_full();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_full();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_full();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_full();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_full();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_full();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_full();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_full();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_full(); break;
		case 0x01: state_irq_full(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x04: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x05: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x06: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r16ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0d: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x10: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
void gt913_device::do_exec_partial()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: sleep_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x40: stc_ccr_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x40: ldc_r8l_ccr_partial(); break;
			case 0x80: ldbank_r8l_bankl_partial(); break;
			case 0xc0: ldbank_r8l_bankh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_partial();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_partial();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_partial();
			break;
		}
		case 0x07: {
			switch(inst_state & 0xc0) {
			case 0x40: ldc_imm6l_ccr_partial(); break;
			case 0x80: ldbank_imm6l_bankl_partial(); break;
			case 0xc0: ldbank_imm6l_bankh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_partial();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_partial();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf0) {
			case 0x00: inc_b_one_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r16l_partial(); break;
			case 0x80: adds_l_two_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_partial();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_partial();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_partial();
			break;
		}
		case 0x0f: {
			mulxu_b_r8h_r16l_partial();
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf0) {
			case 0x00: shll_b_r8l_partial(); break;
			case 0x80: shal_b_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf0) {
			case 0x00: shlr_b_r8l_partial(); break;
			case 0x80: shar_b_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf0) {
			case 0x00: rotxl_b_r8l_partial(); break;
			case 0x80: rotl_b_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf0) {
			case 0x00: rotxr_b_r8l_partial(); break;
			case 0x80: rotr_b_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_partial();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_partial();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_partial();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf0) {
			case 0x00: not_b_r8l_partial(); break;
			case 0x80: neg_b_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_partial();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_partial();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf0) {
			case 0x00: dec_b_one_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_two_r16l_partial(); break;
			case 0x80: subs_l_one_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_partial();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_partial();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_partial();
			break;
		}
		case 0x1f: {
			divxu_b_r8h_r16l_partial();
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_partial();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_partial();
			break;
		}
		case 0x40: {
			bt_rel8_partial();
			break;
		}
		case 0x41: {
			bf_rel8_partial();
			break;
		}
		case 0x42: {
			bhi_rel8_partial();
			break;
		}
		case 0x43: {
			bls_rel8_partial();
			break;
		}
		case 0x44: {
			bcc_rel8_partial();
			break;
		}
		case 0x45: {
			bcs_rel8_partial();
			break;
		}
		case 0x46: {
			bne_rel8_partial();
			break;
		}
		case 0x47: {
			beq_rel8_partial();
			break;
		}
		case 0x48: {
			bvc_rel8_partial();
			break;
		}
		case 0x49: {
			bvs_rel8_partial();
			break;
		}
		case 0x4a: {
			bpl_rel8_partial();
			break;
		}
		case 0x4b: {
			bmi_rel8_partial();
			break;
		}
		case 0x4c: {
			bge_rel8_partial();
			break;
		}
		case 0x4d: {
			blt_rel8_partial();
			break;
		}
		case 0x4e: {
			bgt_rel8_partial();
			break;
		}
		case 0x4f: {
			ble_rel8_partial();
			break;
		}
		case 0x50: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x51: {
			bset_r8h_r8l_partial();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			bclr_r8h_r8l_partial();
			break;
		}
		case 0x54: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bnot_r8h_r8l_partial();
			break;
		}
		case 0x56: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			btst_r8h_r8l_partial();
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: rts_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x80: rte_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x10: case 0x20: case 0x30: case 0x40: case 0x50: case 0x60: case 0x70: jmp_r16h_partial(); break;
			case 0x80: jmp_abs16e_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5b: {
			switch(inst_state & 0xc0) {
			case 0x80: jmp_abs22e_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x10: case 0x20: case 0x30: case 0x40: case 0x50: case 0x60: case 0x70: jsr_r16h_partial(); break;
			case 0x80: jsr_abs16e_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			bsr_rel8_partial();
			break;
		}
		case 0x5f: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x60: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6000_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6100_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6200_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x63: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6300_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x64: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6400_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6500_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6600_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_6700_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16ih_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16ih_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16ph_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16ph_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_b_abs16_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r16d16h_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r16d16h_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			dispatch_7000_partial();
			break;
		}
		case 0x71: {
			dispatch_7100_partial();
			break;
		}
		case 0x72: {
			dispatch_7200_partial();
			break;
		}
		case 0x73: {
			dispatch_7300_partial();
			break;
		}
		case 0x74: {
			dispatch_7400_partial();
			break;
		}
		case 0x75: {
			dispatch_7500_partial();
			break;
		}
		case 0x76: {
			dispatch_7600_partial();
			break;
		}
		case 0x77: {
			dispatch_7700_partial();
			break;
		}
		case 0x78: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_r16ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16l_r16ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_pr16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0x88) {
			case 0x00: mov_w_r16l_pr16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_b_r8l_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_r16l_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r8l_r16d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r16l_r16d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_partial();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_partial();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_partial();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_partial();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_partial();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_partial();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_partial();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_partial();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_partial(); break;
		case 0x01: state_irq_partial(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x04: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x05: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x06: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r16ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0d: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x10: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
