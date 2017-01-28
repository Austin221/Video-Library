#include <iostream>
#include <fstream>
#include <limits>

int main()
{
  using namespace std;
  string test, show, search;
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
  	cout << "               5. EXIT THE PROGRAM                            \n";
  	cout << "                                                              \n";
    cin >> method;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(method) {
      case 1:
        cout << string(istreambuf_iterator<char>(myfile_in), {});
      break;
    	case 2:
        cout << "What would you like to find? \n";
        cin >> search;
        cout << "I managed to find these results based on your search \n";
      break;
      case 3:
      	cout << "Enter the name of the show you would like to add. \n";
      	cin >> show;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        myfile_out << show << endl;
      break;
      case 4:
        // FIXME: Make the links stored in another file
      break;
      case 5:
        cout << "Exiting the program!";
        return 0;
        break;
      default:
        cout << "That is not a valid command! \n";
      break;
    }
  }
}
