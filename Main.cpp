#include <iostream>
#include <fstream>
#include <limits>

int main()
{
  using namespace std;
  string test, show, search, movie, link, key;
  int method;

  for(;;) {
  	ifstream myfile_in("videos.txt");
    ofstream myfile_out("videos.txt", ios::app);
    cout << "     THIS IS A DATABASE OF ALL THE SHOWS CURRENTLY DOWNLOADED.\n";
  	cout << "               YOUR OPTIONS ARE:                              \n";
  	cout << "                                                              \n";
  	cout << "               1. List current shows.                         \n";
  	cout << "               2. Search for a show.                          \n";
  	cout << "               3. Add a show to the list.                     \n";
  	cout << "               4. Add link and encryption key (if any).       \n";
  	cout << "               5. Add Movie                                   \n";
  	cout << "               6. EXIT THE PROGRAM                            \n";
  	cout << "                                                              \n";
    cin >> method;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(method) {
      case 1:
          cout << " \n";
        cout << string(istreambuf_iterator<char>(myfile_in), {});
        cout << "\n";
      break;
    	case 2:
        cout << "What would you like to find? \n";
        cin >> search;
        cout << "I managed to find these results based on your search \n";
      break;
      case 3:
      	cout << "Enter the name of the show you would like to add. \n";
      	cin >> show;
      	cout << " \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        myfile_out << show << endl;
      break;
      case 4:
        cout << "Enter the name of the show you would like to add. \n";
      	cin >> link;
      	cout << " \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        myfile_out << "Mega-Link: " << link << endl;
        cout << "Enter in your Mega-Link key. \n";
        cin >> key;
          if (key == "none") {
        break;
        }
        myfile_out << "Mega-Key: " << key << endl;
      break;
      case 5:
          cout << "Enter the name of the movie you would like to add. \n";
      	cin >> movie;
      	cout << " \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        myfile_out << "---MOVIE--- " << movie << endl;
        break;
      case 6:
        cout << "Exiting the program!";
        return 0;
        break;
      default:
        cout << "That is not a valid command! \n";
      break;
    }
  }
}
