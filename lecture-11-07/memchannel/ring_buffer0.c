#include "ring_buffer0.h"
#include <stdio.h>
#include <string.h>


int min(int i1, int i2) {
    return i1 < i2 ? i1 : i2;
}

void rb_init(ring_buffer_t *rb) {
    rb->iput = 0;
    rb->iget = 0;
}

bool rb_put(ring_buffer_t *rb, char val) {
    uint64_t pget = rb->iget;
    uint64_t iput = rb->iput;
   
    if ((iput - pget) == BUFFER_SIZE) {
        return false;
    }

    int pput = iput++ % BUFFER_SIZE;
     
    rb->buffer[pput] = val;
    rb->iput++;

    return true;
}

int rb_getall(ring_buffer_t *rb, char *packet, int packet_max) {
    uint64_t pput = rb->iput;
    uint64_t iget = rb->iget;
    if (iget == pput) { // empty ringbuffer
        return 0;
    }
    
    int size = min(packet_max, pput - iget);
    pput = pput % BUFFER_SIZE;
    int pget = iget % BUFFER_SIZE;
    if (pget + size <= BUFFER_SIZE) {
        // printf("simple copy! (size =%d, pget=%ld,pput=%ld): ", size, pget,pput);
        // show_buffer(rb->buffer, BUFFER_SIZE);
        // printf("\n");
        memcpy(packet, rb->buffer + pget, size);
    }
    else {
        //  printf("splitted copy! (size =%d, pget=%ld,pput=%ld): ", size, pget,pput);
        //  show_buffer(rb->buffer, BUFFER_SIZE);
        //  printf("\n");
         memcpy(packet, rb->buffer + pget, BUFFER_SIZE - pget);
         memcpy(packet + BUFFER_SIZE - pget, rb->buffer, size - (BUFFER_SIZE - pget));
    }
    
    rb->iget += size;
     
    return size;
}