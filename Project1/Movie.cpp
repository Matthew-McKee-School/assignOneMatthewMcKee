#include "Movie.h"

Movie::Movie(int newMaxMovies, string fileName) {
	
	int length = 0;

	if (newMaxMovies > SIZE) {
		cout << "newMaxMovies is not in range value has been set to 0" << endl;
		maxMovies = 0;
	}
	else {
		maxMovies = newMaxMovies;
	}

	if (fileName != "") {
		ifstream fin(fileName);
		if (!fin.is_open()) {
			cout << "Error opening file" << endl;
			system("pause");
			exit(-1);
		}

		for (length;length < maxMovies;length++) {
			fin >> movies[length].year;
			if (fin.eof())
				break;
			fin.ignore(80, '\n');
			getline(fin, movies[length].name);
			fin >> movies[length].time;
		}
	}
	noMovies = length;
}

int Movie::findMovies(string searchedName) const {
	int position = noMovies;
	for (int movieCount = 0; movieCount < noMovies; movieCount++) {
		if (searchedName == movies[movieCount].name) {
			position = movieCount;
			break;
		}
	}
	if (position < noMovies) {
		cout << "Movie is in position " << position << endl;
	}

	else {
		cout << "That movie is not in the collection." << endl;
	}
	return position;
}

void Movie::writeMovies(ostream& output) const {
	output << "year   " << "name   " << "time   " << endl;

	for (int movie = 0; movie < noMovies; movie++) {
		output << movies[movie].year << "   ";
		output << movies[movie].name << "   ";
		output << movies[movie].time << endl;
	}

	output << endl << "Number of movies: " << noMovies << endl;
}