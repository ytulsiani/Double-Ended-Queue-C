#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Here we are going to write some functions to support a deque that stores
 * person data (name, age)
 */
struct person {
	char *name;
	int age;
};

/* Example functions given to you. If you want to truly grasp these concepts,
 * try writing your own structs and functions as well!
 */

// Create a new person
struct person *create_person(const char *name, int age) {
	struct person *p = (struct person*) malloc(sizeof(struct person));
	p->name = malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->age = age;
	return p;
}

static int print_count;
static char *last_printed;

// Print a person
void print_person(void *data) {
	struct person *p = (struct person*) data;
	++print_count;
	last_printed = p->name;
	printf("%s, %d\n", p->name, p->age);
}

// Copy a person
void *copy_person(const void *data) {
	struct person *p = (struct person*) data;
	return create_person(p->name, p->age);
}

// Free a person
void free_person(void *data) {
	// This is safe because we should only be passing in person struct pointers
	struct person *p = (struct person*) data;
	// free any malloc'd pointers contained in the person struct (just name)
	free(p->name);
	// Now free the struct itself; this takes care of non-malloc'd data, like age.
	free(p);
}

// Compare people by age
int person_age_comp(const void *data1, const void *data2) {
	struct person *p1 = (struct person*) data1;
	struct person *p2 = (struct person*) data2;
	return p1->age - p2->age;
}

// Compare people by name
int person_name_comp(const void *data1, const void *data2) {
	struct person *p1 = (struct person*) data1;
	struct person *p2 = (struct person*) data2;
	return strcmp(p1->name, p2->name);
}

// Tell if a person is age 50
int is_age_50(const void *data) {
	struct person *p = (struct person*) data;
	return p->age == 50;
}

// Tell if a person is 23 or older
int is_age_23_or_greater(const void *data) {
	struct person *p = (struct person*) data;
	return p->age >= 23;
}

// Tell if person's age is 20
int is_age_20(const void *data) {
	struct person *p = (struct person*) data;
	return p->age == 20;
}

// Tell if a person is age 27
int is_age_27(const void *data) {
	struct person *p = (struct person*) data;
	return p->age == 27;
}

// Tell if a person is age 36
int is_age_36(const void *data) {
	struct person *p = (struct person*) data;
	return p->age == 36;
}

// Tell if a person is age 15
int is_age_15(const void *data) {
	struct person *p = (struct person*) data;
	return p->age == 15;
}

/* This main function does a little testing. Like all good CS Majors, you should
 * test your code here. There is no substitute for testing and you should be
 * sure to test for all edge cases, like calling empty_deque on an empty deque.
 */
