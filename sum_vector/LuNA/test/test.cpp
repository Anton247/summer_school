#include "ucenv.h"

extern "C" void c_init(int, OutputDF &); // as init
extern "C" void c_initVA(OutputDF &, int, int); // as initVA
extern "C" void c_initVB(OutputDF &, int, int); // as initVB
extern "C" void partialSum(const InputDF &, const InputDF &, OutputDF &, int); // as partialSum
extern "C" void c_print(const InputDF &); // as print
extern "C" void c_vprint(const InputDF &, int); // as vprint

// MAIN
BlockRetStatus block_0(CF &self)
{

	self.NextBlock=1;
	return CONTINUE;
}

// STRUCT: sub main()
BlockRetStatus block_1(CF &self)
{
	Id _id_0=self.create_id(); // length
	Id _id_1=self.create_id(); // size
	Id _id_2=self.create_id(); // A
	Id _id_3=self.create_id(); // B
	Id _id_4=self.create_id(); // C
	Id _id_5=self.create_id(); // x

// GEN BODY: sub main()
	{ // FORK_BI: cf _l20: init(4, length);
		CF *child=self.fork(2);
		child->id(0)=_id_0;
	}

	{ // FORK_BI: cf _l21: init(4, size);
		CF *child=self.fork(3);
		child->id(0)=_id_1;
	}

	{ // FORK_BI: for n=0..(size)-(1);
		CF *child=self.fork(4);
		child->id(0)=_id_1;
		child->id(1)=_id_0;
		child->id(2)=_id_2;
		child->id(3)=_id_3;
		child->id(4)=_id_4;
	}

	{ // FORK_BI: cf _l29: vprint(C[0], length);
		CF *child=self.fork(16);
		child->id(0)=_id_0;
		child->id(1)=_id_4;
		child->id(2)=_id_5;
	}

	{ // FORK_BI: for n=1..(size)-(1);
		CF *child=self.fork(19);
		child->id(0)=_id_1;
		child->id(1)=_id_5;
		child->id(2)=_id_4;
		child->id(3)=_id_0;
	}

	return EXIT;
}

