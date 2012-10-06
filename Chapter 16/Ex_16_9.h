/*
 * Ex_16_9.h
 *
 *  Created on: Oct 6, 2012
 *      Author: MiTKooK
 */

/*
 * Write an aligned malloc & free function that takes number of bytes and aligned byte (which is always power of 2)
 * EXAMPLE
 * align_malloc (1000,128) will return a memory address that is a multiple of 128 and that points to memory of size 1000 bytes.
 * aligned_free() will free memory allocated by align_malloc.
 */

#ifndef EX_16_9_H_
#define EX_16_9_H_

#include<iostream>
#include<cstdlib>
using namespace std;

void * align_malloc(size_t bytes, size_t alignment) {
	void *p1; // original block
	void **p2; // aligned block
	// alignment - 1 is maximum offset, sizeof(void*) stores p1
	if((p1=(void *)malloc(bytes+alignment-1+sizeof(void*)))==NULL)
		return NULL;

	p2 = (void **)(((size_t)p1+alignment-1+sizeof(void*))&~(alignment-1));
	p2[-1] = p1;
	return (void*)p2;
}

void aligned_free(void *p) {
	free(((void**)p)[-1]);
}

void test() {
	void * p = align_malloc(100,128);
	cout<<"add: "<<p<<" %128 = "<<(size_t)p%128<<endl;
	aligned_free(p);
}

#endif /* EX_16_9_H_ */
