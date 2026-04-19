#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * binsearch_two_tests:
 * Classic version with two comparisons inside the loop.
 */
int binsearch_two_tests(int x, const int v[], int n)
{
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

/*
 * binsearch_one_test:
 * One comparison inside the loop body; final equality is tested once after.
 */
int binsearch_one_test(int x, const int v[], int n)
{
	int low = 0;
	int high = n - 1;

	if (n <= 0) {
		return -1;
	}

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (x <= v[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	return (v[low] == x) ? low : -1;
}

static double elapsed_seconds(clock_t start, clock_t end)
{
	return (double)(end - start) / (double)CLOCKS_PER_SEC;
}

int main(void)
{
	enum { ARRAY_SIZE = 1000000, LOOKUPS = 2000000 };
	int *data;
	int i;
	volatile long long sink = 0;
	clock_t t0, t1, t2;
	double two_tests_time;
	double one_test_time;

	data = malloc((size_t)ARRAY_SIZE * sizeof(int));
	if (data == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		return 1;
	}

	for (i = 0; i < ARRAY_SIZE; ++i) {
		data[i] = i * 2;
	}

	t0 = clock();
	for (i = 0; i < LOOKUPS; ++i) {
		int key = i % (ARRAY_SIZE * 2);
		sink += binsearch_two_tests(key, data, ARRAY_SIZE);
	}
	t1 = clock();

	for (i = 0; i < LOOKUPS; ++i) {
		int key = i % (ARRAY_SIZE * 2);
		sink += binsearch_one_test(key, data, ARRAY_SIZE);
	}
	t2 = clock();

	two_tests_time = elapsed_seconds(t0, t1);
	one_test_time = elapsed_seconds(t1, t2);

	printf("Two-tests version: %.6f s\n", two_tests_time);
	printf("One-test version : %.6f s\n", one_test_time);
	if (one_test_time > 0.0) {
		printf("Speedup (two/one): %.3fx\n", two_tests_time / one_test_time);
	}
	printf("Ignore this value (prevents optimization): %lld\n", sink);

	free(data);
	return 0;
}
