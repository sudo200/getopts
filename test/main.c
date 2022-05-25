#include <getopts.h>

static int help_flag;
static int count_flag;
static char *count_arg;
static int version_flag;

static const option_t opts[] = {
    /* long     short   argmode  flag           arg */
    { "help",	'h',	opt_arg,&help_flag,	NULL },
    { "count",	'c',	req_arg,&count_flag,	&count_arg },
    { NULL,	'v',	no_arg,	&version_flag,	NULL },

    // Termination
    { NULL,	'\0',	no_arg,	NULL,		NULL },
};

int main(int argc, char ** argv)
{
    // "optind" is used to indicate, from where on additional args, which aren't flags, are.
    int optind;
    getopts(opts, &optind, argc, argv);

    puts(help_flag ? "Helpflag set" : "Helpflag not set");
    puts(count_flag ? "Countflag set" : "Countflag not set");
    if(count_flag)
    {
        puts(count_arg);
	free(count_arg); // Don't forget to free...
    }

    puts("Additional params:");
    for(int i = optind; i < argc; i++)
        puts(argv[i]);

    return 0;
}

