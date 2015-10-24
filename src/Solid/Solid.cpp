#include "Solid.h"
#include "../Visitor/Visitor.h"

void Solid::accept(Visitor *visitor) {
    visitor->visit(this);
}
