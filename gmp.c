#include <gmp.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char** argv) {
  // Parse arguments
  int cumsum = 0;
  int print_help = 0;
  char* unknown_flag = NULL;
  char* help_l = "--help";
  char* help_s = "-h";
  char* cum_l = "--cum";
  char* cum_s = "-c";

  for (int ii = 1; ii < argc; ii++) {
    char* arg = argv[ii];
    if (0 == strcmp(arg, help_l) || 0 == strcmp(arg, help_s)) print_help = 1;
    else if (0 == strcmp(arg, cum_l) || 0 == strcmp(arg, cum_s)) cumsum = 1;
    else unknown_flag = arg;
  }

  if (unknown_flag != NULL) {
    printf("ERROR: Unknown flag '%s'\n\n", unknown_flag);
    print_help = 1;
  }

  if (print_help) {
    printf("\
sum - add up newline-delimited integers\n\
\n\
Usage: sum [-h | --help] [-c | --cum]\n\
\n\
  --help  Print this help\n\
  --cum   Print cumulative, running total\n\
");
    return 1;
  }

  // Initialize
  mpz_t x;
  mpz_init(x);
  mpz_set_ui(x, 0);

  mpz_t y;
  mpz_init(y);

  // Read successive integers
  char input[1024];
  while (1 == scanf("%1023s\n", input)) {
    mpz_set_str(y, input, 10);
    mpz_add(x, x, y);

    // Print cumulative result, if flag set
    if (cumsum) {
      mpz_out_str(stdout, 10, y);
      printf(" ");
      mpz_out_str(stdout, 10, x);
      printf("\n");
    }
  }

  // Print final total, if not cumulatively printing
  if (!cumsum) {
    mpz_out_str(stdout, 10, x);
    printf("\n");
  }

  // Clean up like a good boy
  mpz_clear(x);
  mpz_clear(y);
}
