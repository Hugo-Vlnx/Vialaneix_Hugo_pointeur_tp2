#include <stdio.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0) 
#define mu_run_test(test) do {char* message = test(); tests_run++; if (message) return message;} while (0)

int tests_run = 0;

int carre(int a) {
	return a * a;
}


static char* test_carre_positif()
{
	int c = carre(3);
	mu_assert("Assert failed : le carre de 3 est 9\n", c == 3 * 3);
}

static char* test_carre_negatif() {
	int c = carre(-5);
	mu_assert("Assert failed : le carre de -5 est 9\n", c == 25);
}

static char* test_carre_nul() {
	int c = carre(0);
	mu_assert("Assert failed : le carré de 0 est 0\n", c == 0);
}

static char* all_test() {
	mu_run_test(test_carre_positif);
	mu_run_test(test_carre_negatif);
	mu_run_test(test_carre_nul);
	return 0;
}

//int main() {
//	char* result = all_test(); // on lance tous les tests 
//	if (result != 0)   // il y a eu une erreur 
//	{
//		printf("%s\n", result);  // on affiche le message d’erreur 
//	}
//	else
//	{
//		printf("All tests passed.\n");
//	}
//	printf("Tests run: %d\n", tests_run); // on affiche le nombre de tests lancés 
//	return result != 0;
//}

const char* categorize_age(int age)
{
	if (age < 0) {
		return "Invalid age";
	}
	else if (age < 13) {
		return "Child";
	}
	else if (age < 20) {
		return "Teenager";
	}
	else if (age < 65) {
		return "Adult";
	}
	else {
		return "Senior";
	}
}

static char* test_categorize_age_invalid() {
	char* age =categorize_age(-1);
	mu_assert("Assert failed : l'age est invalid\n", age == "Invalid age");
}

static char* test_categorize_age_child() {
	char* age = categorize_age(10);
	mu_assert("Assert failed : l'age est child\n", age == "Child");

}

static char* test_categorize_age_teenager() {
	char* age = categorize_age(18);
	mu_assert("Assert failed : l'age est teenager\n", age == "Teenager");
}

static char* test_categorize_age_adult() {
	char* age = categorize_age(25);
	mu_assert("Assert failed : l'age est invalid\n", age == "Adult");
}

static char* test_categorize_age_senior() {
	char* age = categorize_age(70);
	mu_assert("Assert failed : l'age est invalid\n", age == "Senior");
}

static char* all_test_age() {
	mu_run_test(test_categorize_age_invalid);
	mu_run_test(test_categorize_age_child);
	mu_run_test(test_categorize_age_teenager);
	mu_run_test(test_categorize_age_adult);
	mu_run_test(test_categorize_age_senior);
	return 0;
}
int main() {
	char* result = all_test_age(); // on lance tous les tests 
	if (result != 0)   // il y a eu une erreur 
	{
		printf("%s\n", result);  // on affiche le message d’erreur 
	}
	else
	{
		printf("All tests passed.\n");
	}
	printf("Tests run: %d\n", tests_run); // on affiche le nombre de tests lancés 
	return result != 0;
}