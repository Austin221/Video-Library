#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

int main()
{ // You can change it back if you don't like it... but it's clearer IMO
  using namespace std;
  string test, show, search;
  int method;

  for(;;) {
    // These couts will always loop in this for loop and output to console.
  	fstream myfile ("videos.txt", ios::out | ios::app); // y tho (ZH)
  	cout << "     THIS IS A DATABASE OF ALL THE SHOWS CURRENTLY DOWNLOADED.\n";
  	cout << "               YOUR OPTIONS ARE:                              \n";
  	cout << "                                                              \n";
  	cout << "               1. List current shows.                         \n";
  	cout << "               2. Search for a show.                          \n";
  	cout << "               3. Add a show to the list.                     \n";
  	cout << "               4. Add link and encryption key (if any).       \n";
  	cout << "                                                              \n";
		// i know that, but it should wait on user reply, not just continue on its own.
    // hmm
    cin >> method;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // try with this?  not sure
    switch(method) {
      case 1:
      {
        fstream myfile_in("videos.txt", ios::in); // There is 2 myfile variables this can cause an conflict.
        stringstream buffer({istreambuf_iterator<char>(myfile_in), {}});
      }
      break; // This is personal preference, but I treat break like a scope end kind of thing
    	case 2:
        cout << "What would you like to find? \n";
        cin >> search;
        cout << "I managed to find these results based on your search \n";
      break;
      case 3:
      	cout << "Enter the name of the show you would like to add. \n";
        //getline(cin, show); // try this?  didnt work, infinitely looped.
      	cin >> show;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        myfile << show; // i want it to save data, not delete it.
      break;
      case 4:
      //will work on making the links stored in another file later. 
      break;
      default: 
        cout << "That is not a valid command!";
      break;
    }
  }
}
