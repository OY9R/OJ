//https://www.cnblogs.com/Hs-black/p/12334716.html
const int N = 1000000;
ull mi[200];
struct Bit {
	ull bit[15626]; int len = 15626;
#define I inline 
	I void reset() { memset(bit, 0, sizeof(bit)); }
	Bit() { memset(bit, 0, sizeof(bit)); }
	I void set1(int x) { bit[x >> 6] |= mi[x & 63]; }
	I void set0(int x) { bit[x >> 6] &= ~mi[x & 63]; }
	I void flip(int x) { bit[x >> 6] ^= mi[x & 63]; }
	bool operator [](int x) {
		return (bit[x >> 6] >> (x & 63)) & 1;
	}

#define re register
	Bit operator ~ (void) const {
		Bit res;
		for (re int i = 0; i < len; i++) res.bit[i] = ~bit[i];
		return res;
	}

	Bit operator & (const Bit& b) const {
		Bit res;
		for (re int i = 0; i < len; i++) res.bit[i] = bit[i] & b.bit[i];
		return res;
	}

	Bit operator | (const Bit& b) const {
		Bit res;
		for (re int i = 0; i < len; i++) res.bit[i] = bit[i] | b.bit[i];
		return res;
	}

	Bit operator ^ (const Bit& b) const {
		Bit res;
		for (re int i = 0; i < len; i++) res.bit[i] = bit[i] ^ b.bit[i];
		return res;
	}

	void operator &= (const Bit& b) {
		for (re int i = 0; i < len; i++) bit[i] &= b.bit[i];
	}

	void operator |= (const Bit& b) {
		for (re int i = 0; i < len; i++) bit[i] |= b.bit[i];
	}

	void operator ^= (const Bit& b) {
		for (re int i = 0; i < len; i++) bit[i] ^= b.bit[i];
	}

	Bit operator << (const int t) const {
		Bit res; int high = t >> 6, low = t & 63;
		ull last = 0;
		for (register int i = 0; i + high < len; i++) {
			res.bit[i + high] = (last | (bit[i] << low));
			if (low) last = (bit[i] >> (64 - low));
		}
		return res;
	}

	Bit operator >> (const int t) const {
		Bit res; int high = t >> 6, low = t & 63;
		ull last = 0;
		for (register int i = len - 1; i >= high; i--) {
			res.bit[i - high] = last | (bit[i] >> low);
			if (low) last = bit[i] << (64 - low);
		}
		return res;
	}

	void operator <<= (const int t) {
		int high = t >> 6, low = t & 63;
		for (register int i = len - high - 1; ~i; i--) {
			bit[i + high] = (bit[i] << low);
			if (low && i) bit[i + high] |= bit[i - 1] >> (64 - low);
		}
		for (register int i = 0; i < high; i++) bit[i] = 0;
	}

};