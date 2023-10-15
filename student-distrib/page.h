#ifndef PAGE_H
#define PAGE_H

#ifndef ASM

#include "types.h"

#define PAGE_SIZE     1024
#define VIDEO       0xB8000


/* Assembly functions to set up paging */
extern void loadPageDirectory(unsigned int*);
extern void enablePaging();

/* page directory entry structure */
typedef struct __attribute__((packed)) page_directory_entry {
    uint32_t base_addr          : 20;
    uint8_t avail               : 3;
    uint8_t global              : 1;
    uint8_t page_size           : 1;
    uint8_t reserved            : 1;
    uint8_t accessed            : 1;
    uint8_t cache_disabled      : 1;
    uint8_t write_through       : 1;
    uint8_t user_supervisor     : 1;
    uint8_t read_write          : 1;
    uint8_t present             : 1;
} page_directory_entry_t;

/* page table entry structure */
typedef struct __attribute__((packed)) page_table_entry {
    uint32_t base_addr          : 20;
    uint8_t avail               : 3;
    uint8_t global              : 1;
    uint8_t attr_idx            : 1;
    uint8_t dirty               : 1;
    uint8_t accessed            : 1;
    uint8_t cache_disabled      : 1;
    uint8_t write_through       : 1;
    uint8_t user_supervisor     : 1;
    uint8_t read_write          : 1;
    uint8_t present             : 1;
} page_table_entry_t;

/* page directory */
page_directory_entry_t page_directory[PAGE_SIZE] __attribute__ ((aligned(4096)));
page_table_entry_t page_table[PAGE_SIZE] __attribute__ ((aligned(4096)));

#endif /* ASM */

#endif /* PAGE_H */
