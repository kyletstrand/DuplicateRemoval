//*******************************************************//
//                                                       //
//                 DuplicateRemoval                      //
//                                                       //
//                   Kyle Strand                         //
//               kyletstrand@gmail.com                   //
//                                                       //
//   Reads a text file and removes duplicate entries     //
//   and creates a new file without the duplicates       //
//   leaving the initial file intact.                    //
//                                                       //  
//*******************************************************//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {

   // Help input
   for (int i=1; i < argc; i++) {
      const string arg = argv[i];
      if (arg == "--help" || arg == "-h") {
         cout << argv[0] << ": Reads input file, deletes duplicate entries, and writes to a new file." << endl;
         cout << "Command structure: " << argv[0] << " <input file> <output file>" << endl;
         exit(0);
      }
   }

   // select input file and name output file from command line argument
   string infile("-"), outfile("-");
   if (argc == 3) {
      infile = argv[1];
      outfile = argv[2];
   } else if (argc != 3) {
      cerr << "Command structure: " << argv[0] << " <input file> <output file>" << endl;
      exit(1);
   }

   const char *in = infile.c_str();
   const char *out = outfile.c_str();

   vector<string> vec;
   vec.clear();
   string line;
   ifstream myfile(in);
   cout << "Reading " << in << " and searching for duplicate entires..." << endl;
   if (myfile.is_open())
   {
      while (myfile.good())
      {	
         getline(myfile,line);

         vec.push_back(line);
      }

      myfile.close();
   } else cout << "Unable to open " << in << endl;

   vec.erase(std::unique(vec.begin(),vec.end()), vec.end());
   sort(vec.begin(),vec.end());
   int lines = vec.size();

   ofstream myfile2;
   myfile2.open(out, ios::app);
   for (int i=0; i<lines; i++) {
      myfile2 << vec.at(i) << "\n";
   }

   myfile2.close();

   return 0;

}