int main(void) {

	    printf("\n\n**SYDNEY'S TEST CASES**");

    printf("\nTEST CASE 01: PUSHING BACK\n");
    printf("Creating deque...\n");
    deque* abcd = create_deque();

    struct person* abbie = create_person("Abbie", 20);
    struct person* brian = create_person("Brian", 27);
    struct person* charlie = create_person("Charlie", 36);
    struct person* daniel = create_person("Daniel", 15);

    // end result of adding should look like this:
    // (abbie) -> (brian) -> (charlie) -> (daniel)
    push_back(abcd, abbie);
    assert(abcd->size == 1);
    assert(front(abcd) == abbie);
    assert(back(abcd) == abbie);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    printf("Successfully added Abbie, 20 \n\n");
    // (abbie)
    push_back(abcd, brian);
    assert(abcd->size == 2);
    assert(front(abcd) == abbie);
    assert(back(abcd) == brian);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    printf("Successfully added Brian, 27 \n\n");
    // (abbie) -> (brian)
    push_back(abcd, charlie); // push on back Charlie
    assert(abcd->size == 3);
    assert(front(abcd) == abbie);
    assert(back(abcd) == charlie);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    assert(get(abcd, 2) == charlie);
    printf("Successfully added Charlie, 36 \n\n");
    // (abbie) -> (brian) -> (charlie)
    push_back(abcd, daniel); // push on back Daniel
    assert(abcd->size == 4);
    assert(front(abcd) == abbie);
    assert(back(abcd) == daniel);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    assert(get(abcd, 2) == charlie);
    assert(get(abcd, 3) == daniel);
    printf("Successfully added Daniel, 15 \n\n");
    // (abbie) -> (brian) -> (charlie) -> (daniel)
    printf("Everyone added successfully!\n");

    printf("Emptying deque...\n");
    empty_deque(abcd, free_person);
    assert(abcd != NULL);
    assert(abcd->size == 0);
    assert(front(abcd) == NULL);
    assert(back(abcd) == NULL);


    printf("\n\nTEST CASE 02: PUSHING FRONT\n");

    abbie = create_person("Abbie", 20);
    brian = create_person("Brian", 27);
    charlie = create_person("Charlie", 36);
    daniel = create_person("Daniel", 15);

    push_front(abcd, daniel);
    assert(abcd->size == 1);
    assert(front(abcd) == daniel);
    assert(back(abcd) == daniel);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == daniel);
    printf("Successfully added Daniel, 15 \n\n");
    // (daniel)
    push_front(abcd, charlie);
    assert(abcd->size == 2);
    assert(front(abcd) == charlie);
    assert(back(abcd) == daniel);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == charlie);
    assert(get(abcd, 1) == daniel);
    printf("Successfully added Charlie, 36 \n\n");
    // (charlie) -> (daniel)
    push_front(abcd, brian);
    assert(abcd->size == 3);
    assert(front(abcd) == brian);
    assert(back(abcd) == daniel);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == brian);
    assert(get(abcd, 1) == charlie);
    assert(get(abcd, 2) == daniel);
    printf("Successfully added Brian, 27 \n\n");
    // (brian) -> (charlie) -> (daniel)
    push_front(abcd, abbie);
    assert(abcd->size == 4);
    assert(front(abcd) == abbie);
    assert(back(abcd) == daniel);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    assert(get(abcd, 2) == charlie);
    assert(get(abcd, 3) == daniel);
    printf("Successfully added Abby, 20 \n\n");
    // (abbie) -> (brian) -> (charlie) -> (daniel)
    printf("Everyone added successfully!\n");

    printf("\n\nTEST CASE 3: REMOVE IF\n");
    printf("This should check if a node being removed is:\n");
    printf("  1) a head only\n");
    printf("  2) a tail only\n");
    printf("  3) both a head and tail\n");
    printf("  4) neither a head nor tail\n\n");

    printf("Initial config:\n");
    traverse(abcd, print_person);
    printf("\n");

    remove_if(abcd, is_age_15, free_person); // should remove Daniel
    assert(front(abcd) == abbie);
    assert(back(abcd) == charlie);
    assert(abcd->size == 3);
    assert(front(abcd) == abbie);
    assert(back(abcd) == charlie);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    assert(get(abcd, 2) == charlie);
    printf("Removed person who is tail only successfully.\n\n");
    // (abbie) -> (brian) -> (charlie)
    remove_if(abcd, is_age_20, free_person); // should remove Abbie
    assert(front(abcd) == brian);
    assert(back(abcd) == charlie);
    assert(abcd->size == 2);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == brian);
    assert(get(abcd, 1) == charlie);
    printf("Removed person who is head only successfully.\n\n");
    // (brian) -> (charlie)
    remove_if(abcd, is_age_27, free_person); // removes Brian to test a different edge case
    // (charlie)
    remove_if(abcd, is_age_36, free_person); // should Remove Charlie
    assert(abcd->size == 0);
    assert(front(abcd) == NULL);
    assert(back(abcd) == NULL);
    traverse(abcd, print_person);
    // <empty>
    printf("Removed person who is both a head and tail successfully.\n\n");
    printf("Resetting deque...\n");

    abbie = create_person("Abbie", 20);
    brian = create_person("Brian", 27);
    charlie = create_person("Charlie", 36);
    daniel = create_person("Daniel", 15);

    push_back(abcd, abbie);
    push_back(abcd, brian);
    push_back(abcd, charlie);
    push_back(abcd, daniel);
    // (abbie) -> (brian) -> (charlie) -> (daniel)
    printf("Updated config:\n");
    traverse(abcd, print_person);
    printf("\n");

    remove_if(abcd, is_age_36, free_person);
    assert(abcd->size == 3);
    traverse(abcd, print_person);
    assert(get(abcd, 0) == abbie);
    assert(get(abcd, 1) == brian);
    assert(get(abcd, 2) == daniel);
    //
    printf("Removed person that is neither a head nor tail successfully.\n");
    printf("Success!\n");

    empty_deque(abcd, free_person);
    free(abcd);

    printf("\n\nMake sure to write more test cases as well in test.c!\n"
        "Also test using valgrind. Half credit will be given to\n"
        "functions with memory leaks or memory errors.\n");

	return 0;
}
