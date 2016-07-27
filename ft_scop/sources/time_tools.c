#include <time.h>

double update_delta_time()
{
	static double last_time = 0;
	double current_time;
	double delta_time;

	current_time = clock() / (double)CLOCKS_PER_SEC;
	delta_time = current_time - last_time;
	last_time = current_time;
	return delta_time;
}

float custom_rand()
{
	static unsigned int x;
	unsigned int number;
	const unsigned int range = 11969;
	const unsigned int primaryFactorA = 44273;
	const unsigned int primaryFactorB = 32099;

	number = (primaryFactorA * (clock() + x) + x * primaryFactorB);
	number %= range + 1;
	x++;
	return (float)number / (float)range;
}