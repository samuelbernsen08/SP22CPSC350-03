#include "Simulation.h"

using namespace std;

int main(int argc, char** argv)
{
    try
    {
        string inFile = argv[1];


        Simulation *sim = new Simulation();
        sim->Simulate(inFile);

    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}