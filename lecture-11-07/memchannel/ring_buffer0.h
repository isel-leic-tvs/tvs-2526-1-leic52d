#include <stdint.h>
#include <stdbool.h>


#define BUFFER_SIZE 10

typedef struct {
    uint64_t iput, iget; // r/w access indexes (grow monotonically)
    char buffer[BUFFER_SIZE];
} ring_buffer_t;

void rb_init(ring_buffer_t *rb);

bool rb_put(ring_buffer_t *rb, char val);

int rb_getall(ring_buffer_t *rb, char *packet, int packet_max);