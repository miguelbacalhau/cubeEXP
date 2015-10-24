#ifndef INCLUDED_VISITOR
#define INCLUDED_VISITOR

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Solid;
class Cube;

class Visitor {

    public:
        void virtual visit(Solid *solid) = 0;
        void virtual visit(Cube *cube) = 0;
};
#endif