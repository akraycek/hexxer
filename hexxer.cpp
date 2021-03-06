#include <cstdio>
#include <cstring>
#include <stdexcept>

const unsigned char HEX_TABLE[] = {
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	0,1,2,3,4,5,6,7,8,9, // 0-9
	255,255,255,255,255,255,255,
	10,11,12,13,14,15, // a-f
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	10,11,12,13,14,15, // A-F
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
};

const auto HEX_ALPHABET = "0123456789abcdef";

int main (int argc, char** argv) {
	unsigned char hbuf[2] = {};
	unsigned char bbuf[1] = {};

	// decode?
	if (argc > 1) {
		if (strncmp(argv[1], "-d", 2) != 0 && strncmp(argv[1], "--decode", 8) != 0) {
			throw std::invalid_argument("Unknown argument");
		}

		while (true) {
			const auto read = fread(hbuf, sizeof(hbuf), 1, stdin);

			// EOF?
			if (read == 0) break;

			const auto a = HEX_TABLE[hbuf[0]];
			const auto b = HEX_TABLE[hbuf[1]];
			if (a == 255) throw std::domain_error("Invalid hex character");
			if (b == 255) throw std::domain_error("Invalid hex character");

			bbuf[0] = static_cast<unsigned char>(a * 16 + b);
			fwrite(bbuf, sizeof(bbuf), 1, stdout);
		}

	// encode
	} else {
		while (true) {
			const auto read = fread(bbuf, sizeof(bbuf), 1, stdin);

			// EOF?
			if (read == 0) break;

			const auto a = bbuf[0] / 16;
			const auto b = bbuf[0] % 16;

			hbuf[0] = HEX_ALPHABET[a];
			hbuf[1] = HEX_ALPHABET[b];
			fwrite(hbuf, sizeof(hbuf), 1, stdout);
		}
	}

	return 0;
}
