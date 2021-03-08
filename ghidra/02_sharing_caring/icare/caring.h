#ifndef CARING_H
#define CARING_H

typedef struct
{
	unsigned int count[2];
	unsigned int state[4];
	unsigned char buffer[64];   
} CARING_CTX;


#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))

#define FF(a,b,c,d,x,s,ac) \
{ \
	a += F(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define GG(a,b,c,d,x,s,ac) \
{ \
	a += G(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define HH(a,b,c,d,x,s,ac) \
{ \
	a += H(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}
#define II(a,b,c,d,x,s,ac) \
{ \
	a += I(b,c,d) + x + ac; \
	a = ROTATE_LEFT(a,s); \
	a += b; \
}                                            
void CARINGInit(CARING_CTX *context);
void CARINGUpdate(CARING_CTX *context, unsigned char *input, unsigned int inputlen);
void CARINGFinal(CARING_CTX *context, unsigned char digest[16]);
void CARINGTransform(unsigned int state[4], unsigned char block[64]);
void CARINGEncode(unsigned char *output, unsigned int *input, unsigned int len);
void CARINGDecode(unsigned int *output, unsigned char *input, unsigned int len);

#endif

