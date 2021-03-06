/*SabreMap.cpp
 *Creates an unordered_map of sabre channels from an input file.
 *Based on work done by S. Balak, K. Macon, and E. Good.
 *
 *Gordon M. Oct. 2019
 */
#include "EventBuilder.h"
#include "SabreMap.h"

int FillSabreMap(string mapfile, unordered_map<int, sabrechan> &smap) {
  ifstream input(mapfile); 
  if(input.is_open()) {
    int chan_i;
    sabrechan chan;
    int idNumber;
    while(input>>chan_i) {
      input>>idNumber;
      if(idNumber ==  1) {
        chan.detID = 0;
      } else if (idNumber == 2) {
        chan.detID = 1;
      } else if (idNumber == 3) {
        chan.detID = 2;
      } else if (idNumber == 4) {
        chan.detID = 3;
      } else if (idNumber == 5) {
        chan.detID = 4;
      }
      input>>chan.side_pos.first>>chan.side_pos.second>>chan.ECutLo>>chan.ECutHi;
      smap[chan_i] = chan;
    }
    input.close();
    return 1;
  } else {
    cerr<<"Unable to find the Sabre channel map file!! Terminating process."<<endl;
    return 0;
  }
}
