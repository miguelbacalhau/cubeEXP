#ifndef INCLUDED_DRAWVISITOR
#define INCLUDED_DRAWVISITOR
#include "Visitor.h"

class DrawVisitor : public Visitor {

    public:
        void visit(CompModel *compModel);
        void visit(Solid *solid);
        void visit(Cube *cube);
};
#endif
