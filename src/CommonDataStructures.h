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

struct Velocity {
    double x, y ,z;
};

struct Acceleration {
    double x, y ,z;
};

struct Force {
    double x, y ,z;

    Force& operator+=(const Force& a) {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }
};

struct Volume {
    double maxX, minX;
    double maxY, minY;
    double maxZ, minZ;
};

class CommonHelpers {
    public:
        static std::vector<Position> generateSpherePositions(int rings, int points);
};
#endif