// BI_EXEC: cf _l20: init(4, length);
BlockRetStatus block_2(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l20: init(4, length);
		c_init(
			// int 4
			4, 
			// name length
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0), stored);
		}
	}

	// req_unlimited: length
	{		DF posted=self.wait(self.id(0));
	self.post(self.id(0), posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l21: init(4, size);
BlockRetStatus block_3(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l21: init(4, size);
		c_init(
			// int 4
			4, 
			// name size
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0), stored);
		}
	}

	// req_unlimited: size
	{		DF posted=self.wait(self.id(0));
	self.post(self.id(0), posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_FOR: for n = 0 .. (size)-(1)
BlockRetStatus block_4(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=5;
	return CONTINUE;
}

// Request : for n = 0 .. (size)-(1)
BlockRetStatus block_5(CF &self)
{
	// wait size
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=6;
	return CONTINUE;
}

// After requests: for n = 0 .. (size)-(1)
BlockRetStatus block_6(CF &self)
{
	for (int _lc_n=0; _lc_n<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_n++) {

// GEN BODY: for n = 0 .. (size)-(1)
	{ // FORK_BI: cf _l24: initVA(A[n], length, n);
		CF *child=self.fork(7);
		child->arg(0)=_lc_n;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	{ // FORK_BI: cf _l25: initVB(B[n], length, n);
		CF *child=self.fork(10);
		child->arg(0)=_lc_n;
		child->id(0)=self.id(1);
		child->id(1)=self.id(3);
	}

	{ // FORK_BI: cf _l26: partialSum(A[n], B[n], C[n], length);
		CF *child=self.fork(13);
		child->arg(0)=_lc_n;
		child->id(0)=self.id(3);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
		child->id(3)=self.id(4);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l24: initVA(A[n], length, n);
BlockRetStatus block_7(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request length
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=8;
	return CONTINUE;
}

// Request : cf _l24: initVA(A[n], length, n);
BlockRetStatus block_8(CF &self)
{
	// wait length
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=9;
	return CONTINUE;
}

// After requests: cf _l24: initVA(A[n], length, n);
BlockRetStatus block_9(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l24: initVA(A[n], length, n);
		c_initVA(
			// name A[n]
			_out_0, 
			// int length
			(self.wait(self.id(0))).get_int(), 
			// int n
			self.arg(0).get_int());

		{
			DF stored=_out_0;
			self.store(self.id(1)[self.arg(0).get_int()], stored);
		}
	}

	// req_unlimited: A[n]
	{		DF posted=self.wait(self.id(1)[self.arg(0).get_int()]);
	self.post(self.id(1)[self.arg(0).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l25: initVB(B[n], length, n);
BlockRetStatus block_10(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request length
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=11;
	return CONTINUE;
}

// Request : cf _l25: initVB(B[n], length, n);
BlockRetStatus block_11(CF &self)
{
	// wait length
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=12;
	return CONTINUE;
}

// After requests: cf _l25: initVB(B[n], length, n);
BlockRetStatus block_12(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l25: initVB(B[n], length, n);
		c_initVB(
			// name B[n]
			_out_0, 
			// int length
			(self.wait(self.id(0))).get_int(), 
			// int n
			self.arg(0).get_int());

		{
			DF stored=_out_0;
			self.store(self.id(1)[self.arg(0).get_int()], stored);
		}
	}

	// req_unlimited: B[n]
	{		DF posted=self.wait(self.id(1)[self.arg(0).get_int()]);
	self.post(self.id(1)[self.arg(0).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l26: partialSum(A[n], B[n], C[n], length);
BlockRetStatus block_13(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request B[n]
	self.request(self.id(0)[self.arg(0).get_int()], CyclicLocator(0));
	// request length
	self.request(self.id(1), CyclicLocator(0));
	// request A[n]
	self.request(self.id(2)[self.arg(0).get_int()], CyclicLocator(0));

	self.NextBlock=14;
	return CONTINUE;
}

// Request : cf _l26: partialSum(A[n], B[n], C[n], length);
BlockRetStatus block_14(CF &self)
{
	// wait B[n]
	if (self.wait(self.id(0)[self.arg(0).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait length
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait A[n]
	if (self.wait(self.id(2)[self.arg(0).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=15;
	return CONTINUE;
}

// After requests: cf _l26: partialSum(A[n], B[n], C[n], length);
BlockRetStatus block_15(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l26: partialSum(A[n], B[n], C[n], length);
		partialSum(
			// value A[n]
			self.wait(self.id(2)[self.arg(0).get_int()]), 
			// value B[n]
			self.wait(self.id(0)[self.arg(0).get_int()]), 
			// name C[n]
			_out_0, 
			// int length
			(self.wait(self.id(1))).get_int());

		{
			DF stored=_out_0;
			self.store(self.id(3)[self.arg(0).get_int()], stored);
		}
	}

	// req_unlimited: C[n]
	{		DF posted=self.wait(self.id(3)[self.arg(0).get_int()]);
	self.post(self.id(3)[self.arg(0).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l29: vprint(C[0], length);
BlockRetStatus block_16(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request length
	self.request(self.id(0), CyclicLocator(0));
	// request C[0]
	self.request(self.id(1)[0], CyclicLocator(0));

	self.NextBlock=17;
	return CONTINUE;
}

// Request : cf _l29: vprint(C[0], length);
BlockRetStatus block_17(CF &self)
{
	// wait length
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait C[0]
	if (self.wait(self.id(1)[0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=18;
	return CONTINUE;
}

// After requests: cf _l29: vprint(C[0], length);
BlockRetStatus block_18(CF &self)
{
	{
		// EXEC_EXTERN cf _l29: vprint(C[0], length);
		c_vprint(
			// value C[0]
			self.wait(self.id(1)[0]), 
			// int length
			(self.wait(self.id(0))).get_int());

	}

	{
		DF one; one=1;
		self.store(self.id(2)[0][1][1], one);
	}
	// req_unlimited: x[0][1][1]
	{		DF posted=self.wait(self.id(2)[0][1][1]);
	self.post(self.id(2)[0][1][1], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_FOR: for n = 1 .. (size)-(1)
BlockRetStatus block_19(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=20;
	return CONTINUE;
}

// Request : for n = 1 .. (size)-(1)
BlockRetStatus block_20(CF &self)
{
	// wait size
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=21;
	return CONTINUE;
}

// After requests: for n = 1 .. (size)-(1)
BlockRetStatus block_21(CF &self)
{
	for (int _lc_n=1; _lc_n<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_n++) {

// GEN BODY: for n = 1 .. (size)-(1)
	{ // FORK_BI: if x[(n)-(1)][1][1]
		CF *child=self.fork(22);
		child->arg(0)=_lc_n;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	} // for
	return EXIT;
}

// IF: preparations: if x[(n)-(1)][1][1]
BlockRetStatus block_22(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request x[(n)-(1)][1][1]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][1][1], CyclicLocator(0));

	self.NextBlock=23;
	return CONTINUE;
}

// Request : if x[(n)-(1)][1][1]
BlockRetStatus block_23(CF &self)
{
	// wait x[(n)-(1)][1][1]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][1][1]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=24;
	return CONTINUE;
}

// After requests: if x[(n)-(1)][1][1]
BlockRetStatus block_24(CF &self)
{
	if (0!=self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][1][1]).get_int()) {

// GEN BODY: if x[(n)-(1)][1][1]
	{ // FORK_BI: cf _l33: vprint(C[n], length);
		CF *child=self.fork(25);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(0);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf _l33: vprint(C[n], length);
BlockRetStatus block_25(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request C[n]
	self.request(self.id(0)[self.arg(0).get_int()], CyclicLocator(0));
	// request length
	self.request(self.id(1), CyclicLocator(0));

	self.NextBlock=26;
	return CONTINUE;
}

// Request : cf _l33: vprint(C[n], length);
BlockRetStatus block_26(CF &self)
{
	// wait C[n]
	if (self.wait(self.id(0)[self.arg(0).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait length
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=27;
	return CONTINUE;
}

// After requests: cf _l33: vprint(C[n], length);
BlockRetStatus block_27(CF &self)
{
	{
		// EXEC_EXTERN cf _l33: vprint(C[n], length);
		c_vprint(
			// value C[n]
			self.wait(self.id(0)[self.arg(0).get_int()]), 
			// int length
			(self.wait(self.id(1))).get_int());

	}

	{
		DF one; one=1;
		self.store(self.id(2)[self.arg(0).get_int()][1][1], one);
	}
	// req_unlimited: x[n][1][1]
	{		DF posted=self.wait(self.id(2)[self.arg(0).get_int()][1][1]);
	self.post(self.id(2)[self.arg(0).get_int()][1][1], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

extern "C" void init_blocks(BlocksAppender add)
{
	bool ok=true;

	ok = ok && add(block_0)==0;
	ok = ok && add(block_1)==1;
	ok = ok && add(block_2)==2;
	ok = ok && add(block_3)==3;
	ok = ok && add(block_4)==4;
	ok = ok && add(block_5)==5;
	ok = ok && add(block_6)==6;
	ok = ok && add(block_7)==7;
	ok = ok && add(block_8)==8;
	ok = ok && add(block_9)==9;
	ok = ok && add(block_10)==10;
	ok = ok && add(block_11)==11;
	ok = ok && add(block_12)==12;
	ok = ok && add(block_13)==13;
	ok = ok && add(block_14)==14;
	ok = ok && add(block_15)==15;
	ok = ok && add(block_16)==16;
	ok = ok && add(block_17)==17;
	ok = ok && add(block_18)==18;
	ok = ok && add(block_19)==19;
	ok = ok && add(block_20)==20;
	ok = ok && add(block_21)==21;
	ok = ok && add(block_22)==22;
	ok = ok && add(block_23)==23;
	ok = ok && add(block_24)==24;
	ok = ok && add(block_25)==25;
	ok = ok && add(block_26)==26;
	ok = ok && add(block_27)==27;

	assert(ok);
}

