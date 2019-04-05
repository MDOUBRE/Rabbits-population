#ifndef MATSUMOTO
#define MATSUMOTO

/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s);


/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length);


/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void);


/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void);


/* generates a random number on [0,1]-real-interval */
double genrand_real1(void);


/* generates a random number on [0,1)-real-interval */
double genrand_real2(void);


/* generates a random number on (0,1)-real-interval */
double genrand_real3(void);


/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void);


#endif
