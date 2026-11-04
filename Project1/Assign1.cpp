#include "Movie.h"
#include <fstream>

int main() {
	Movie MovieCollection(10, "Movie.data");

	cout << MovieCollection.getNoMovies() << endl;

	MovieCollection.findMovies("Star Wars");

	MovieCollection.findMovies("Jurassic Park");

	MovieCollection.writeMovies(cout);

	system("pause");
}