#ifndef INCLUDED_VISITED
#define INCLUDED_VISITED

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class Visited {

    public:
        virtual void accept(Visitor *visitor) = 0;
};
#endif
