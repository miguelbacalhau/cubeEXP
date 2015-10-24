#ifndef INCLUDED_VISITED
#define INCLUDED_VISITED

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class Visited {

    public:
        void virtual accept(Visitor *visitor) = 0;
};
#endif
