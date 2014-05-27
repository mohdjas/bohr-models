//Draws Bohr models of all elements in the periodic table

#include <pngwriter.h>
#include <cmath>
#include <map>

#define PI 3.14159
#define rad(theta) (double)((PI/180.0)*theta)

using namespace std;

int main(int argc, char* argv[]){
	if (argc != 3){
		cerr << "Error   : You have not provided the correct number of arguments." << endl;
		cerr << "Usage   : " << argv[0] << " image-size background-colour" << endl;
		cerr << "          Images smaller than 1250px*1250px will be resized to accomodate the full models of higher elements." << endl;
		cerr << "Example : " << argv[0] << " 1500 0.0" << endl;
		return -1;
	}
	cout << "If specified size is less than 1250px*1250px, it will be resized to fit the full models of higher elements." << endl;
	cin;
	int imgHeight = atoi(argv[1]) < 1250 ? 1250 : atoi(argv[1]);
	int orbitalLimit[] = {2, 8, 18, 32, 50, 72};
    map<string, int> periodicTable = {  {"H", 1}, {"He", 2}, {"Li", 3}, {"Be", 4}, {"B", 5}, {"C", 6}, 
                                        {"N", 7}, {"O", 8}, {"F", 9}, {"Ne", 10}, {"Na", 11}, {"Mg", 12},
                                        {"Al", 13}, {"Si", 14}, {"P", 15}, {"S", 16}, {"Cl", 17}, {"Ar", 18},
                                        {"K", 19}, {"Ca", 20}, {"Sc", 21}, {"Ti", 20}, {"V", 21}, {"Cr", 24},
                                        {"Mn", 25}, {"Fe", 26}, {"Co", 27}, {"Ni", 28}, {"Cu", 29}, {"Zn", 30},
                                        {"Ga", 31}, {"Ge", 32}, {"As", 33}, {"Se", 34}, {"Br", 35}, {"Kr", 36},
                                        {"Rb", 37}, {"Sr", 38}, {"Y", 39}, {"Zr", 40}, {"Nb", 41}, {"Mo", 42},
                                        {"Tc", 43}, {"Ru", 44}, {"Rh", 45}, {"Pd", 46}, {"Ag", 47}, {"Cd", 48},
                                        {"In", 49}, {"Sn", 50}, {"Sb", 51}, {"Te", 52}, {"I", 53}, {"Xe", 54},
                                        {"Cs", 55}, {"Ba", 56}, {"La", 57}, {"Ce", 58}, {"Pr", 59}, {"Nd", 60},
                                        {"Pm", 61}, {"Sm", 62}, {"Eu", 63}, {"Gd", 64}, {"Tb", 65}, {"Dy", 66},
                                        {"Ho", 67}, {"Er", 68}, {"Tm", 69}, {"Yb", 70}, {"Lu", 71}, {"Hf", 72},
                                        {"Ta", 73}, {"W", 74}, {"Re", 75}, {"Os", 76}, {"Ir", 77}, {"Pt", 78},
                                        {"Au", 79}, {"Hg", 80}, {"Tl", 81}, {"Pb", 82}, {"Bi", 83}, {"Po", 84},
                                        {"At", 85}, {"Rn", 86}, {"Fr", 87}, {"Ra", 88}, {"Ac", 89}, {"Th", 90},
                                        {"Pa", 91}, {"U", 92}, {"Np", 93}, {"Pu", 94}, {"Am", 95}, {"Cm", 96},
                                        {"Bk", 97}, {"Cf", 98}, {"Es", 99}, {"Fm", 100}, {"Md", 101}, {"No", 102},
                                        {"Lr", 103}, {"Rf", 104}, {"Db", 105}, {"Sg", 106}, {"Bh", 107}, {"Hs", 108},
                                        {"Mt", 109}, {"Ds", 110}, {"Rg", 111}, {"Cn", 112}, {"Uut", 113}, {"Fl", 114},
                                        {"Uup", 115}, {"Lv", 116}, {"Uus", 117}, {"Uuo", 118}   
                                    };
    

    for (map<string, int>::iterator it = periodicTable.begin(); it != periodicTable.end(); it++){
        int numElectrons = it->second;
        string name = it->first;
        pngwriter img(imgHeight, imgHeight, atof(argv[2]), name.c_str());
		cout << "Now drawing element " << name << "..." << endl;
				
	    int numOrbitals = 	numElectrons <= 2 ? 1 : 
							numElectrons <= 10 ? 2 : 
							numElectrons <= 28 ? 3 : 
							numElectrons <= 60 ? 4 : 
							numElectrons <= 110 ? 5 : 6;
        int numElectronsToDraw = 0;
        int rem = numElectrons;

	    int originX = img.getheight()/2;
	    int originY = img.getwidth()/2;
	    int electronRadius = img.getheight()/150;
	    int orbitalRadius = img.getheight()/8;
		double electronColour = atof(argv[2]) < 0.5 ? 1.0 : 0.0;
	
	    int i = 0, j = 0;
		img.filledcircle(originX, originY, imgHeight/15, 65535, 46774, 0);
	    for (j = 0; j < numOrbitals; j++, orbitalRadius += imgHeight/15){
		    //Drawing orbital path
		    img.circle(originX, originY, orbitalRadius, 55769, 0, 23387);
            numElectronsToDraw = rem > orbitalLimit[j] ? orbitalLimit[j] : rem;
            rem -= numElectronsToDraw;
		    double increment = 360.0/numElectronsToDraw;
		    //Begin drawing electrons
		    for (double angle = 90.0, i = 0; i < numElectronsToDraw; angle += increment, i++){
			    img.filledcircle(	originX + orbitalRadius*cos(rad(angle)), 
						            originY + orbitalRadius*sin(rad(angle)), 
                                    electronRadius, electronColour, electronColour, electronColour);
		    }
		    //End drawing electrons
	    }
	    img.close();
    }
	return 0;
}
