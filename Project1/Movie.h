//This is the header file for assignment one
//Matthew McKee

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 83;

struct MovieRec {
	int year;
	string name;
	double time;
};

class Movie {
public:
	void showMovie(string /*name*/) const;
	int getNoMovies() const { return noMovies; }
	void addMovie(int /*year*/, string /*name*/, double /*time*/);
	void writeMovies(ostream& output) const;
	Movie(int maxMovies = SIZE /*maxMovies*/, string fileName = "" /*file name for initial movies*/);
	int findMovies(string /*name*/) const;
private:
	int maxMovies;
	int noMovies;
	MovieRec movies[SIZE];
};
