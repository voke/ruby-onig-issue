#include <stdio.h>
#include <string.h>
#include <oniguruma.h>

void Init_myextension()
{

	int r;
	unsigned char *start, *range, *end;
	regex_t* reg;
	OnigErrorInfo einfo;
	OnigRegion *region;

	static UChar* pattern = (UChar* )"foo([a-z]+)";
	static UChar* str     = (UChar* )"foobar";

	printf("oniguruma version: %d.%d.%d\n",
		ONIGURUMA_VERSION_MAJOR, ONIGURUMA_VERSION_MINOR, ONIGURUMA_VERSION_TEENY);

	r = onig_new(&reg, pattern, pattern + strlen((char* )pattern),
	ONIG_OPTION_DEFAULT, ONIG_ENCODING_UTF8, ONIG_SYNTAX_DEFAULT, &einfo);
	if (r != ONIG_NORMAL) {
		char s[ONIG_MAX_ERROR_MESSAGE_LEN];
		onig_error_code_to_str((UChar* )s, r, &einfo);
		fprintf(stderr, "ERROR: %s\n", s);
	}

	region = onig_region_new();

	end   = str + strlen((char* )str);
	start = str;
	range = end;
	r = onig_search(reg, str, end, start, range, region, ONIG_OPTION_NONE);
	if (r >= 0) {
		int i;

		fprintf(stderr, "match at %d\n", r);
		for (i = 0; i < region->num_regs; i++) {
			fprintf(stderr, "%d: (%d-%d)\n", i, region->beg[i], region->end[i]);
		}
	}
	else if (r == ONIG_MISMATCH) {
		fprintf(stderr, "search fail\n");
	}
	else { /* error */
		char s[ONIG_MAX_ERROR_MESSAGE_LEN];
		onig_error_code_to_str((UChar* )s, r);
		fprintf(stderr, "ERROR: %s\n", s);
	}

	onig_region_free(region, 1 /* 1:free self, 0:free contents only */);
	onig_free(reg);
	onig_end();

}
