#include <stdio.h>

#define MAX_PRODUCTS 1000

typedef struct {
    char names[MAX_PRODUCTS][32]; // Store names in a 2D array (Data-Oriented!)
    int price[MAX_PRODUCTS];
    int stock[MAX_PRODUCTS];
} ProductStore;

int create_products(ProductStore *store, int count) {
    for (int i = 0; i < count; i++) {
        printf("\n--- Product %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", store->names[i]);
        printf("Enter price: ");
        scanf("%d", &store->price[i]);
        printf("Enter stock: ");
        scanf("%d", &store->stock[i]);
        
        printf("Product %d created successfully.\n", i);
    }
    return 1;
}

int main() {
    // Allocate the store on the stack (if it's too big, use 'static' or heap)
    static ProductStore myStore; 

    // Create 3 products for testing instead of 1000
    create_products(&myStore, 3);

    return 0;
}
