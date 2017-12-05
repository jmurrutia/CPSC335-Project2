#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

 int main() {
     int n, i, j, count, center;
     int W[100][100];
     bool cond;

     // display the header
     cout << endl << "CPSC 335-03 - Programming Assignement #2" << endl;
     cout << "Topology recognition algorithm" << endl;
     cout << "Enter the number of nodes in the topology" << endl;

     // read the number of nodes
     cin >> n;

     // read the weight matrix
     cout << "Enter the positive weights, 100 for infinity" << endl;
     for (i = 0; i < n; i++)
          for (j = 0; j < n; j++)
               cin >> W[i][j];

     // Start the chronograph to time the execution of the algorithm
     auto start = chrono::high_resolution_clock::now();

     cout << "The topology is" << endl;

     cond = true;
     
     // loop to check whether the topology is a ring
     for (i = 0; i < n; i++) {
          count = 0;
          // YOU NEED TO IMPLEMENT THIS LOOP
          for (j = 0; j < n; j++) {
               if ((W[i][j] > 0) && (W[i][j] < 100))
                    count += 1;
          }
          if (count != 2)
               cond = false;
     }
     
     if (cond) {
          cout << "ring" << endl;
          auto end = chrono::high_resolution_clock::now();
          int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
          double seconds = microseconds / 1E6;
          cout << "elapsed time: " << seconds << "seconds" << endl;
          return EXIT_SUCCESS;
     }

     cond = true;
     center = 0;
     // loop to check whether the topology is a star
     for (i = 0; i < n; i++) {
          count = 0;
          // YOU NEED TO IMPLEMENT THIS LOOP
          for (j = 0; j < n; j++) {
               if ((W[i][j] > 0) && (W[i][j] < 100))
                    count += 1;
          }
          if (count == (n - 1))
               center += 1;
          else if (count != 1)
               cond = false;
     }

     if (cond && center == 1) {
          cout << "star" << endl;          
          auto end = chrono::high_resolution_clock::now();
          int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
          double seconds = microseconds / 1E6;
          cout << "elapsed time: " << seconds << "seconds" << endl;
          return EXIT_SUCCESS;
     }

     cond = true;     
     // loop to check whether the topology is a fully connected mesh
     for (i = 0; i < n; i++) {
          count = 0;
          // YOU NEED TO IMPLEMENT THIS LOOP 
          for (j = 0; j < n; j++) {
               if ((W[i][j] > 0) && (W[i][j] < 100)) {
                    count += 1;
               }
          }
          if (count != (n - 1))
               cond = false;
     }
     if (cond)
          cout << "fully connected mesh" << endl;
     else
          cout << "neither" << endl;

     // End the chronograph to time the loop
     auto end = chrono::high_resolution_clock::now();
     int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
     double seconds = microseconds / 1E6;
     cout << "elapsed time: " << seconds << "seconds" << endl;
     return EXIT_SUCCESS;
}
