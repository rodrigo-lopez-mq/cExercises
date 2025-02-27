#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Pointers and Memory Allocation
void pointer_example() {
    int* ptr;
    ptr = (int*)malloc(sizeof(int)); // Allocate memory for an integer

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = 10;
    printf("Value pointed to by ptr: %d\n", *ptr);

    free(ptr); // Release the allocated memory
}

// 2. String Manipulation
void string_example() {
    char str1[] = "Hello";
    char str2[] = " World";
    char combined[20];

    strcpy(combined, str1); // Copy str1 to combined
    strcat(combined, str2); // Concatenate str2 to combined

    printf("Combined string: %s\n", combined);

    if (strcmp(str1, "Hello") == 0) {
        printf("str1 is equal to 'Hello'\n");
    }
}

// 3. Structures and Pointers to Structures
typedef struct {
    char name[50];
    int age;
} Person;

void struct_example() {
    Person person1;
    Person* ptr_person = &person1;

    strcpy(ptr_person->name, "Alice");
    ptr_person->age = 30;

    printf("Person's name: %s, age: %d\n", ptr_person->name, ptr_person->age);
}

// 4. Function Pointers
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void function_pointer_example() {
    int (*operation)(int, int); // Declare a function pointer

    operation = add;
    printf("Addition: %d\n", operation(5, 3));

    operation = subtract;
    printf("Subtraction: %d\n", operation(5, 3));
}

// 5. Bitwise Operations
void bitwise_example() {
    unsigned int a = 5; // 0101
    unsigned int b = 3; // 0011

    printf("a & b: %u\n", a & b); // Bitwise AND
    printf("a | b: %u\n", a | b); // Bitwise OR
    printf("a ^ b: %u\n", a ^ b); // Bitwise XOR
    printf("~a: %u\n", ~a);       // Bitwise NOT
    printf("a << 1: %u\n", a << 1); // Left shift
    printf("a >> 1: %u\n", a >> 1); // Right shift
}

// 6. File I/O
void file_io_example() {
    FILE* file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing\n");
        return;
    }

    fprintf(file, "This is a test.\n");
    fclose(file);

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Could not open file for reading\n");
        return;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("Read from file: %s", buffer);

    fclose(file);
}

//7. Arrays and pointers.
void array_pointer_example(){
    int arr[] = {1,2,3,4,5};
    int *ptr = arr; //arr decays to a pointer to the first element.

    printf("First element : %d\n", *ptr);
    printf("Third element : %d\n", *(ptr + 2));
}

//8. Preprocessor Directives
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void preprocessor_example(){
    int x = 10;
    int y = 20;

    printf("Max of x and y: %d\n", MAX(x,y));
}

// Function to set a specific bit in a number
unsigned int set_bit(unsigned int num, int bit_position) {
    return num | (1 << bit_position);
}

// Function to clear a specific bit in a number
unsigned int clear_bit(unsigned int num, int bit_position) {
    return num & ~(1 << bit_position);
}

// Function to toggle a specific bit.
unsigned int toggle_bit(unsigned int num, int bit_position) {
    return num ^ (1 << bit_position);
}

// Function to check if a specific bit is set
int check_bit(unsigned int num, int bit_position) {
    return (num & (1 << bit_position)) != 0;
}

void bit_manipulation_example() {
    unsigned int num = 10; // Binary: 1010
    int bit_to_manipulate = 1; // Second bit from the right (position 1)

    printf("Original number: %u (Binary: ", num);
    for (int i = sizeof(num) * 8 -1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(")\n");

    unsigned int set_result = set_bit(num, bit_to_manipulate);
    printf("Number after setting bit %d: %u (Binary: ", bit_to_manipulate, set_result);
    for (int i = sizeof(set_result) * 8 -1; i >= 0; i--) {
        printf("%d", (set_result >> i) & 1);
    }
    printf(")\n");

    unsigned int clear_result = clear_bit(set_result, bit_to_manipulate);
    printf("Number after clearing bit %d: %u (Binary: ", bit_to_manipulate, clear_result);
    for (int i = sizeof(clear_result) * 8 -1; i >= 0; i--) {
        printf("%d", (clear_result >> i) & 1);
    }
    printf(")\n");

    unsigned int toggle_result = toggle_bit(num, bit_to_manipulate);
    printf("Number after toggling bit %d: %u (Binary: ", bit_to_manipulate, toggle_result);
    for (int i = sizeof(toggle_result) * 8 -1; i >= 0; i--) {
        printf("%d", (toggle_result >> i) & 1);
    }
    printf(")\n");

    if (check_bit(num, bit_to_manipulate)){
        printf("Bit %d is set in the original number.\n", bit_to_manipulate);
    } else {
        printf("Bit %d is clear in the original number.\n", bit_to_manipulate);
    }
}

int main() {
    pointer_example();
    string_example();
    struct_example();
    function_pointer_example();
    bitwise_example();
    file_io_example();
    array_pointer_example();
    preprocessor_example();
    bit_manipulation_example();

    return 0;
}