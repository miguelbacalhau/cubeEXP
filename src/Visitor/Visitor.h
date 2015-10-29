#ifndef INCLUDED_VISITOR
#define INCLUDED_VISITOR

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class CompositeModel;
class Solid;
class Cube;

class Visitor {

    public:
       virtual void visit(Solid *solid) = 0;
       virtual void visit(Cube *cube) = 0;
       virtual void visit(CompositeModel *compModel) = 0;
};
#endif
