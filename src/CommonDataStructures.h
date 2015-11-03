#ifndef INCLUDED_SOLIDDATASTRUCTURE
#define INCLUDED_SOLIDDATASTRUCTURE
#include <vector>

/**
 * Various helper data structures
 */
struct Position {
    double x, y ,z;
};

struct Color {
    double red, green, blue;
};

class CommonHelpers {
    public:
        static std::vector<Position> generateSpherePositions(int rings, int points);
};
#endif
